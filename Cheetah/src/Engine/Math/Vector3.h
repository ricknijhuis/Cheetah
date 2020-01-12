#ifndef CHEETAH_ENGINE_MATH_VECTOR3_H_
#define CHEETAH_ENGINE_MATH_VECTOR3_H_

#include "../Core/Core.h"

namespace cheetah
{
	template<typename T>
	union Vector3
	{
		inline Vector3();
		inline Vector3(const T& fill);
		inline Vector3(const T fill[3]);
		inline Vector3(const T& x, const T& y, const T& z);

		struct
		{
			T x, y, z;
		};

		inline const T* get() const;

		inline T magnitude() const;
		inline Vector3<T> cross(const Vector3<T>& rhs) const;

		inline void operator *= (const T& rhs);
		inline void operator += (const T& rhs);
		inline void operator -= (const T& rhs);
		inline void operator /= (const T& rhs);

		inline Vector3<T> operator + (const Vector3<T>& rhs) const;
		inline Vector3<T> operator - (const Vector3<T>& rhs) const;

		inline T operator * (const Vector3<T>& rhs) const;

	private:
		struct
		{
			T m_data[3];
		};
	};

	template union CH_API Vector3<float>;
	template union CH_API Vector3<int>;
	template union CH_API Vector3<double>;

	using Vector3f = Vector3<float>;
	using Vector3i = Vector3<int>;
	using Vector3d = Vector3<double>;
}

#include "Vector3.inl"

#endif // !CHEETAH_ENGINE_MATH_VECTOR3_H_