namespace cheetah
{
	// ctors
	template<typename T>
	inline Vector3<T>::Vector3()
		: m_data{ 0, 0, 0 }
	{
	}

	template<typename T>
	inline Vector3<T>::Vector3(const T& fill)
		: m_data{ fill, fill, fill }
	{
	}

	template<typename T>
	inline Vector3<T>::Vector3(const T fill[3])
		: m_data{ fill[0], fill[1], fill[2] }
	{
	}

	template<typename T>
	inline Vector3<T>::Vector3(const T& x, const T& y, const T& z)
		: m_data{ x, y, z }
	{
	}

	// getters
	template<typename T>
	inline const T* Vector3<T>::get() const
	{
		return &m_data[0];
	}

	//math
	template<typename T>
	inline T Vector3<T>::magnitude() const
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::cross(const Vector3<T>& rhs) const
	{
		return Vector3<T>(
			((m_data[1] * rhs.m_data[2]) - (m_data[2] * rhs.m_data[1])),
			((m_data[2] * rhs.m_data[0]) - (m_data[0] * rhs.m_data[2])),
			((m_data[0] * rhs.m_data[1]) - (m_data[1] * rhs.m_data[0]))
			);
	}

	// operators
	template<typename T>
	inline void Vector3<T>::operator *= (const T& rhs)
	{
		m_data[0] *= rhs;
		m_data[1] *= rhs;
		m_data[2] *= rhs;
	}

	template<typename T>
	inline void Vector3<T>::operator /= (const T& rhs)
	{
		m_data[0] /= rhs;
		m_data[1] /= rhs;
		m_data[2] /= rhs;
	}

	template<typename T>
	inline void Vector3<T>::operator += (const T& rhs)
	{
		m_data[0] += rhs;
		m_data[1] += rhs;
		m_data[2] += rhs;
	}

	template<typename T>
	inline void Vector3<T>::operator -= (const T& rhs)
	{
		m_data[0] -= rhs;
		m_data[1] -= rhs;
		m_data[2] -= rhs;
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator + (const Vector3<T>& rhs) const
	{
		return Vector3<T>(m_data[0] + rhs.x, m_data[1] + rhs.y, m_data[2] + rhs.z);
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::operator - (const Vector3<T>& rhs) const
	{
		return Vector3<T>(m_data[0] + (-rhs.x), m_data[1] + (-rhs.y), m_data[2] + (-rhs.z));
	}

	template<typename T>
	inline T Vector3<T>::operator * (const Vector3<T>& rhs) const
	{
		return (m_data[0] * rhs.m_data[0]) + (m_data[1] * rhs.m_data[1]) + (m_data[2] * rhs.m_data[2]);
	}
}