#pragma once

#include "core/update.h"
#include "graphics/renderer.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <SDL.h>

#include <string>

namespace engine::graphics {

class Window {
private:
    bool m_RunGraphicsLoop;

    SDL_Window* m_Window{nullptr};
    SDL_Renderer* m_Renderer{nullptr};

    Renderer m_GameRenderer;

    size_t m_WindowScale;
    std::string m_WindowTitle;

    const engine::Update& m_UpdateController;

    bool setupSDL(bool enableVSync = true);
    void updateGUIWindows(const ImGuiIO&);
public:
    Window(const std::string&, const engine::Update&);
    ~Window();

    bool IsRunning() const { return m_RunGraphicsLoop; }

    void StartGraphicsLoop();
    void StopGraphicsLoop();
};

}; // namespace engine::graphics