#include "engine.h"

int main(int argc, char **argv)
{
    auto engine = Engine::makeEngine();
    engine->Run();

    return 0;
}