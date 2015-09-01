
#include <SDL2/SDL.h>

#include <iostream>
#include <memory>

#include "line.h"

SDL_Window *window = NULL;
SDL_GLContext *context = NULL;

void SimpleTest();

int Start()
{
    int result = 1;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        result = 0;
        std::cerr << "FE : SDL Initialization faild" << std::endl;
        std::cerr << SDL_GetError() << std::endl;
    }

    if (result)
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

         window = SDL_CreateWindow("tests",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    800,
                                    600,
                                    SDL_WINDOW_OPENGL);

        if (window == NULL)
        {
            result = 0;
            std::cerr << "FE : SDL Window creation faild" << std::endl;
            std::cerr << SDL_GetError() << std::endl;
        }
    }

    if (result)
    {
        context = SDL_GL_CreateContext(window);

        if (context == NULL)
        {
            result = 0;
            std::cerr << "FE : SDL GL Context creation faild" << std::endl;
            std::cerr << SDL_GetError() << std::endl;
        }
    }

    if (result)
    {
        if (SDL_GL_SetSwapInterval(1) != 0)
        {
            result = 0;
            std::cerr << SDL_GetError() << std::endl;
        }
    }

    return result;
}

int End()
{
    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    atexit(SDL_Quit);

    return 1;
}

int main(void)
{
    // general personal testing
    SimpleTest();

    if (Start())
    {
        Line *object = Line::Allocate();

//        object->
    }

    return End();
}

class Test
{
public:
    Test() : k (5){}
    int k;
};

void func(const Test *ptr)
{

}

void SimpleTest()
{
    Test *t =  new Test;

    func(t);

    int r = 0;
}
