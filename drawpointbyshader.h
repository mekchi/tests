#ifndef DRAWPOINTBYSHADER_H
#define DRAWPOINTBYSHADER_H

#include <glm/glm.hpp>

#include "drawobject.h"

class DrawPointByShader : public DrawObject
{

public:
    DrawPointByShader();
    ~DrawPointByShader();

    void SetPointSize(double size);
    double GetPointSize() const;

    virtual unsigned int GetDrawType() const;

private:

    double m_point_size;

};

#endif // DRAWPOINTBYSHADER_H
