
#include "drawpointbyshader.h"

#include <GL/glew.h>

DrawPointByShader::DrawPointByShader()
{
    m_data = new glm::vec2(0.0);
    m_data_size = sizeof(glm::vec2);
    m_point_size = 1.0;
    m_first_to_draw = 0;
    m_number_to_draw = 1;
    m_data_offset = 0;
}

DrawPointByShader::~DrawPointByShader()
{
    if (m_data)
    {
        delete m_data;
    }
}

void DrawPointByShader::SetPointSize(double size)
{
    m_point_size = size;
}

double DrawPointByShader::GetPointSize() const
{
    return m_point_size;
}

unsigned int DrawPointByShader::GetDrawType() const
{
    return GL_POINTS;
}

const void* DrawPointByShader::GetData() const
{
	return (const void*)m_data;
}