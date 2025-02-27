#ifndef VKKEYSTATESTRUCT_H
#define VKKEYSTATESTRUCT_H

#include <qevent.h>

struct KeyState {
    bool W{0};
    bool A{0};
    bool S{0};
    bool D{0};
};

class IState{
public:
    virtual void keyPressEvent(QKeyEvenet *event) =0;
    virtual void keyReleaseEvent(QKeyEvenet *event) =0;
};

#endif // VKKEYSTATESTRUCT_H
