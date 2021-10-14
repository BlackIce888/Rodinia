#include "Base.h"

class Sandbox : public Rodinia::Application {
public:
	Sandbox() {}

	~Sandbox() {}
};

Rodinia::Application* Rodinia::CreateApplication() {
	return new Sandbox();
}