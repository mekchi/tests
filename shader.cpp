
#include "shader.h"

#include <stdlib.h>

#include "mlog.h"
#include "fileutility.h"

Shader::Shader()
{
    m_shader_program = 0;
}

Shader::~Shader()
{
    if (m_shader_program)
    {
        glDeleteShader(m_shader_program);
    }
}

void Shader::Bind()
{
    glUseProgram(m_shader_program);
}

GLuint Shader::CreateProgram()
{
    return glCreateProgram();
}

GLuint Shader::CompileShader(GLuint shader_type, const char *file)
{
    int compile_status = GL_FALSE;
    GLuint shader = 0;
    GLchar* source_code = NULL;
    int source_code_size = 0;

    shader = glCreateShader(shader_type);

    if (shader != 0)
    {
        if (!FileUtility::ReadFile(file,
                                   (char**)&source_code,
                                   &source_code_size))
        {
            MLog::Error(MLog::MLOG_ET_FILE, "Faild to read %s", file);
            glDeleteShader(shader);
            shader = 0;
        }

        if (source_code_size == 0)
        {
            MLog::Error(MLog::MLOG_ET_FILE, "File %s is empty", file);
            glDeleteShader(shader);
            shader = 0;

        }
    }

    if (shader != 0)
    {
        glShaderSource(shader, 1, (const GLchar**)&source_code, NULL);
        glCompileShader(shader);

        free(source_code);

        // check status of compilation
        // if not output log
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
        if(compile_status == GL_FALSE)
        {
            int size = 0;
            char* log = NULL;

            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);

            log = (char*)malloc(size);

            glGetShaderInfoLog(shader, size, &size, log);

            //MLog::Error(MLog::MLOG_ET_OPENGL, "Shader compile error in %s:", file);
            MLog::Error(MLog::MLOG_ET_OPENGL, log);

            free(log);
            glDeleteShader(shader);
            shader = 0;
        }
    }

    return shader;
}

void Shader::AttachShader(GLuint shader_program, GLuint shader)
{
    glAttachShader(shader_program, shader);
}

bool Shader::LinkProgram(GLuint shader_program)
{
    int link_status = GL_FALSE;

    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, (int *)&link_status);
    if(link_status == GL_FALSE)
    {
        int size = 0;
        char* log = NULL;

        glGetProgramiv(shader_program, GL_INFO_LOG_LENGTH, &size);

        log = (char*)malloc(size);

        glGetProgramInfoLog(shader_program, size, &size, log);
        MLog::Error(MLog::MLOG_ET_OPENGL, log);

        free(log);
    }

    return link_status == GL_TRUE;
}
