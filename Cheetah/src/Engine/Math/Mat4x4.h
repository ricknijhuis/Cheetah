#ifndef CHEETAH_ENGINE_MATH_MAT4x4_H_
#define CHEETAH_ENGINE_MATH_MAT4x4_H_

#include "Core/Core.h"
#include "Vector4.h"
#include "Vector3.h"
#include <vector>

namespace cheetah
{
	namespace math
	{
		template<typename T>
		class Mat4x4
		{
		public:
			Mat4x4();
			Mat4x4(const T& identity);
			Mat4x4(std::vector<T>& data);

			T get(int col, int row) const;
			std::vector<T> get() const;
			// T* getRaw() const;

			Mat4x4<T> operator * (const Mat4x4<T>& rh);
			Vector4<T> operator * (const Vector4<T>& rh);
			static Mat4x4<T> scale(const Vector3<T>& vector);
			static Mat4x4<T> ortho(const T& left, const T& right, const T& top, const T& bottom, const T& zNear, const T& zFar, const T& aspectRatio);
			static Mat4x4<T> translate(const Mat4x4<T>& mat, const Vector3<T>& vector);

		private:
			std::vector<T> m_data;
		};

		template class CH_API Mat4x4<float>;
		template class CH_API Mat4x4<int>;
		template class CH_API Mat4x4<double>;

		using Mat4x4f = Mat4x4<float>;
		using Mat4x4i = Mat4x4<int>;
		using Mat4x4d = Mat4x4<double>;
	}
}

#include "Mat4x4.inl"

#endif // !CHEETAH_ENGINE_MATH_MAT4x4_H_
