
#include "fileutility.h"
#include "mwindow.h"

int main(void)
{
    FileUtility::SetResourcePath("/home/mekchi/Documents/me/tests/");

    MWindow* window = new MWindow;

    if (window->Create())
    {
        window->Show();
    }

    window->Destroy();

    delete window;

    return 0;
}

