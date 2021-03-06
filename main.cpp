#include "Core.h"

int main(int argc, char *argv[])
{
    const char *fileName = "assets/Sample.mkv";
    const char *fileName2 = "../assets/Sample.mkv";

    bool res;

    Core *core = new Core();
    res = core->openMediaFile(fileName);
    if (!res)
        res = core->openMediaFile(fileName2);

    res = core->preprocessStream();
    if (!res)
        return 1;

    res = core->initSDL();
    if (!res)
        return 1;

    res = core->playMedia();
    if (!res)
        return 1;

    core->cleanUp();

    delete core;
    return 0;
}