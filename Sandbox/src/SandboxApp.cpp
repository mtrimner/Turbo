#include <Turbo.h>


class Sandbox : public Turbo::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Turbo::Application* Turbo::CreateApplication()
{
	return new Sandbox();
}