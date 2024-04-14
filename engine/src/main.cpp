#include "engine.h"

#include <iostream>

int main(int argc, char **argv)
{
    auto engine = engine::Engine::makeEngine();
    return engine->Run();
}