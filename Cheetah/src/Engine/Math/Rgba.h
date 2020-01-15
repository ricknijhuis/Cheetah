#ifndef CHEETAH_ENGINE_MATH_RGBA_H_
#define CHEETAH_ENGINE_MATH_RGBA_H_

#include "Vector.h"
#include "Vector3.h"
#include "Rgb.h"

namespace cheetah
{
	namespace math
	{
		class Rgba : public Vector<float, 4, VectorType::Color>
		{
			Rgba();
			Rgba(const float& fill);
			Rgba(const float fill[4]);
			Rgba(const Rgb& rgb, float a = 1.0f);
		};
	}
}

#endif // !CHEETAH_ENGINE_MATH_RGBA_H_
