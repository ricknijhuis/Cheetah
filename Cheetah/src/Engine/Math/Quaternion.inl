namespace cheetah
{
	// ctors
	template<typename T>
	inline Quaternion<T>::Quaternion()
		: m_data{ 0, 0, 0, 0 }
	{
	}

	template<typename T>
	inline Quaternion<T>::Quaternion(const T& axisX, const T& axisY, const T& axisZ, const T& degrees)
		: m_data{ axisX, axisY, axisZ, degrees }
	{
	}

	template<typename T>
	inline Quaternion<T>::Quaternion(const Vector3<T>& axis, const T& degrees)
		: m_data{ axis.x, axis.y, axis.z, degrees }
	{
	}

	template<typename T>
	inline Quaternion<T>::Quaternion(const T fill[4])
		: m_data{ fill[0], fill[1], fill[2], fill[3] }
	{
	}

	// getters
	template<typename T>
	inline const T* Quaternion<T>::get() const
	{
		return &m_data[0];
	}

	//template<>
	//inline Mat4x4<int> Quaternion<int>::getMatrix() const
	//{
	//	Quaternion<int> quat = normalize(Quaternion<int>(axisX, axisY, axisZ, degrees));
	//	std::vector<int> mat = std::vector<int>
	//	{
	//		1 - 2 * quat.m_data[1] * quat.m_data[1] - 2 * quat.m_data[2] * quat.m_data[2],		2 * quat.m_data[0] * quat.m_data[1] - 2 * quat.m_data[2] * quat.m_data[3],			2 * quat.m_data[0] * quat.m_data[2] + 2 * quat.m_data[1] * quat.m_data[3],			0,
	//		2 * quat.m_data[0] * quat.m_data[1] + 2 * quat.m_data[2] * quat.m_data[3],			1 - 2 * quat.m_data[0] * quat.m_data[0] - 2 * quat.m_data[2] * quat.m_data[2],		2 * quat.m_data[1] * quat.m_data[2] - 2 * quat.m_data[0] * quat.m_data[3],			0,
	//		2 * quat.m_data[0] * quat.m_data[2] - 2 * quat.m_data[1] * quat.m_data[3],			2 * quat.m_data[1] * quat.m_data[2] + 2 * quat.m_data[0] * quat.m_data[3],			1 - 2 * quat.m_data[0] * quat.m_data[0] - 2 * quat.m_data[1] * quat.m_data[1],		0,
	//		0,																					0,																					0,																					1
	//	};

	//	return Mat4x4i(mat);
	//}

	//template<>
	//inline Mat4x4<double> Quaternion<double>::getMatrix() const
	//{
	//	Quaternion<double> quat = normalize(Quaternion<double>(axisX, axisY, axisZ, degrees));
	//	std::vector<double> mat = std::vector<double>
	//	{
	//		1 - 2 * quat.m_data[1] * quat.m_data[1] - 2 * quat.m_data[2] * quat.m_data[2],		2 * quat.m_data[0] * quat.m_data[1] - 2 * quat.m_data[2] * quat.m_data[3],			2 * quat.m_data[0] * quat.m_data[2] + 2 * quat.m_data[1] * quat.m_data[3],			0,
	//		2 * quat.m_data[0] * quat.m_data[1] + 2 * quat.m_data[2] * quat.m_data[3],			1 - 2 * quat.m_data[0] * quat.m_data[0] - 2 * quat.m_data[2] * quat.m_data[2],		2 * quat.m_data[1] * quat.m_data[2] - 2 * quat.m_data[0] * quat.m_data[3],			0,
	//		2 * quat.m_data[0] * quat.m_data[2] - 2 * quat.m_data[1] * quat.m_data[3],			2 * quat.m_data[1] * quat.m_data[2] + 2 * quat.m_data[0] * quat.m_data[3],			1 - 2 * quat.m_data[0] * quat.m_data[0] - 2 * quat.m_data[1] * quat.m_data[1],		0,
	//		0,																					0,																					0,																					1
	//	};

	//	return Mat4x4d(mat);
	//}

	template<>
	inline Mat4x4<float> Quaternion<float>::getMatrix() const
	{
		Vector4f vec = normalize(Vector4f(m_data[0], m_data[1], m_data[2], m_data[3]));
		std::vector<float> mat = std::vector<float>
		{
			1.0f - 2.0f * vec.y * vec.y - 2.0f * vec.z * vec.z,		2.0f * vec.x * vec.y - 2.0f * vec.z * vec.w,			2.0f * vec.x * vec.z + 2.0f * vec.y * vec.w,			0.0f,
			2.0f * vec.x * vec.y + 2.0f * vec.z * vec.w,			1.0f - 2.0f * vec.x * vec.x - 2.0f * vec.z * vec.z,		2.0f * vec.y * vec.z - 2.0f * vec.x * vec.w,			0.0f,
			2.0f * vec.x * vec.z - 2.0f * vec.y * vec.w,			2.0f * vec.y * vec.z + 2.0f * vec.x * vec.w,			1.0f - 2.0f * vec.x * vec.x - 2.0f * vec.y * vec.y,		0.0f,
			0.0f,													0.0f,													0.0f,													1.0f
		};

		return Mat4x4f(mat);
	}

	template<typename T>
	inline Mat4x4<T> Quaternion<T>::getMatrix() const
	{
		return Mat4x4<T>();
	}


	// math
	template<>
	inline void Quaternion<int>::normalize()
	{
		const int n = 1 / sqrt(axisX * axisX + axisY * axisY + axisZ * axisZ + degrees * degrees);
		m_data[0] *= n;
		m_data[1] *= n;
		m_data[2] *= n;
		m_data[3] *= n;
	}

	template<>
	inline void Quaternion<double>::normalize()
	{
		const double n = 1 / sqrt(axisX * axisX + axisY * axisY + axisZ * axisZ + degrees * degrees);
		m_data[0] *= n;
		m_data[1] *= n;
		m_data[2] *= n;
		m_data[3] *= n;
	}

	template<>
	inline void Quaternion<float>::normalize()
	{
		const float n = 1.0f / sqrt(axisX * axisX + axisY * axisY + axisZ * axisZ + degrees * degrees);
		m_data[0] *= n;
		m_data[1] *= n;
		m_data[2] *= n;
		m_data[3] *= n;
	}

	template<typename T>
	inline void Quaternion<T>::normalize()
	{
	}

	template<>
	inline Vector4<int> Quaternion<int>::normalize(const Vector4<int>& vector) const
	{
		const int n = 1 / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
		Vector4<int> quat(vector.x, vector.y, vector.z, vector.w);
		quat.x *= n;
		quat.y *= n;
		quat.z *= n;
		quat.w *= n;

		return quat;
	}

	template<>
	inline Vector4<double> Quaternion<double>::normalize(const Vector4<double>& vector) const
	{
		const double n = 1 / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
		Vector4<double> quat(vector.x, vector.y, vector.z, vector.w);
		quat.x *= n;
		quat.y *= n;
		quat.z *= n;
		quat.w *= n;

		return quat;
	}

	template<>
	inline Vector4<float> Quaternion<float>::normalize(const Vector4<float>& vector) const
	{
		const float n = 1.0f / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
		Vector4<float> quat(vector.x, vector.y, vector.z, vector.w);
		quat.x *= n;
		quat.y *= n;
		quat.z *= n;
		quat.w *= n;

		return quat;
	}

	template<typename T>
	inline Vector4<T> Quaternion<T>::normalize(const Vector4<T>& vector) const
	{
	}

	template<typename T>
	inline void Quaternion<T>::operator *= (const T& rhs)
	{
		m_data[0] *= rhs;
		m_data[1] *= rhs;
		m_data[2] *= rhs;
		m_data[3] *= rhs;
	}

	template<typename T>
	inline void Quaternion<T>::operator += (const T& rhs)
	{
		m_data[0] += rhs;
		m_data[1] += rhs;
		m_data[2] += rhs;
		m_data[3] += rhs;
	}

	template<typename T>
	inline void Quaternion<T>::operator -= (const T& rhs)
	{
		m_data[0] -= rhs;
		m_data[1] -= rhs;
		m_data[2] -= rhs;
		m_data[3] -= rhs;
	}

	template<typename T>
	inline void Quaternion<T>::operator /= (const T& rhs)
	{
		m_data[0] /= rhs;
		m_data[1] /= rhs;
		m_data[2] /= rhs;
		m_data[3] /= rhs;
	}

	template<typename T>
	inline Quaternion<T> Quaternion<T>::operator + (const Vector4<T>& rhs) const
	{
		return Quaternion<T>(m_data[0] + rhs.x, m_data[1] + rhs.y, m_data[2] + rhs.z, m_data[3] + rhs.w);
	}

	template<typename T>
	inline Quaternion<T> Quaternion<T>::operator - (const Vector4<T>& rhs) const
	{
		return Quaternion<T>(m_data[0] + (-rhs.x), m_data[1] + (-rhs.y), m_data[2] + (-rhs.z), m_data[3] + (-rhs.w));
	}

	template<typename T>
	inline T Quaternion<T>::operator * (const Vector4<T>& rhs) const
	{
		return (m_data[0] * rhs.x) + (m_data[1] * rhs.y) + (m_data[2] * rhs.z) + (m_data[3] * rhs.w);
	}
}