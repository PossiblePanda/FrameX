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
	return new Sandbox();
}