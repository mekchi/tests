#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <vector>
#include <memory>

#include "drawobject.h"

class DrawManager
{
public:

    DrawManager();
    ~DrawManager();

    void AddDrawObject(typeDrawObjectAllocateMethod method);
    void Render();

private:

    typedef std::unique_ptr<DrawObject> typeDrawObject;
    typedef std::vector<std::unique_ptr<DrawObject>> typeDrawObjectList;

    typeDrawObjectList m_DrawObjects;
};

#endif // DRAWMANAGER_H
