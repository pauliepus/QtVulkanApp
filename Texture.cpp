#include <iostream>
#include <fstream>
#include <string>
#include <QDebug>

#include "Texture.h"

Texture::Texture()
{
    //Default constructor - Make small dummy texture
    makeDummyTexture();
}

Texture::Texture(const std::string& filename)
{
    textureFilename = filename;
    readBitmap(filename);       //reads the BMP into memory
    //bool success = readBitmap(filename);       //reads the BMP into memory
    //if(success)
        //setTexture();               //set texture up for OpenGL
}

unsigned int Texture::id() const
{
    return mId;
}

bool Texture::readBitmap(const std::string &filename)
{
    OBITMAPFILEHEADER bmFileHeader;
    OBITMAPINFOHEADER bmInfoHeader;
    ODWORD redMask = 0x00FF0000;
    ODWORD greenMask = 0x0000FF00;
    ODWORD blueMask = 0x000000FF;
    ODWORD alphaMask = 0xFF000000;

    std::string fileWithPath = filename;

    std::ifstream file;
    file.open (fileWithPath.c_str(), std::ifstream::in | std::ifstream::binary);
    if (file.is_open())
    {
        // Read the BMP file header manually - since the size of each field can be alligned
        file.read(reinterpret_cast<char*>(&bmFileHeader.bfType), sizeof(bmFileHeader.bfType));
        file.read(reinterpret_cast<char*>(&bmFileHeader.bfSize), sizeof(bmFileHeader.bfSize));
        file.read(reinterpret_cast<char*>(&bmFileHeader.bfReserved1), sizeof(bmFileHeader.bfReserved1));
        file.read(reinterpret_cast<char*>(&bmFileHeader.bfReserved2), sizeof(bmFileHeader.bfReserved2));
        file.read(reinterpret_cast<char*>(&bmFileHeader.bfOffBits), sizeof(bmFileHeader.bfOffBits));

        // Read the BMP info header manually - since the size of each field can be alligned
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biSize), sizeof(bmInfoHeader.biSize));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biWidth), sizeof(bmInfoHeader.biWidth));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biHeight), sizeof(bmInfoHeader.biHeight));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biPlanes), sizeof(bmInfoHeader.biPlanes));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biBitCount), sizeof(bmInfoHeader.biBitCount));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biCompression), sizeof(bmInfoHeader.biCompression));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biSizeImage), sizeof(bmInfoHeader.biSizeImage));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biXPelsPerMeter), sizeof(bmInfoHeader.biXPelsPerMeter));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biYPelsPerMeter), sizeof(bmInfoHeader.biYPelsPerMeter));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biClrUsed), sizeof(bmInfoHeader.biClrUsed));
        file.read(reinterpret_cast<char*>(&bmInfoHeader.biClrImportant), sizeof(bmInfoHeader.biClrImportant));

        if (bmFileHeader.bfType != 19778)
        {
            qDebug("ERROR: File is not a propper BMP file - no BM as first bytes");
            makeDummyTexture();
            return false;
        }

        //Bitmap can be compressed using masking of the channels
        if (bmInfoHeader.biCompression == 3)
        {
            // Read the bit masks for Bitfields compression
            file.read(reinterpret_cast<char*>(&redMask), sizeof(redMask));
            file.read(reinterpret_cast<char*>(&greenMask), sizeof(greenMask));
            file.read(reinterpret_cast<char*>(&blueMask), sizeof(blueMask));
            if (bmInfoHeader.biBitCount == 32)
            {
                file.read(reinterpret_cast<char*>(&alphaMask), sizeof(alphaMask));
            }
        }
        else if (bmInfoHeader.biCompression != 0)
        {
            qDebug("ERROR: Unsupported BMP compression format");
            makeDummyTexture();
            return false;
        }

        mColumns = bmInfoHeader.biWidth;
        mRows = bmInfoHeader.biHeight;
        mBytesPrPixel = bmInfoHeader.biBitCount / 8;
        if(mBytesPrPixel == 4)
            mAlphaUsed = true;

        if(mBytesPrPixel <3)    //we only support 24 or 32 bit images
        {
            qDebug("ERROR: Image not 24 or 32 bit RBG or RBGA");
            makeDummyTexture();
            return false;
        }

        //check if image data is offset - most often not used...
        if(bmFileHeader.bfOffBits !=0)
            file.seekg(bmFileHeader.bfOffBits);
        else if(bmInfoHeader.biSize != 40) //try next trick if file is not a plain old BMP
        {
            int discard = bmInfoHeader.biSize - sizeof(OBITMAPINFOHEADER);
            char* temp = new char[discard];
            file.read( temp, discard);   //discard extra info if header is not old 40 byte header
            qDebug("WARNING: InfoHeader is not 40 bytes, so image might not be correct");
            delete[] temp;
        }

		//If bitmap is without alpha channel, we need to convert it to RGBA
        if (mBytesPrPixel == 3)
        {
            unsigned char* tempBitmap = new unsigned char[mColumns * mRows * mBytesPrPixel];
            mBitmap = new unsigned char[mColumns * mRows * 4]; // Allocate space for RGBA
            for (int i = 0; i < mColumns * mRows; ++i)
            {
                unsigned char r = tempBitmap[i * 3 + 2];
                unsigned char g = tempBitmap[i * 3 + 1];
                unsigned char b = tempBitmap[i * 3 + 0];
                mBitmap[i * 4 + 0] = r;
                mBitmap[i * 4 + 1] = g;
                mBitmap[i * 4 + 2] = b;
                mBitmap[i * 4 + 3] = 255; // Set alpha to fully opaque
            }
            delete[] tempBitmap;
        }
        else
            mBitmap = new unsigned char[mColumns * mRows * mBytesPrPixel];

        file.read((char *) mBitmap, mColumns * mRows * mBytesPrPixel);
        file.close();

        // Process the pixel data using the bit masks
        for (int i = 0; i < mColumns * mRows; ++i)
        {
            unsigned int pixel = reinterpret_cast<unsigned int*>(mBitmap)[i];
            unsigned char r = (pixel & redMask) >> 16;
            unsigned char g = (pixel & greenMask) >> 8;
            unsigned char b = (pixel & blueMask);
            unsigned char a = (mAlphaUsed) ? (pixel & alphaMask) >> 24 : 255;

            mBitmap[i * mBytesPrPixel + 0] = r;
            mBitmap[i * mBytesPrPixel + 1] = g;
            mBitmap[i * mBytesPrPixel + 2] = b;
            if (mAlphaUsed)
                mBitmap[i * mBytesPrPixel + 3] = a;

            // Debug output for the processed pixel values
            //if(i % 40 == 0)
                //qDebug() << "Pixel" << i << ": R=" << r << "G=" << g << "B=" << b << "A=" << a;
        }

        return true;
    }
    else
    {
        qDebug() << "ERROR: Can not read " << fileWithPath;
		//Make dummy texture instead
        makeDummyTexture();
    }
    return false;
}

void Texture::makeDummyTexture()
{
    qDebug("Making dummy texture");
    for (int i = 0; i < 16; i++)
        pixels[i] = 0;
    //Set some colors
    pixels[0] = 255;
    pixels[5] = 255;
    pixels[10] = 255;
    pixels[12] = 255;
    pixels[13] = 255;

    mColumns = 2;
	mRows = 2;
    mBytesPrPixel = 4;
    mAlphaUsed = true;

    // mBytesPrPixel = 3;
    // mAlphaUsed = false;


    mBitmap = new unsigned char[mColumns * mRows * mBytesPrPixel];
    memcpy(mBitmap, pixels, mColumns * mRows * mBytesPrPixel);
	//for (int i = 0; i < mColumns * mRows * mBytesPrPixel; i++)
	//	mBitmap[i] = pixels[i];
}
