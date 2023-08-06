#pragma once

#ifdef FX_PLATFORM_WINDOWS

extern FrameX::Application* FrameX::CreateApplication();

int main(int argc, char** argv) 
{
	FrameX::Log::Init();
	auto app = FrameX::CreateApplication();
	
	app->Run();
	delete app;
}

#endif