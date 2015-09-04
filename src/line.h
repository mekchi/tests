#ifndef LINE_H
#define LINE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class DrawObject;

class Line : public DrawObject
{
public:
    Line();
    virtual ~Line();

    virtual unsigned int GetDrawType() const;
    virtual const void* GetData() const;

private:

    double *m_data;

};

#endif // LINE_H
