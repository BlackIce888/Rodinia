#include "Rodinia/Core/Application.hpp"
#include "Rodinia/Core/Logger.hpp"

namespace Rodinia {
	Application::Application() {
		RODINIA_INFO("Application created");
	}

	Application::~Application() {
		RODINIA_INFO("Application closed");
	}

	void Application::Run() {
		RODINIA_INFO("Welcome to Rodinia!");
		while (true);
	}
}