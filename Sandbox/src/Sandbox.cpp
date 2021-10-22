#include <Rodinia/Core/Base.hpp>
#include <Rodinia/Core/Logger.hpp>

class Sandbox : public Rodinia::Application {
public:
	Sandbox() {}

	~Sandbox() {}
};

Rodinia::Application* Rodinia::CreateApplication() {
	CLIENT_INFO("Creating application");
	return new Sandbox();
}