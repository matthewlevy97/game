#include "core/ecs/position.h"
#include "core/ecs/renderable.h"

#include "graphics/renderer.h"

#include "engine.h"

namespace engine::graphics {

Renderer::Renderer()
{}

Renderer::~Renderer()
{}

void Renderer::Frame(SDL_Renderer* renderer)
{
    auto& registry = engine::Engine::GetEngine()->GetECS();
    auto view = registry.view<const struct engine::ecs::position, const struct engine::ecs::renderable>();

    for (auto& entity : view) {
        auto &position = view.get<const struct engine::ecs::position>(entity);
        SDL_Rect fillRect = {position.x, position.y, 80, 80};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);        
        SDL_RenderFillRect(renderer, &fillRect);
    }
}

}; // namespace engine::graphics