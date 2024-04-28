#include "engine.h"
#include "logging.h"

#include <chrono>
#include <thread>

namespace engine {

std::shared_ptr<Engine> Engine::s_engineSingleton(new Engine("Game Engine"));

Engine::Engine(const std::string& title)
{
	m_Updater = Update();
	m_GameWindow = new graphics::Window(title, m_Updater);

	LOG(INFO) << "Game Engine Initialized";
}

Engine::~Engine()
{
	if (m_GameWindow) {
		delete m_GameWindow;
	}
}

int Engine::Run()
{
	CHECK(m_GameWindow != nullptr);

	bool runUpdateLoop = true;
	auto th = std::thread([&]() {
		auto& updater = this->m_Updater;
		do {
			updater.RunFixedUpdate();
			std::this_thread::sleep_for(std::chrono::milliseconds(updater.FixedUpdateMs()));
		} while (runUpdateLoop);
	});
	
	m_GameWindow->StartGraphicsLoop();

	runUpdateLoop = false;
	th.join();

	return 0;
}

std::shared_ptr<Engine> Engine::GetEngine()
{
	// Hide from main()
	static bool loggingInitialized = false;
	if (!loggingInitialized) {
		google::SetLogDestination(google::GLOG_INFO, "./engine-log-");
		google::InitGoogleLogging("GameEngine");
		loggingInitialized = true;
	}
	return s_engineSingleton;
}

}; // namespace engine