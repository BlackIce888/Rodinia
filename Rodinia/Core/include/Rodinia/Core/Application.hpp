#pragma once

#ifdef RODINIA_PLATFORM_WINDOWS
	#ifdef RODINIA_BUILD_DLL
		#define RODINIA_API __declspec(dllexport)
	#else
		#define RODINIA_API __declspec(dllimport)
	#endif
#else
	#error Rodinia supports Windows only!
#endif

namespace Rodinia {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
}

