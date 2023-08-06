#include <FrameX.h>

class ExampleLayer : public FrameX::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FX_INFO("ExampleLayer::Update");
	}

	void OnEvent(FrameX::Event& event) override
	{
		// FX_TRACE("{0}", event.ToString()); - ONLY WORKS IN RELEASE / DIST MODE
	}
};

class Sandbox : public FrameX::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

FrameX::Application* Start()
{
	WindowResizeEvent e(1920, 1080);

	FX_TRACE(e.ToString());
	FX_TRACE("trace");
	FX_INFO("info");
	FX_WARN("warning");
	FX_ERROR("ERROR!");
	return new Sandbox();
}

