#pragma once
#include "Core.h"

namespace NoRubish {

	class NR_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};

	//To be declared
	Application* CreateApplication();

}

