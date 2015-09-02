
#include "mwindow.h"

#include <assert.h>

bool MWindow::m_instantiated = false;

MWindow::MWindow()
{
    assert(!m_instantiated);
    m_instantiated = true;

    m_window = NULL;
    m_context = NULL;
}

MWindow::~MWindow()
{
    m_instantiated = false;

    if (m_window != NULL && m_context != NULL)
    {
        Destroy();
    }
}

bool MWindow::Create()
{
    bool result = false;

    // Create can be called only once
    assert(m_window == NULL && m_context == NULL);

    if (m_window == NULL && m_context == NULL)
    {
        resutl = SDL_Init(SDL_INIT_VIDEO) == 0;

        if (!result)
        {
            result = false;
            std::cerr << "FE : SDL Initialization faild" << std::endl;
            std::cerr << SDL_GetError() << std::endl;
        }
    }

    if (result)
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

         m_window = SDL_CreateWindow("tests",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    800,
                                    600,
                                    SDL_WINDOW_OPENGL);

        if (m_window == NULL)
        {
            result = false;
            std::cerr << "FE : SDL Window creation faild" << std::endl;
            std::cerr << SDL_GetError() << std::endl;
        }
    }

    if (result)
    {
        m_context = SDL_GL_CreateContext(m_window);

        if (m_context == NULL)
        {
            result = false;
            std::cerr << "FE : SDL GL Context creation faild" << std::endl;
            std::cerr << SDL_GetError() << std::endl;
        }
    }

    if (result)
    {
        if (SDL_GL_SetSwapInterval(1) != 0)
        {
            result = false;
            std::cerr << SDL_GetError() << std::endl;
        }
    }

    return result;
}

void MWindow::Destroy()
{
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
    m_window = NULL;
    m_context = NULL;

    atexit(SDL_Quit);
}
