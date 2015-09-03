
#include "drawmanager.h"

#include "drawpointshader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

DrawManager::DrawManager()
{
    m_test_manager.reset(new DrawPointShaderManager);

}

DrawManager::~DrawManager()
{

}

bool DrawManager::Initialize()
{
    m_ortho_camera.modelview = glm::mat4();
    m_ortho_camera.projection = glm::ortho(-0.5f, 0.5f, -0.5f, 0.5f, -5.0f, 5.0f);

    m_test_manager->SetCamera(&m_ortho_camera);

    return m_test_manager->Initialize();
}

void DrawManager::Manage()
{
    m_test_manager->Manage();
}

