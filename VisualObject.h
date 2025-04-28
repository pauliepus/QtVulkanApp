#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QVulkanWindow>
#include <vector>
#include "Utilities.h"
#include "vertex.h"

class VisualObject
{
public:
    VisualObject();
    virtual ~VisualObject();

    bool enabled=true;
    void updatePosition() {
        position = mMatrix.column(3).toVector3D(); // Extracts position from transformation matrix
    }

    // legg til en for x for å gi tall
    // for alle objekter elns for å teste

    void move(float x, float y = 0.0f, float z = 0.0f);
    void scale(float s);
    void rotate(float t, float x, float y, float z);


    // I fear this is *very* bad, given that now it's holding
    // the position of *everything*, but maybe not.
    /* Object position container */
    QVector3D position;
    QVector3D mScale;
    QVector3D mRotate;
    void setPosition(float x, float y, float z){ position = QVector3D(x,y,z);}
    QVector3D getPosition() const { return position;}

    //Setters and Getters
    inline std::vector<Vertex> getVertices() { return mVertices; }
    inline VkBuffer& getVBuffer() { return mVertexBuffer.mBuffer; }
    inline VkDeviceMemory& getVBufferMemory() { return mVertexBuffer.mBufferMemory; }
    inline VkDeviceMemory& getIBufferMemory() { return mIndexBuffer.mBufferMemory; }
    inline void setVBuffer(VkBuffer bufferIn) { mVertexBuffer.mBuffer = bufferIn; }
    inline void setVBufferMemory(VkDeviceMemory bufferMemoryIn) { mVertexBuffer.mBufferMemory = bufferMemoryIn; }
    inline VkBuffer& getIBuffer() { return mIndexBuffer.mBuffer; }
    inline void setIBuffer(VkBuffer bufferIn) { mIndexBuffer.mBuffer = bufferIn; }
    inline void setIBufferMemory(VkDeviceMemory bufferMemoryIn) { mIndexBuffer.mBufferMemory = bufferMemoryIn; }
    inline void setName(std::string name) { mName = name; }
    inline std::string getName() const { return mName; }
    inline int getDrawType() const { return drawType; }
    inline QMatrix4x4 getMatrix() const {return mMatrix;}
    inline std::vector<Vertex> getVertices() const { return mVertices; }
    inline std::vector<uint32_t> getIndices() const { return mIndices; }
    QMatrix4x4 mMatrix;
    int drawType{ 0 }; // 0 = fill, 1 = line


protected:
    std::vector<Vertex> mVertices;
    std::vector<uint32_t> mIndices;

    std::string mName;

    BufferHandle mVertexBuffer;
    BufferHandle mIndexBuffer;
    //VkPrimitiveTopology mTopology{ VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST }; //not used

};

#endif // VISUALOBJECT_H

