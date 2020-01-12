#ifndef CHEETAH_ENGINE_CORE_CORE_H_
#define CHEETAH_ENGINE_CORE_CORE_H_

#include <memory>
#include <string>
#include <iostream>

#ifdef CH_ASSERT_ENABLED

#include <assert.h>
#include <type_traits>
#define ASSERT(expr, msg) if(!(expr)) {						\
	std::cout << "assertion failed: " << msg << std::endl;	\
	std::cout << "file: " << __FILE__ << std::endl;			\
	std::cout << "line: " << __LINE__ << std::endl;			\
	__debugbreak();											\
}															

#define STATIC_ASSERT(expr, msg) static_assert(expr, "static assertion failed: " msg "\n file: " __FILE__ "\n line: ");

#endif // !CH_ENABLE_ASSERT

#ifdef CH_PLATFORM_WINDOWS
#ifdef CH_BUILD_DLL
#define CH_API __declspec(dllexport)
#else 
#define CH_API __declspec(dllimport)
#endif // CH_BUILD_DLL
#else 
#error Cheetah currently only supports windows!
#endif // CH_PLATFORM_WINDOWS

#endif // !CHEETAH_ENGINE_CORE_CORE_H_
