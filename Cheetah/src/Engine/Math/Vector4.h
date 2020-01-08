#ifndef CHEETAH_ENGINE_MATH_VECTOR4_H_
#define CHEETAH_ENGINE_MATH_VECTOR4_H_

#include "../Core/Core.h"

namespace cheetah
{
	template<typename T>
	class Vector4
	{
	protected:
		T m_data[4];
	public:
		T& x;
		T& y;
		T& z;
		T& w;

	public:
		Vector4(const T& fill);
		Vector4(const T& x, const T& y, const T& z, const T& w);
	};

	template class CH_API Vector4<float>;
	template class CH_API Vector4<int>;
	template class CH_API Vector4<double>;

	using Vector4f = Vector4<float>;
	using Vector4i = Vector4<int>;
	using Vector4d = Vector4<double>;
}

#include "Vector4.inl"

#endif // !CHEETAH_ENGINE_MATH_VECTOR_H_