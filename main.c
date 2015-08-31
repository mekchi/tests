
#include <SDL2/SDL.h>


int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("tests",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800,
                                          600,
                                          SDL_WINDOW_OPENGL);

    if (window == NULL)
    {
        return 1;
    }

    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    atexit(SDL_Quit);

    return 0;
}

