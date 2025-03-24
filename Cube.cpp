#include "Cube.h"
#include <fstream>
#include <QDebug>


Cube::Cube(): VisualObject()
{
    //red front-low-left, point at origo
    Vertex v1{0.0f,   0.0f,  0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
    //green front-low-right green, point x+1
    Vertex v2{1.0f,   0.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
    //blue front-top-right, point y+1
    Vertex v3{0.0f,   1.0f,  0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
    //r+g front-    x+1,y+1,0,
    Vertex v4{1.0f,   1.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
    //blue bak v3 -low-right x+1,z-1
    Vertex v5{0.0f,  1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
    //red bak-v1
    Vertex v6{0.0f,  0.0f, -1.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
    //green bak-v2
    Vertex v7{1.0f,  0.0f, -1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
    //r+g bak v4
    Vertex v8{1.0f,  1.0f, -1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};



    //Pushing 1st triangle,
    mVertices.push_back(v1); //front-low-left
    mVertices.push_back(v2); //front-low-right
    mVertices.push_back(v3); //front-top-right
    //then the 2nd.
    mVertices.push_back(v3); //front-top-right
    mVertices.push_back(v2); //front-low-right
    mVertices.push_back(v4); //front-top-left

    // square behind first
    mVertices.push_back(v6); //bak v1
    mVertices.push_back(v7);
    mVertices.push_back(v5);

    mVertices.push_back(v5); //bak 3
    mVertices.push_back(v7); //bak 2
    mVertices.push_back(v8); //bak 4


    // square on top

    mVertices.push_back(v5);
    mVertices.push_back(v3);
    mVertices.push_back(v8);

    mVertices.push_back(v4);
    mVertices.push_back(v8);
    mVertices.push_back(v3);


    // square on something

    mVertices.push_back(v5); // blå bak
    mVertices.push_back(v1); // rød
    mVertices.push_back(v6); // blå bak

    mVertices.push_back(v3);
    mVertices.push_back(v5);
    mVertices.push_back(v1);


    //right side

    mVertices.push_back(v8);
    mVertices.push_back(v4);
    mVertices.push_back(v2);

    mVertices.push_back(v8);
    mVertices.push_back(v7);
    mVertices.push_back(v2);

    // underside
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v6);

    mVertices.push_back(v7);
    mVertices.push_back(v2);
    mVertices.push_back(v6);


    //Temporary scale and positioning
    //mMatrix.scale(0.5f);
    //mMatrix.translate(0.5f, 0.1f, 0.1f);
};
Cube::Cube(std::string name) {
    Vertex v1,v2,v3,v4,v5,v6,v7,v8;
    if(name=="Enemy"){
        //red front-low-left, point at origo
        Vertex t1{0.0f,   0.0f,  0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v1=t1;
        //green front-low-right green, point x+1
        Vertex t2{1.0f,   0.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v2=t2;
        //blue front-top-right, point y+1
        Vertex t3{0.0f,   1.0f,  0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v3=t3;
        //r+g front-    x+1,y+1,0,
        Vertex t4{1.0f,   1.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v4=t4;
        //blue bak v3 -low-right x+1,z-1
        Vertex t5{0.0f,  1.0f, -1.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v5=t5;
        //red bak-v1
        Vertex t6{0.0f,  0.0f, -1.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v6=t6;
        //green bak-v2
        Vertex t7{1.0f,  0.0f, -1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v7=t7;
        //r+g bak v4
        Vertex t8{1.0f,  1.0f, -1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v8=t8;
    };

    if(name=="Pickup"){
        //red front-low-left, point at origo
        Vertex t1{0.0f,   0.0f,  0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v1=t1;
        //green front-low-right green, point x+1
        Vertex t2{1.0f,   0.0f,  0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v2=t2;
        //blue front-top-right, point y+1
        Vertex t3{0.0f,   1.0f,  0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v3=t3;
        //r+g front-    x+1,y+1,0,
        Vertex t4{1.0f,   1.0f,  0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v4=t4;
        //blue bak v3 -low-right x+1,z-1
        Vertex t5{0.0f,  1.0f, -1.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v5=t5;
        //red bak-v1
        Vertex t6{0.0f,  0.0f, -1.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v6=t6;
        //green bak-v2
        Vertex t7{1.0f,  0.0f, -1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v7=t7;
        //r+g bak v4
        Vertex t8{1.0f,  1.0f, -1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v8=t8;
    };

    if(name=="Player"){
        //red front-low-left, point at origo
        Vertex t1{0.0f,   0.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v1=t1;
        //green front-low-right green, point x+1
        Vertex t2{1.0f,   0.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v2=t2;
        //blue front-top-right, point y+1
        Vertex t3{0.0f,   1.0f,  0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f};
        v3=t3;
        //r+g front-    x+1,y+1,0,
        Vertex t4{1.0f,   1.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v4=t4;
        //blue bak v3 -low-right x+1,z-1
        Vertex t5{0.0f,  1.0f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f};
        v5=t5;
        //red bak-v1
        Vertex t6{0.0f,  0.0f, -1.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
        v6=t6;
        //green bak-v2
        Vertex t7{1.0f,  0.0f, -1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v7=t7;
        //r+g bak v4
        Vertex t8{1.0f,  1.0f, -1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
        v8=t8;
    };
    if(name=="Win"){
        //red front-low-left, point at origo
        Vertex v1{0.0f,   0.0f,  0.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
        //green front-low-right green, point x+1
        Vertex v2{1.0f,   0.0f,  0.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
        //blue front-top-right, point y+1
        Vertex v3{0.0f,   1.0f,  0.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
        //r+g front-    x+1,y+1,0,
        Vertex v4{1.0f,   1.0f,  0.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
        //blue bak v3 -low-right x+1,z-1
        Vertex v5{0.0f,  1.0f, -1.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
        //red bak-v1
        Vertex v6{0.0f,  0.0f, -1.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
        //green bak-v2
        Vertex v7{1.0f,  0.0f, -1.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
        //r+g bak v4
        Vertex v8{1.0f,  1.0f, -1.0f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f};
    };


    //Pushing 1st triangle,
    mVertices.push_back(v1); //front-low-left
    mVertices.push_back(v2); //front-low-right
    mVertices.push_back(v3); //front-top-right
    //then the 2nd.
    mVertices.push_back(v3); //front-top-right
    mVertices.push_back(v2); //front-low-right
    mVertices.push_back(v4); //front-top-left

    // square behind first
    mVertices.push_back(v6); //bak v1
    mVertices.push_back(v7);
    mVertices.push_back(v5);

    mVertices.push_back(v5); //bak 3
    mVertices.push_back(v7); //bak 2
    mVertices.push_back(v8); //bak 4


    // square on top

    mVertices.push_back(v5);
    mVertices.push_back(v3);
    mVertices.push_back(v8);

    mVertices.push_back(v4);
    mVertices.push_back(v8);
    mVertices.push_back(v3);


    // square on something

    mVertices.push_back(v5); // blå bak
    mVertices.push_back(v1); // rød
    mVertices.push_back(v6); // blå bak

    mVertices.push_back(v3);
    mVertices.push_back(v5);
    mVertices.push_back(v1);


    //right side

    mVertices.push_back(v8);
    mVertices.push_back(v4);
    mVertices.push_back(v2);

    mVertices.push_back(v8);
    mVertices.push_back(v7);
    mVertices.push_back(v2);

    // underside
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v6);

    mVertices.push_back(v7);
    mVertices.push_back(v2);
    mVertices.push_back(v6);


    //Temporary scale and positioning
    //mMatrix.scale(0.5f);
    //mMatrix.translate(0.5f, 0.1f, 0.1f);
}
