
#include "drawobject.h"
#include "line.h"

#include <string.h>



Line::Line()
{
    const double data[] = {-0.25, -0.25, 0.0, 0.0, 0.0,
                          0.25, -0.25, 0.0, 1.0, 0.0};

    m_data = new double[10];
    m_data_size = sizeof(data);
    memcpy(m_data, data, m_data_size);
    m_data_offset = 0;
    m_first_to_draw = 0;
    m_number_to_draw = 2;
}

Line::~Line()
{
    if (m_data)
    {
        delete [] m_data;
    }
}

unsigned int Line::GetDrawType() const
{
    return GL_LINES;
}

const void* Line::GetData() const
{
    return (const void*)m_data;
}
