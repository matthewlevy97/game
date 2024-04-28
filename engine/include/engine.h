#pragma once

#include <memory>
#include <string>

#include <entt/entt.hpp>

#include "core/update.h"
#include "graphics/window.h"

namespace engine {

	class Engine {
	private:
		graphics::Window* m_GameWindow;
		Update m_Updater;
		entt::registry m_Registry;

		static std::shared_ptr<Engine> s_engineSingleton;

		Engine(const std::string&);

	public:
		~Engine();

		int Run();

		Update& GetUpdater() { return m_Updater; }
		entt::registry& GetECS() { return m_Registry; }

		static std::shared_ptr<Engine> GetEngine();
	};

}; // namespace engine