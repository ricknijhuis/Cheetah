#include "Renderer.h"

#include "Core/Application.h"
#include "RenderAction.h"
#include "Renderer2D.h"

namespace cheetah
{
	void Renderer::init()
	{
		RenderAction::init();
		RenderAction::setViewPort(0, 0, Application::getWindow().getWidth(), Application::getWindow().getHeight());
		Renderer2D::init();
	}

	void Renderer::setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
	{
		RenderAction::setViewPort(x, y, width, height);
	}

	void Renderer::shutDown()
	{
		Renderer2D::shutDown();
	}
}