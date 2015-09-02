
#include "mwindow.h"

int main(void)
{
    MWindow* window = new MWindow;

    window->Create();

    window->Display();

    window->Destroy();

    delete window;

    return 0;
}

