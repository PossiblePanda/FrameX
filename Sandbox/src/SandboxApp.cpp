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
	FX_TRACE("trace");
	FX_INFO("info");
	FX_WARN("warning");
	FX_ERROR("ERROR!!!!!!!!");
	return new Sandbox();
}