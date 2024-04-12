#pragma once

#include <SDL.h>

namespace graphics {
    
class Renderer
{
public:
    Renderer();
    ~Renderer();

    void Frame(SDL_Renderer*);
};

} // namespace graphics
