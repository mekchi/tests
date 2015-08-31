#ifndef LINE_H
#define LINE_H

#include <glm/glm.hpp>

class Line
{
public:
    Line();
    Line(const glm::vec3& point1,
         const glm::vec3& point2,
         double width,
         int number);
    ~Line();

    void SetPoints(const glm::vec3& point1, const glm::vec3& point2);
    void SetWidth(double width);
    void SetSegmentNumber(int number);

private:
    bool LoadData();

    glm::vec3 *m_Data;
};

#endif // LINE_H
