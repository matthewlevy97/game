#include "graphics/window.h"

int main(int argc, char **argv)
{
    auto window = graphics::Window("Game Engine");
    window.StartGraphicsLoop();

    return 0;
}