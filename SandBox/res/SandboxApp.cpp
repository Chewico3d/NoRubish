#include "NoRubish.h"

class sandbox : public NoRubish::Application {
public:
	sandbox() {


	}

	~sandbox() {


	}

};

NoRubish::Application* NoRubish::CreateApplication() {

	return new sandbox;
}