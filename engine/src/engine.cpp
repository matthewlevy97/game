#include "engine.h"
#include "logging.h"

Engine::Engine(const std::string& title)
{
	m_GameWindow = new graphics::Window(title);

	LOG(INFO) << "Game Engine Initialized";
}

Engine::~Engine()
{
	if (m_GameWindow) {
		delete m_GameWindow;
	}
}

void Engine::Run()
{
	CHECK(m_GameWindow != nullptr);

	m_GameWindow->StartGraphicsLoop();
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