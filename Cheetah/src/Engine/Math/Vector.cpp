#include "Quaternion.h"
#include "Vector4.h"
#include "Vector3.h"

namespace cheetah
{
	namespace math
	{
		template class Vector4<float>;
		template class Vector4<int>;
		template class Vector4<double>;

		template class Vector3<float>;
		template class Vector3<int>;
		template class Vector3<double>;

		template class Quaternion<float>;
		template class Quaternion<double>;
	}
}