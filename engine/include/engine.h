#pragma once

#include <memory>
#include <string>

#include "core/update.h"
#include "graphics/window.h"

namespace engine {

	class Engine {
	private:
		graphics::Window* m_GameWindow;

		Update m_Updater;

		Engine(const std::string&);

	public:
		~Engine();

		int Run();

		Update* GetUpdater() { return &m_Updater; };

		static std::unique_ptr<Engine> makeEngine();
	};

}; // namespace engine