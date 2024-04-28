#include "engine.h"

#include <iostream>

int main(int argc, char **argv)
{
    auto engine = engine::Engine::GetEngine();
    return engine->Run();
}