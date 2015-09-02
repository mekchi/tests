
#include "shader.h"

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

    shader = glCreateShader(shader_type);

    if (shader != 0)
    {
        if (!FileUtility::ReadFile(file, (char**)&source_code))
        {
            MLog::Error(MLog::MLOG_ET_FILE, "Faild to read file");
            glDeleteShader(shader);
            shader = 0;
        }
    }

    if (shader != 0)
    {
        glShaderSource(shader, 1, (const GLchar**)&source_code, 0);
        glCompileShader(shader);

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

        glGetProgramInfoLog(shader_program, size, &size, shaderProgramInfoLog);
        MLog::Error(MLog::MLOG_ET_OPENGL, log);

        free(log);
    }

    return link_status == GL_TRUE;
}

bool DrawArcShader::Init()
{
    bool result = false;
    GLuint vertex_shader = CompileShader(GL_VERTEX_SHADER, "");
    GLuint fragment_shader = CompileShader(GL_FRAGMENT_SHADER, "");

    result = (vertex_shader != 0 && fragment_shader != 0);

    if (result)
    {
        AttachShader(m_shader_program, vertex_shader);
        AttachShader(m_shader_program, fragment_shader);
        result = LinkProgram(m_shader_program);

        if (!result)
        {
            MLog::Error(MLog::MLOG_ET_INIT, "Faild to initialize DrawArcShader");
        }
    }

    return result;
}
