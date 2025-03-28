#ifndef CUBE_H
#define CUBE_H


#include <string>
#include "VisualObject.h"

class Cube : public VisualObject
{

public:
    Cube();
    Cube(std::string name);

    void setPatrolPoints(QVector3D a, QVector3D b) {
        patrolA = a;
        patrolB = b;
        target = patrolB;
    }
    void patrol() {
        QVector3D position = mMatrix.column(3).toVector3D();
        QVector3D direction = (target - position).normalized();

        // Move towards the target
        mMatrix.translate(direction * speed);

        // Check if close enough to switch target
        if ((position - target).length() < 0.1f) {
            movingToB = !movingToB;
            target = movingToB ? patrolB : patrolA;
        }
    }
private:

    QVector3D patrolA;
    QVector3D patrolB;
    QVector3D target;

    float speed = 0.02f;
    bool movingToB = true;
};

#endif // CUBE_H
