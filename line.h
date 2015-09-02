#ifndef LINE_H
#define LINE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class DrawObject;

class Line : public DrawObject
{
public:
    Line();
    ~Line();

    static Line* Allocate() { return new Line; }

    virtual GLuint GetDrawType() { return GL_TRIANGLE_STRIP; }
    virtual void Render();

    void SetPoints(const glm::vec3& point1, const glm::vec3& point2);
    void SetWidth(double width);
    void SetSegmentNumber(int number);

private:
    bool LoadData();
    void UnloadData();

    glm::vec3 *m_Data;

    GLuint m_VBO;
    GLuint m_VAO;
};



#endif // LINE_H
