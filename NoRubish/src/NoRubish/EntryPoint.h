#pragma once

#ifdef NR_PLATFORM_WINDOWS

extern NoRubish::Application* NoRubish::CreateApplication();

int main(int arcs, char** argv) {

	NoRubish::Log::Init();
	NR_CORE_WARN("Initialitzed Client Logger");
	NR_INFO("Initialitzed NoRubish Logger");

	auto app = NoRubish::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // NR_PLATFORM_WINDOWS
