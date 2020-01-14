#ifndef CHEETAH_CORE_MATH_QUATERNION_H_
#define CHEETAH_CORE_MATH_QUATERNION_H_

#include "Vector4.h"
#include "Vector3.h"
#include "Mat4x4.h"

#include<math.h>

#include "../Core/Core.h"
#include "Vector.h"

namespace cheetah
{
	namespace math
	{
		template<typename T>
		class Quaternion : public Vector<T, 4>
		{
		public:
			Quaternion();
			Quaternion(const T& x, const T& y, const T& z, const T& degrees);
			Quaternion(const Vector3<T>& axis, const T& degrees);
			Quaternion(const T fill[4]);

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
		};

		template class CH_API Quaternion<float>;
		template class CH_API Quaternion<double>;

		using Quaternionf = Quaternion<float>;
		using Quaterniond = Quaternion<double>;
	}
}

#include "Quaternion.inl"

#endif // !CHEETAH_CORE_MATH_QUATERNION_H_
