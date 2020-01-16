namespace cheetah
{
	namespace math
	{
		inline void Rgb::operator *= (const float& rhs)
		{
			data[0] *= rhs;
			data[1] *= rhs;
			data[2] *= rhs;
		}

		inline void Rgb::operator /= (const float & rhs)
		{
			data[0] /= rhs;
			data[1] /= rhs;
			data[2] /= rhs;
		}

		inline void Rgb::operator += (const float& rhs)
		{
			data[0] += rhs;
			data[1] += rhs;
			data[2] += rhs;
		}

		inline void Rgb::operator -= (const float& rhs)
		{
			data[0] -= rhs;
			data[1] -= rhs;
			data[2] -= rhs;
		}
	}
}