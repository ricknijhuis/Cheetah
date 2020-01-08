#ifndef CHEETAH_ENGINE_CORE_ENTRYPOINT_H_
#define CHEETAH_ENGINE_CORE_ENTRYPOINT_H_

#include "Application.h"

#ifdef CH_PLATFORM_WINDOWS

extern cheetah::Application* cheetah::createApplication();

int main(int argc, char** argv)
{
	auto app = cheetah::createApplication();
	app->run();
	delete app;
}

#endif // CH_PLATFORM_WINDOWS

#endif // !CHEETAH_ENGINE_CORE_ENTRYPOINT_H_
