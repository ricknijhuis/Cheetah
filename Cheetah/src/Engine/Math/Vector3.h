#ifndef CHEETAH_ENGINE_MATH_VECTOR3_H_
#define CHEETAH_ENGINE_MATH_VECTOR3_H_

#include "Core/Core.h"

namespace cheetah
{
	template<typename T>
	class Vector3
	{
	protected:
		T m_data[3];
	public:
		T& x;
		T& y;
		T& z;

	public:
		Vector3(const T& fill);
		Vector3(const T& x, const T& y, const T& z);
	};

	template class CH_API Vector3<float>;
	template class CH_API Vector3<int>;
	template class CH_API Vector3<double>;

	using Vector3f = Vector3<float>;
	using Vector3i = Vector3<int>;
	using Vector3d = Vector3<double>;
}

#include "Vector3.inl"

#endif // !CHEETAH_ENGINE_MATH_VECTOR3_H_