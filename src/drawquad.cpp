
#include "drawquad.h"

#include <GL/glew.h>


DrawQuad::DrawQuad()
{
    m_data = new glm::vec3[4];
    m_data[0] = glm::vec3(-0.5, -0.5, 0.0);
    m_data[1] = glm::vec3(0.5, -0.5, 0.0);
    m_data[2] = glm::vec3(-0.5, 0.5, 0.0);
    m_data[3] = glm::vec3(0.5, 0.5, 0.0);
    m_data_size = sizeof(glm::vec3) * 4;
    m_data_offset = 0;
    m_first_to_draw = 0;
    m_number_to_draw = 4;
}

DrawQuad::~DrawQuad()
{
    if (m_data)
    {
        delete [] m_data;
    }
}

unsigned int DrawQuad::GetDrawType() const
{
    return GL_TRIANGLE_STRIP;
}

const void* DrawQuad::GetData() const
{
	return (const void*)m_data;
}