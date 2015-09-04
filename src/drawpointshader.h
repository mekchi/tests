#ifndef DRAWPOINTSHADER_H
#define DRAWPOINTSHADER_H

#include <memory>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "shader.h"
#include "camera.h"

class DrawObject;

// shader
class DrawPointShader : public Shader
{
public:
    DrawPointShader();
    virtual ~DrawPointShader();
    virtual bool Initialize();

    void SetModelviewMatrix(const glm::mat4& matrix);
    void SetProjectionMatrix(const glm::mat4& matrix);

protected:

    GLuint m_uniform_projection;
    GLuint m_uniform_modelview;

    GLuint m_attribute_vertex;
    GLuint m_attribute_uv;
};

// Manager draws objects using DrawPointShader
class DrawPointShaderManager : private DrawPointShader
{
public:
    DrawPointShaderManager();
    ~DrawPointShaderManager();

    bool Initialize();
    void SetCamera(camera* camera);
    void Manage();

private:

    //std::unique_ptr<DrawPointShader> m_shader;
    std::vector<DrawObject*> m_draw_object_list;

    camera *m_camera;

    GLuint m_vbo;
    GLuint m_vao;
};

#endif // DRAWPOINTSHADER_H
