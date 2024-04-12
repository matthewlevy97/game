#include "graphics/renderer.h"

namespace graphics {

Renderer::Renderer()
{}

Renderer::~Renderer()
{}

void Renderer::Frame(SDL_Renderer* renderer)
{
    SDL_Rect fillRect = {80, 80, 80, 80};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF );        
    SDL_RenderFillRect(renderer, &fillRect );
}

}; // namespace graphics