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
	virtual const void* GetData() const;

private:

    double m_point_size;
	glm::vec2* m_data;

};

#endif // DRAWPOINTBYSHADER_H
