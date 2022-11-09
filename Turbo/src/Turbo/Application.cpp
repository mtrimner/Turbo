#include "tbpch.h"
#include "Application.h"

#include "Turbo/Events/ApplicationEvent.h"
#include "Turbo/Log.h"

#include <GLFW/glfw3.h>

namespace Turbo {
	Application::Application()
	{
		// Will call the constructor to call init and initialize GLFW
		m_Window = std::unique_ptr<Window>(Window::Create()); // Unique pointer will make the window close upon termination
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{ // TODO: DELETE THIS BEFORE MOVING ON!!!!!!! Don't forget the #include.
			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}