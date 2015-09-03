#ifndef DRAWQUAD_H
#define DRAWQUAD_H

#include "drawobject.h"

class DrawQuad : public DrawObject
{
public:
    DrawQuad();
    virtual ~DrawQuad();

    unsigned int GetDrawType() const;

};

#endif // DRAWQUAD_H
