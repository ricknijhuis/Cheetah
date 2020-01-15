namespace cheetah
{
	namespace math
	{
		// ctors
		template<typename T>
		inline Vector4<T>::Vector4()
			: data{ 0, 0, 0, 0 }
		{
		}

		template<typename T>
		inline Vector4<T>::Vector4(const T& fill)
			: data{ fill, fill, fill, fill }
		{
		}

		template<typename T>
		inline Vector4<T>::Vector4(const T fill[4])
			: data{ fill[0], fill[1], fill[2], fill[3] }
		{
		}

		template<typename T>
		inline Vector4<T>::Vector4(const Vector3<T>& fill, const T& w)
			: data{ fill.x, fill.y, fill.z, w }
		{
		}

		template<typename T>
		inline Vector4<T>::Vector4(const T& x, const T& y, const T& z, const T& w)
			: data{ x, y, z, w }
		{
		}

		//math
		template<typename T>
		inline T Vector4<T>::magnitude() const
		{
			return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
		}

		// operators
		template<typename T>
		inline void Vector4<T>::operator *= (const T& rhs)
		{
			data[0] *= rhs;
			data[1] *= rhs;
			data[2] *= rhs;
			data[3] *= rhs;
		}

		template<typename T>
		inline void Vector4<T>::operator /= (const T& rhs)
		{
			data[0] /= rhs;
			data[1] /= rhs;
			data[2] /= rhs;
			data[3] /= rhs;
		}

		template<typename T>
		inline void Vector4<T>::operator += (const T& rhs)
		{
			data[0] += rhs;
			data[1] += rhs;
			data[2] += rhs;
			data[3] += rhs;
		}

		template<typename T>
		inline void Vector4<T>::operator -= (const T& rhs)
		{
			data[0] -= rhs;
			data[1] -= rhs;
			data[2] -= rhs;
			data[3] -= rhs;
		}

		template<typename T>
		inline Vector4<T> Vector4<T>::operator + (const Vector4<T>& rhs) const
		{
			return Vector4<T>(data[0] + rhs.x, data[1] + rhs.y, data[2] + rhs.z, data[3] + rhs.w);
		}

		template<typename T>
		inline Vector4<T> Vector4<T>::operator - (const Vector4<T>& rhs) const
		{
			return Vector4<T>(data[0] + (-rhs.x), data[1] + (-rhs.y), data[2] + (-rhs.z), data[3] + (-rhs.w));
		}

		template<typename T>
		inline T Vector4<T>::operator * (const Vector4<T>& rhs) const
		{
			return (data[0] * rhs.data[0]) + (data[1] * rhs.data[1]) + (data[2] * rhs.data[2]) + (data[3] * rhs.data[3]);
		}
	}
}