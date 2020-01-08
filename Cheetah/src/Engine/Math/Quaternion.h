#ifndef CHEETAH_CORE_MATH_QUATERNION_H_
#define CHEETAH_CORE_MATH_QUATERNION_H_

#include "Core/Core.h"

#include "Vector4.h"
#include "Vector3.h"
#include "Mat4x4.h"

#include<math.h>

namespace cheetah
{
	class CH_API Quaternion : public Vector4f
	{
	public:
		Quaternion();
		Quaternion(const Vector3f& axis, const float& degrees);
		
		void normalize();
		Vector4f normalize(const Vector4f& vector) const;
		Mat4x4f getMatrix() const;
	};
}

#endif // !CHEETAH_CORE_MATH_QUATERNION_H_
