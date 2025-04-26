#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QVulkanWindow>
#include <vector>
#include "vertex.h"

class VisualObject
{
public:
    std::vector<Vertex> mVertices;
    inline std::vector<Vertex> getVertices() { return mVertices; }
    VisualObject();
    virtual ~VisualObject();

    void updatePosition() {
        position = mMatrix.column(3).toVector3D(); // Extracts position from transformation matrix
    }

    // legg til en for x for å gi tall
    // for alle objekter elns for å teste

    void setName(std::string name);
    std::string getName() const;
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


    VkDeviceMemory mBufferMemory{ VK_NULL_HANDLE };
    VkBuffer mBuffer{ VK_NULL_HANDLE };
    VkPrimitiveTopology mTopology { VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST };

    QMatrix4x4 mMatrix;

    bool enabled=true;

    int drawType{ 0 }; // 0 = fill, 1 = line
    inline std::vector<uint32_t> getIndices() const { return mIndices; }

protected:
    std::string mName;
    std::vector<uint32_t> mIndices;
};

#endif // VISUALOBJECT_H

