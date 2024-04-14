#include "engine.h"
#include "logging.h"

#include <chrono>
#include <thread>

namespace engine {

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

std::unique_ptr<Engine> Engine::makeEngine()
{
	// Hide from main()
	static bool loggingInitialized = false;
	if (!loggingInitialized) {
		google::SetLogDestination(google::GLOG_INFO, "./engine-log-");
		google::InitGoogleLogging("GameEngine");
		loggingInitialized = true;
	}

	return std::unique_ptr<Engine>(new Engine("Game Engine"));
}

}; // namespace engine