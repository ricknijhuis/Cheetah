#ifndef CHEETAH_ENGINE_MATH_RGB_H_
#define CHEETAH_ENGINE_MATH_RGB_H_

#include "Vector.h"
#include "Vector3.h"

namespace cheetah
{
	namespace math
	{
		class Rgb : public Vector<float, 3, VectorType::Color>
		{
			Rgba();
			Rgba(const float& fill);
			Rgba(const float fill[3]);
		};
	}
}

#endif // !CHEETAH_ENGINE_MATH_RGB_H_