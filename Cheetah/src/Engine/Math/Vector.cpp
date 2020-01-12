#include "Quaternion.h"
#include "Vector4.h"
#include "Vector3.h"

namespace cheetah
{
	template union Vector4<float>;
	template union Vector4<int>;
	template union Vector4<double>;

	template union Vector3<float>;
	template union Vector3<int>;
	template union Vector3<double>;

	template union Quaternion<float>;
	template union Quaternion<int>;
	template union Quaternion<double>;
}