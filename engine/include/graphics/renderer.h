#pragma once

#include <SDL.h>

namespace engine::graphics {
    
class Renderer
{
public:
    Renderer();
    ~Renderer();

    void Frame(SDL_Renderer*);
};

} // namespace engine::graphics
