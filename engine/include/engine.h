#pragma once

#include <memory>
#include <string>

#include "graphics/window.h"

class Engine {
private:
	graphics::Window* m_GameWindow;

	Engine(const std::string&);

public:
	~Engine();

	void Run();

	static std::unique_ptr<Engine> makeEngine();
};