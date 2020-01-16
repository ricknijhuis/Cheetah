#include "Rgba.h"

namespace cheetah
{
	namespace math
	{
		Rgba::Rgba()
			: Vector<float, 4, VectorType::Color>()
		{
		}

		Rgba::Rgba(const float& fill)
			: Vector<float, 4, VectorType::Color>(fill)
		{
		}

		Rgba::Rgba(const float fill[4])
			: Vector<float, 4, VectorType::Color>(fill)
		{
		}

		Rgba::Rgba(const float& r, const float& g, const float& b, const float& a)
			: Vector<float, 4, VectorType::Color>(r, g, b, a)
		{
		}

		Rgba::Rgba(const Rgb& rgb, float a)
			: Vector<float, 4, VectorType::Color>(rgb, a)
		{
		}
	}
}