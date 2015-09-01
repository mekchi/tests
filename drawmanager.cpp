
#include "drawmanager.h"

DrawManager::DrawManager()
{

}

DrawManager::~DrawManager()
{

}

void DrawManager::AddDrawObject(typeDrawObjectAllocateMethod method)
{
    if (method != NULL)
    {
        m_DrawObjects.push_back(typeDrawObject(method()));
    }
}

void DrawManager::Render()
{
    for (auto& drawObject : m_DrawObjects)
    {
        drawObject->Render();
    }
}

