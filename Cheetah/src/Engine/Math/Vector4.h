#ifndef CHEETAH_ENGINE_MATH_VECTOR4_H_
#define CHEETAH_ENGINE_MATH_VECTOR4_H_

#include "Core/Core.h"
#include "Vector3.h"

namespace cheetah
{
	template<typename T>
	union Vector4
	{
		inline Vector4();
		inline Vector4(const T& fill);
		inline Vector4(const T fill[4]);
		inline Vector4(const Vector3<T>& fill, const T& w);
		inline Vector4(const T& x, const T& y, const T& z, const T& w);

		struct
		{
			T x, y, z, w;
		};

		inline const T* get() const;
		
		inline T magnitude() const;

		inline void operator *= (const T& rhs);
		inline void operator += (const T& rhs);
		inline void operator -= (const T& rhs);
		inline void operator /= (const T& rhs);

		inline Vector4<T> operator + (const Vector4<T>& rhs) const;
		inline Vector4<T> operator - (const Vector4<T>& rhs) const;

		inline T operator * (const Vector4<T>& rhs) const;

	private:
		struct
		{
			T m_data[4];
		};
	};

	template union CH_API Vector4<float>;
	template union CH_API Vector4<int>;
	template union CH_API Vector4<double>;

	using Vector4f = Vector4<float>;
	using Vector4i = Vector4<int>;
	using Vector4d = Vector4<double>;
}

#include "Vector4.inl"

#endif // !CHEETAH_ENGINE_MATH_VECTOR_H_