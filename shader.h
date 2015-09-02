#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

class Shader
{
public:
    Shader();
    virtual ~Shader();

    virtual bool Init() = 0;
    virtual void Bind();

protected:
    static GLuint CreateProgram();
    static GLuint CompileShader(GLuint shader_type, const char *file);
    static void AttachShader(GLuint shader_program, GLuint shader);
    static bool LinkProgram(GLuint shader_program);

    GLuint m_shader_program;
};

class DrawArcShader : private Shader
{
public:
    virtual bool Init();
};

#endif // SHADER_H
