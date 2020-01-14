namespace cheetah
{
	namespace math
	{
		// ctors
		template<typename T>
		inline Vector3<T>::Vector3()
			: Vector<T, 3>()
		{
		}

		template<typename T>
		inline Vector3<T>::Vector3(const T& fill)
			: Vector<T, 3>(fill, fill, fill)
		{
		}

		template<typename T>
		inline Vector3<T>::Vector3(const T fill[3])
			: Vector<T, 3>(fill)
		{
		}

		template<typename T>
		inline Vector3<T>::Vector3(const T& x, const T& y, const T& z)
			: Vector<T, 3>(x, y, z)
		{
		}

		//math
		template<typename T>
		inline T Vector3<T>::magnitude() const
		{
			return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		}

		template<typename T>
		inline Vector3<T> Vector3<T>::cross(const Vector3<T>& rhs) const
		{
			return Vector3<T>(
				((data[1] * rhs.data[2]) - (data[2] * rhs.data[1])),
				((data[2] * rhs.data[0]) - (data[0] * rhs.data[2])),
				((data[0] * rhs.data[1]) - (data[1] * rhs.data[0]))
				);
		}

		// operators
		template<typename T>
		inline void Vector3<T>::operator *= (const T& rhs)
		{
			data[0] *= rhs;
			data[1] *= rhs;
			data[2] *= rhs;
		}

		template<typename T>
		inline void Vector3<T>::operator /= (const T& rhs)
		{
			data[0] /= rhs;
			data[1] /= rhs;
			data[2] /= rhs;
		}

		template<typename T>
		inline void Vector3<T>::operator += (const T& rhs)
		{
			data[0] += rhs;
			data[1] += rhs;
			data[2] += rhs;
		}

		template<typename T>
		inline void Vector3<T>::operator -= (const T& rhs)
		{
			data[0] -= rhs;
			data[1] -= rhs;
			data[2] -= rhs;
		}

		template<typename T>
		inline Vector3<T> Vector3<T>::operator + (const Vector3<T>& rhs) const
		{
			return Vector3<T>(data[0] + rhs.x, data[1] + rhs.y, data[2] + rhs.z);
		}

		template<typename T>
		inline Vector3<T> Vector3<T>::operator - (const Vector3<T>& rhs) const
		{
			return Vector3<T>(data[0] + (-rhs.x), data[1] + (-rhs.y), data[2] + (-rhs.z));
		}

		template<typename T>
		inline T Vector3<T>::operator * (const Vector3<T>& rhs) const
		{
			return (data[0] * rhs.data[0]) + (data[1] * rhs.data[1]) + (data[2] * rhs.data[2]);
		}
	}
}