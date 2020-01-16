namespace cheetah
{
	namespace math
	{
		inline void Rgba::operator *= (const float& rhs)
		{
			data[0] *= rhs;
			data[1] *= rhs;
			data[2] *= rhs;
			data[3] *= rhs;
		}

		inline void Rgba::operator /= (const float& rhs)
		{
			data[0] /= rhs;
			data[1] /= rhs;
			data[2] /= rhs;
			data[3] /= rhs;
		}

		inline void Rgba::operator += (const float& rhs)
		{
			data[0] += rhs;
			data[1] += rhs;
			data[2] += rhs;
			data[3] += rhs;
		}

		inline void Rgba::operator -= (const float& rhs)
		{
			data[0] -= rhs;
			data[1] -= rhs;
			data[2] -= rhs;
			data[3] -= rhs;
		}
	}
}