#ifndef DRAWQUAD_H
#define DRAWQUAD_H

#include "drawobject.h"
#include <glm/glm.hpp>

class DrawQuad : public DrawObject
{
public:
    DrawQuad();
    virtual ~DrawQuad();

    virtual unsigned int GetDrawType() const;
	virtual const void* GetData() const;

private:
	glm::vec3* m_data;
};

#endif // DRAWQUAD_H
