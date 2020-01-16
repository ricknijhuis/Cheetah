#ifndef CHEETAH_ENGINE_MATH_RGB_H_
#define CHEETAH_ENGINE_MATH_RGB_H_


#include "Core/Core.h"
#include "Vector.h"
#include "Vector3.h"

namespace cheetah
{
	namespace math
	{
		class CH_API Rgb : public Vector<float, 3, VectorType::Color>
		{
			Rgb();
			Rgb(const float& fill);
			Rgb(const float fill[3]);

			inline void operator *= (const float& rhs);
			inline void operator += (const float& rhs);
			inline void operator -= (const float& rhs);
			inline void operator /= (const float& rhs);
		};
	}
}

#include "Rgb.inl"

#endif // !CHEETAH_ENGINE_MATH_RGB_H_
