#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

class DrawObject;

typedef DrawObject* (*typeDrawObjectAllocateMethod)();

class DrawObject
{

public:

    virtual unsigned int GetDrawType() = 0;
    virtual void Render() = 0;
};

#endif // DRAWOBJECT_H
