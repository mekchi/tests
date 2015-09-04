#ifndef MWINDOW_H
#define MWINDOW_H

#include <SDL2/SDL.h>

#undef main

class DrawManager;

class MWindow
{
public:

    MWindow();
    ~MWindow();

    bool Create();
    void Destroy();
    void Show();


private:

    bool Initialize();
    bool InitializeGL();

    // there can be only one copy of this object
    static bool m_instantiated;

    SDL_Window *m_window;
    SDL_GLContext m_context;

    DrawManager *m_draw_manager;

    bool m_is_running;

};

#endif // MWINDOW_H
