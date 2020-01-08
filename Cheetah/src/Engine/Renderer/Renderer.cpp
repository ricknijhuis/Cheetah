#include "Renderer.h"

#include "RenderAction.h"
#include "Renderer2D.h"

namespace cheetah
{
	void Renderer::init()
	{
		RenderAction::init();
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