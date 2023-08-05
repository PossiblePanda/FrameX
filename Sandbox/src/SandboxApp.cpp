#include <FrameX.h>

class Sandbox : public FrameX::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

FrameX::Application* FrameX::CreateApplication()
{
	WindowResizeEvent e(1920, 1080);

	FX_TRACE(e.ToString());

	FX_TRACE("trace");
	FX_INFO("info");
	FX_WARN("warning");
	FX_ERROR("ERROR!");
	return new Sandbox();
}