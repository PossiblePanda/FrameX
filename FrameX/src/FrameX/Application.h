#pragma once

#include "Core.h"

namespace FrameX {
	class FRAMEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
