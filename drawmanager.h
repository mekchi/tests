#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <memory>

#include "camera.h"

class DrawPointShaderManager;

class DrawManager
{
public:

    DrawManager();
    ~DrawManager();

    bool Initialize();
    void Manage();


private:

    camera m_ortho_camera;
    std::unique_ptr<DrawPointShaderManager> m_test_manager;
};

#endif // DRAWMANAGER_H
