
#include "drawquad.h"

#include <GL/glew.h>


DrawQuad::DrawQuad()
{
	const double data[] = {-0.5, -0.5, 0.0, 0.0, 0.0,
						  0.5, -0.5, 0.0, 1.0, 0.0,
						  -0.5, 0.5, 0.0, 0.0, 1.0,
						  0.5, 0.5, 0.0, 1.0, 1.0};

    m_data = new double[20];
	m_data_size = sizeof(data);
	memcpy_s(m_data, 1, data, m_data_size);
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