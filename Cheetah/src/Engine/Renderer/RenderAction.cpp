#include "RenderAction.h"

namespace cheetah
{
	std::unique_ptr<RenderAPI> RenderAction::s_renderAPI = RenderAPI::create();

	void RenderAction::init()
	{
		s_renderAPI->init();
	}

	void RenderAction::setViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
	{
		s_renderAPI->setViewPort(x, y, width, height);
	}

	void RenderAction::setClearColor(float r, float g, float b, float a)
	{
		s_renderAPI->clearColor(r, g, b, a);
	}

	void RenderAction::drawIndexed(short unsigned int count, RenderAPI::APITypes type)
	{
		s_renderAPI->drawIndexed(count, type);
	}

	void RenderAction::clear()
	{
		s_renderAPI->clear();
	}
}