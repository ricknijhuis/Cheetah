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
			: Vector<float, 4, VectorType::Color>(fill);
		{
		}

		Rgba::Rgba(const Rgb& rgb, float a = 1.0f)
			: Vector<float, 4, VectorType::Color>(rgb, a);
		{
		}
	}
}