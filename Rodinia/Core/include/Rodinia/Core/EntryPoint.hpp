#pragma once

#ifdef RODINIA_PLATFORM_WINDOWS

extern Rodinia::Application* Rodinia::CreateApplication();

int main(int argc, char** argv) {
	auto app = Rodinia::CreateApplication();
	app->Run();
	delete app;
}
#endif