#pragma once
#ifdef NR_PLATFORM_WINDOWS

extern NoRubish::Application* NoRubish::CreateApplication();

int main(int arcs, char** argv) {

	auto app = NoRubish::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // NR_PLATFORM_WINDOWS
