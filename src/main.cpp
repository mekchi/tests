
#include "fileutility.h"
#include "mwindow.h"

#define WIN

int main(void)
{
#ifdef WIN
	FileUtility::SetResourcePath("../");
#else
    FileUtility::SetResourcePath("/home/mekchi/Documents/me/tests/");
#endif

    MWindow* window = new MWindow;

    if (window->Create())
    {
        window->Show();
    }

    window->Destroy();

    delete window;

    return 0;
}

