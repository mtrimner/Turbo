#pragma once

#ifdef TB_PLATFORM_WINDOWS

extern Turbo::Application* Turbo::CreateApplication();

int main(int argc, char** argv)
{	
	Turbo::Log::Init();
	TB_CORE_WARN("BAD STUFFFF");
	int numbersss = 7;
	TB_INFO("You rock var={0}", numbersss);

	auto app = Turbo::CreateApplication();
	app->Run();
	delete app;
}
#endif