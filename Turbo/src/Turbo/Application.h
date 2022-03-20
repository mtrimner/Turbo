#pragma once

#include "Core.h"

namespace Turbo {

	class TB_API Application
	{
	public:
		Application();
		virtual ~Application();
		int Run();
	};

	// To be defined in client

	Application* CreateApplication();


}