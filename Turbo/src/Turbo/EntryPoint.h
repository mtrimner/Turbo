#pragma once

#ifdef TB_PLATFORM_WINDOWS

extern Turbo::Application* Turbo::CreateApplication();

int main(int argc, char** argv)
{	
	printf("Please, for the love of god...work");
	auto app = Turbo::CreateApplication();
	app->Run();
	delete app;
}
#endif