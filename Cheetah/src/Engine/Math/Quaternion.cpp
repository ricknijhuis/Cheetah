#include "Quaternion.h"

namespace cheetah
{
	Quaternion::Quaternion()
		: Vector4f(0.0f, 0.0f, 0.0f, 1.0f)
	{
	}
	Quaternion::Quaternion(const Vector3f& axis, const float& degrees)
		: Vector4f(axis.x* sin(degrees / 2), axis.y* sin(degrees / 2), axis.z* sin(degrees / 2), cos(degrees / 2))
	{
	}

	void Quaternion::normalize()
	{
		const float n = 1.0f / sqrt(x * x + y * y + z * z + w * w);
		x *= n;
		y *= n;
		z *= n;
		w *= n;
	}

	Vector4f Quaternion::normalize(const Vector4f& vector) const
	{
		const float n = 1.0f / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
		Vector4f vec(vector.x, vector.y , vector.z, vector.w);
		vec.x *= n;
		vec.y *= n;
		vec.z *= n;
		vec.w *= n;

		return vec;
	}

	Mat4x4f Quaternion::getMatrix() const
	{
		Vector4f vec = normalize(Vector4f(x, y, z, w));
		std::vector<float> mat = std::vector<float>
		{
			1.0f - 2.0f * vec.y * vec.y - 2.0f * vec.z * vec.z,		2.0f * vec.x * vec.y - 2.0f * vec.z * vec.w,			2.0f * vec.x * vec.z + 2.0f * vec.y * vec.w,			0.0f,
			2.0f * vec.x * vec.y + 2.0f * vec.z * vec.w,			1.0f - 2.0f * vec.x * vec.x - 2.0f * vec.z * vec.z,		2.0f * vec.y * vec.z - 2.0f * vec.x * vec.w,			0.0f,
			2.0f * vec.x * vec.z - 2.0f * vec.y * vec.w,			2.0f * vec.y * vec.z + 2.0f * vec.x * vec.w,			1.0f - 2.0f * vec.x * vec.x - 2.0f * vec.y * vec.y,		0.0f,
			0.0f,													0.0f,													0.0f,													1.0f
		};

		return Mat4x4f(mat);
	}
}