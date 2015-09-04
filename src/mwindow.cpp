
#include "mwindow.h"

#include <assert.h>
#include <GL/glew.h>

#include "mlog.h"
#include "drawmanager.h"

bool MWindow::m_instantiated = false;

const unsigned int window_width = 800;
const unsigned int window_height = 800;

MWindow::MWindow()
{
    assert(!m_instantiated);
    m_instantiated = true;

    m_window = NULL;
    m_context = NULL;
    m_draw_manager = NULL;

    m_is_running = false;
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
        result = SDL_Init(SDL_INIT_VIDEO) == 0;

        if (!result)
        {
            result = false;
            MLog::Error(MLog::MLOG_ET_INIT, SDL_GetError());
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
                                    window_width,
                                    window_height,
                                    SDL_WINDOW_OPENGL);

        if (m_window == NULL)
        {
            result = false;
            MLog::Error(MLog::MLOG_ET_INIT, SDL_GetError());
        }
    }

    if (result)
    {
        m_context = SDL_GL_CreateContext(m_window);

        if (m_context == NULL)
        {
            result = false;
            MLog::Error(MLog::MLOG_ET_INIT, SDL_GetError());
        }
    }

    if (result)
    {
        glewExperimental = GL_TRUE;
        GLenum error = glewInit();

        result = error == GLEW_OK;
        if (!result)
        {
            MLog::Error(MLog::MLOG_ET_OPENGL, (char*)glewGetErrorString(error));
        }
    }

    if (result)
    {
        if (SDL_GL_SetSwapInterval(1) != 0)
        {
            result = false;
            MLog::Error(MLog::MLOG_ET_INIT, SDL_GetError());
        }
    }

    if (result)
    {
        if (!Initialize() || !InitializeGL())
        {
            MLog::Error(MLog::MLOG_ET_INIT, "Faild to initialize window");
            result = false;
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

bool MWindow::Initialize()
{
    m_draw_manager = new DrawManager;

    return m_draw_manager->Initialize();
}

bool MWindow::InitializeGL()
{
    glViewport(0, 0, window_width, window_height);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    return true;
}

void MWindow::Show()
{
    bool quit = false;
    SDL_Event event;

    while(!quit)
    {
        // handle events
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_draw_manager->Manage();

        SDL_GL_SwapWindow(m_window);
    }
}
