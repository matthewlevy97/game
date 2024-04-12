#include "graphics/window.h"

int main()
{
    auto window = graphics::Window("Game Engine");
    window.StartGraphicsLoop();

    return 0;
}