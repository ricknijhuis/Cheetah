#include "Rgb.h"

namespace cheetah
{
	namespace math
	{
		Rgb::Rgb()
			: Vector<float, 3, VectorType::Color>()
		{
		}

		Rgb::Rgb(const float& fill)
			: Vector<float, 3, VectorType::Color>(fill)
		{
		}

		Rgb::Rgb(const float fill[3])
			: Vector<float, 3, VectorType::Color>(fill)
		{
		}
	}
}