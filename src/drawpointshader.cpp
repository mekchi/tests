
#include "drawpointshader.h"

#include <glm/gtc/type_ptr.hpp>

#include "mlog.h"
#include "fileutility.h"
#include "camera.h"

#include "drawquad.h"
#include "line.h"
#include "drawpointbyshader.h"


DrawPointShader::DrawPointShader()
{

}

DrawPointShader::~DrawPointShader()
{

}

bool DrawPointShader::Initialize()
{
    const char* modelview_name = "modelview";
    const char* projection_name = "projection";
    const char* vertex_name = "vertex";
    const char* uv_name = "uv";

    bool result = false;
    GLuint vertex_shader;
    GLuint fragment_shader;

    m_shader_program = CreateProgram();

    result = m_shader_program != 0;

    if (result)
    {
        vertex_shader = CompileShader(GL_VERTEX_SHADER, FileUtility::GetFullResourcePath("shaders/draw_point.vert").c_str());
        fragment_shader = CompileShader(GL_FRAGMENT_SHADER, FileUtility::GetFullResourcePath("shaders/draw_point.frag").c_str());

        result = (vertex_shader != 0 && fragment_shader != 0);
    }

    if (result)
    {
        AttachShader(m_shader_program, vertex_shader);
        AttachShader(m_shader_program, fragment_shader);

        result = LinkProgram(m_shader_program);

        if (result)
        {
            // locate uniforms
            m_uniform_modelview = glGetUniformLocation(m_shader_program, modelview_name);
            m_uniform_projection = glGetUniformLocation(m_shader_program, projection_name);

            m_attribute_vertex = glGetAttribLocation(m_shader_program, vertex_name);
            m_attribute_uv = glGetAttribLocation(m_shader_program, uv_name);
        }
        else
        {
            MLog::Error(MLog::MLOG_ET_INIT, "Faild to initialize DrawPointShader");
        }
    }

    return result;
}

void DrawPointShader::SetModelviewMatrix(const glm::mat4 &matrix)
{
    glUniformMatrix4fv(m_uniform_modelview, 1, GL_FALSE, glm::value_ptr(matrix));
}

void DrawPointShader::SetProjectionMatrix(const glm::mat4 &matrix)
{
    glUniformMatrix4fv(m_uniform_projection, 1, GL_FALSE, glm::value_ptr(matrix));
}

DrawPointShaderManager::DrawPointShaderManager()
{
//    m_shader.reset(new DrawPointShader);
    m_vao = 0;
    m_vbo = 0;
}

DrawPointShaderManager::~DrawPointShaderManager()
{
    // for now
    // allocate objects in different place and pass list of them to this manager
    for (DrawObject* object : m_draw_object_list)
    {
        delete object;
    }
    m_draw_object_list.clear();
}

bool DrawPointShaderManager::Initialize()
{
//    bool result = m_shader->Initialize();
    bool result = DrawPointShader::Initialize();

    if (result)
    {
        unsigned int size = 0;
        unsigned int first = 0;

        //m_draw_object_list.push_back(new DrawPointByShader);
        m_draw_object_list.push_back(new DrawQuad);
//        m_draw_object_list.push_back(new Line);

        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);
        glBindVertexArray(m_vao);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        for (const DrawObject* object : m_draw_object_list)
        {
            size += object->GetDataSize();
        }

        glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

        size = 0;

        for (DrawObject* object : m_draw_object_list)
        {
            glBufferSubData(GL_ARRAY_BUFFER, size, object->GetDataSize(), (GLvoid*)object->GetData());
            object->SetDataOffset(size);
            object->SetFirstToDraw(first);
            first += object->GetNumberToDraw();
            size += object->GetDataSize();
        }

        glEnableVertexAttribArray(m_attribute_vertex);
        glVertexAttribPointer(m_attribute_vertex, 3, GL_DOUBLE, GL_FALSE, sizeof(double) * 5, 0);
        glEnableVertexAttribArray(m_attribute_uv);
        glVertexAttribPointer(m_attribute_uv, 2, GL_DOUBLE, GL_FALSE, sizeof(double) * 5, (const GLvoid*)(sizeof(double) * 3));

    }

    return result;
}

void DrawPointShaderManager::SetCamera(camera *camera)
{
    m_camera = camera;
}

void DrawPointShaderManager::Manage()
{
    DrawPointShader::Bind();
    DrawPointShader::SetModelviewMatrix(m_camera->modelview);
    DrawPointShader::SetProjectionMatrix(m_camera->projection);

    glBindVertexArray(m_vao);
    for (const DrawObject* object : m_draw_object_list)
    {
        glDrawArrays(object->GetDrawType(), object->GetFirstToDraw(), object->GetNumberToDraw());
    }
    glBindVertexArray(0);
}
