
#include "drawobject.h"
#include "line.h"

Line::Line()
{
}

Line::~Line()
{
}

//bool Line::LoadData()
//{
//    glm::vec3 p1 = glm::vec3(0.0);
//    glm::vec3 p2 = glm::vec3(1.0);
//    glm::vec3 v = p2 - p1;
//    double width = 1.0;
//    double length = glm::length(v);
//    double scale = width / length;
//    //int number = 12;
//    glm::vec3 perp = glm::vec3(-v.y * scale, v.x * scale, 0.0);

//    glBindVertexArray(m_VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * 4, m_Data, GL_STATIC_DRAW);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0);
//    glBindVertexArray(0);
//}

//void Line::UnloadData()
//{
//    glDeleteBuffers(1, &m_VBO);
//    glDeleteVertexArrays(1, &m_VAO);
//}

//void Line::Render()
//{
//    glBindVertexArray(m_VAO);
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//    glBindVertexArray(0);
//}
