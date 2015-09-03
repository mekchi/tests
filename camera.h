#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

struct camera
{
    glm::mat4 modelview;
    glm::mat4 projection;
};

#endif // CAMERA_H
