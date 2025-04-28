#include "Barycitrus.h"



float Barycitrus::getPositionInTerrain(HeightMap Terrain, float Positionx, float PositionZ)
{
    QVector2D ObjPos = QVector2D(Positionx,PositionZ);

    const auto& indices = Terrain.getIndices();
    const auto& vertices = Terrain.getVertices();


    for(size_t i = 0; i+2 < indices.size(); i+=3)
    {
        int index0 = indices.at(i);
        int index1 = indices.at(i+1);
        int index2 = indices.at(i+2);


        if (index0 >= vertices.size() ||  index1 >= vertices.size() || index2 >= vertices.size())
        {
            continue; // skip this triangle
        }

        Vertex V0 = vertices[index0];
        Vertex V1 = vertices[index1];
        Vertex V2 = vertices[index2];



        QVector2D a(V0.x, V0.z);
        QVector2D b(V1.x, V1.z);
        QVector2D c(V2.x, V2.z);

        // qDebug() << "V0.y:" << V0.y << "V1.y:" << V1.y << "V2.y:" << V2.y;

        QVector3D bary = BarycentricCoordinetes(ObjPos,a,b,c);


        //qDebug() << bary.x() + bary.y() + bary.z() << " should be 1";

        if (bary.x() >= 0.0f && bary.y() >= 0.0f && bary.z() >= 0.0f &&
            bary.x() <= 1.0f && bary.y() <= 1.0f && bary.z() <= 1.0f)
        {
            float height = (bary.x()* V0.y) + (bary.y() * V1.y) + (bary.z() * V2.y);
            return height;
        }

    }

    return -1.0f;
}

QVector3D Barycitrus::BarycentricCoordinetes(QVector2D ObjPos, QVector2D p0, QVector2D p1, QVector2D p2)
{
    QVector2D p10 = p1-p0;
    QVector2D p11 = p2-p0;
    QVector2D p12 = ObjPos-p0;
    float d00 = QVector2D::dotProduct(p10,p10);
    float d01 = QVector2D::dotProduct(p10,p11);
    float d11 = QVector2D::dotProduct(p11,p11);
    float d20 = QVector2D::dotProduct(p12,p10);
    float d21 = QVector2D::dotProduct(p12,p11);


    float denom = 1.0f / (d00 * d11 - d01 * d01);
    float v = (d11 * d20 - d01 * d21) * denom;
    float w = (d00 * d21 - d01 * d20) * denom;
    float u = 1.0f - v - w;

    return QVector3D(u, v, w);
}
