#ifndef CHEETAH_ENGINE_MATH_VECTOR3_H_
#define CHEETAH_ENGINE_MATH_VECTOR3_H_

#include "../Core/Core.h"
#include "Vector.h"

namespace cheetah
{
	namespace math
	{
		template<typename T>
		class Vector3 : public Vector<T, 3, VectorType::Vector>
		{
		public:
			inline Vector3();
			inline Vector3(const T& fill);
			inline Vector3(const T fill[3]);
			inline Vector3(const T& x, const T& y, const T& z);

			inline T magnitude() const;
			inline Vector3<T> cross(const Vector3<T>& rhs) const;

			inline void operator *= (const T& rhs);
			inline void operator += (const T& rhs);
			inline void operator -= (const T& rhs);
			inline void operator /= (const T& rhs);

			inline Vector3<T> operator + (const Vector3<T>& rhs) const;
			inline Vector3<T> operator - (const Vector3<T>& rhs) const;

			inline T operator * (const Vector3<T>& rhs) const;
		};

		template class CH_API Vector3<float>;
		template class CH_API Vector3<int>;
		template class CH_API Vector3<double>;

		using Vector3f = Vector3<float>;
		using Vector3i = Vector3<int>;
		using Vector3d = Vector3<double>;
	}
}

#include "Vector3.inl"

#endif // !CHEETAH_ENGINE_MATH_VECTOR3_H_