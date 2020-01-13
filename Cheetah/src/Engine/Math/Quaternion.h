#ifndef CHEETAH_CORE_MATH_QUATERNION_H_
#define CHEETAH_CORE_MATH_QUATERNION_H_

#include "Vector4.h"
#include "Vector3.h"
#include "Mat4x4.h"

#include<math.h>

#include "Core/Core.h"

namespace cheetah
{
	template<typename T>
	union Quaternion
	{
	public:
		Quaternion();
		Quaternion(const T& axisX, const T& axisY, const T& axisZ, const T& degrees);
		Quaternion(const Vector3<T>& axis, const T& degrees);
		Quaternion(const T fill[4]);

		struct
		{
			T axisX, axisY, axisZ, degrees;
		};

		inline const T* get() const;
		inline Mat4x4<T> getMatrix() const;

		inline void normalize();
		inline Quaternion<T> normalize(const Quaternion<T>& vector) const;

		inline void operator *= (const T& rhs);
		inline void operator += (const T& rhs);
		inline void operator -= (const T& rhs);
		inline void operator /= (const T& rhs);

		inline Quaternion<T> operator + (const Vector4<T>& rhs) const;
		inline Quaternion<T> operator - (const Vector4<T>& rhs) const;

		inline T operator * (const Vector4<T>& rhs) const;

	private:
		struct
		{
			T m_data[4];
		};
	};

	template union CH_API Quaternion<float>;
	template union CH_API Quaternion<int>;
	template union CH_API Quaternion<double>;

	using Quaternionf = Quaternion<float>;
	using Quaternioni = Quaternion<int>;
	using Quaterniond = Quaternion<double>;
}

#include "Quaternion.inl"

#endif // !CHEETAH_CORE_MATH_QUATERNION_H_
