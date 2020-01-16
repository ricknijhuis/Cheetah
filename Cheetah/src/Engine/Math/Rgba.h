#ifndef CHEETAH_ENGINE_MATH_RGBA_H_
#define CHEETAH_ENGINE_MATH_RGBA_H_

#include "Core/Core.h"
#include "Vector.h"
#include "Rgb.h"

namespace cheetah
{
	namespace math
	{
		class CH_API Rgba : public Vector<float, 4, VectorType::Color>
		{
		public:
			Rgba();
			Rgba(const float& fill);
			Rgba(const float fill[4]);
			Rgba(const float& r, const float& g, const float& b, const float& a);
			Rgba(const Rgb& rgb, float a = 1.0f);

			inline void operator *= (const float& rhs);
			inline void operator += (const float& rhs);
			inline void operator -= (const float& rhs);
			inline void operator /= (const float& rhs);
		};
	}
}

#include "Rgba.inl"

#endif // !CHEETAH_ENGINE_MATH_RGBA_H_
