#ifndef MWINDOW_H
#define MWINDOW_H

#include <SDL2/SDL.h>

class MWindow
{
public:

    MWindow();
    ~MWindow();

    bool Create();
    void Destroy();

private:

    // there can be only one copy of this object
    static bool m_instantiated;

    SDL_Window *m_window = NULL;
    SDL_GLContext *m_context = NULL;
};

#endif // MWINDOW_H
