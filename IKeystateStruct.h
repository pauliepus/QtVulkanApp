#ifndef IKEYSTATESTRUCT_H
#define IKEYSTATESTRUCT_H

#include <qevent.h>

struct KeyState {
    bool W{0};
    bool A{0};
    bool S{0};
    bool D{0};
};

class IState{
public:
    virtual void keyPressEvent(QKeyEvent *event) =0;
    virtual void keyReleaseEvent(QKeyEvent *event) =0;
};

#endif // IKEYSTATESTRUCT_H
