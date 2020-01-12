namespace cheetah
{
	// ctors
	template<typename T>
	inline Vector4<T>::Vector4()
		: m_data{ 0, 0, 0, 0 }
	{
	}

	template<typename T>
	inline Vector4<T>::Vector4(const T& fill)
		: m_data{ fill, fill, fill, fill }
	{
	}

	template<typename T>
	inline Vector4<T>::Vector4(const T fill[4])
		: m_data{ fill[0], fill[1], fill[2], fill[3] }
	{
	}

	template<typename T>
	inline Vector4<T>::Vector4(const Vector3<T>& fill, const T& w)
		: m_data{ fill.x, fill.y, fill.z, w }
	{
	}

	template<typename T>
	inline Vector4<T>::Vector4(const T& x, const T& y, const T& z, const T& w)
		: m_data{ x, y, z, w }
	{
	}

	// getters
	template<typename T>
	inline const T* Vector4<T>::get() const
	{
		return &m_data[0];
	}

	//math
	template<typename T>
	inline T Vector4<T>::magnitude() const
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	}

	// operators
	template<typename T>
	inline void Vector4<T>::operator *= (const T& rhs)
	{
		m_data[0] *= rhs;
		m_data[1] *= rhs;
		m_data[2] *= rhs;
		m_data[3] *= rhs;
	}

	template<typename T>
	inline void Vector4<T>::operator /= (const T& rhs)
	{
		m_data[0] /= rhs;
		m_data[1] /= rhs;
		m_data[2] /= rhs;
		m_data[3] /= rhs;
	}

	template<typename T>
	inline void Vector4<T>::operator += (const T& rhs)
	{
		m_data[0] += rhs;
		m_data[1] += rhs;
		m_data[2] += rhs;
		m_data[3] += rhs;
	}

	template<typename T>
	inline void Vector4<T>::operator -= (const T& rhs)
	{
		m_data[0] -= rhs;
		m_data[1] -= rhs;
		m_data[2] -= rhs;
		m_data[3] -= rhs;
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator + (const Vector4<T>& rhs) const
	{
		return Vector4<T>(m_data[0] + rhs.x, m_data[1] + rhs.y, m_data[2] + rhs.z, m_data[3] + rhs.w);
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::operator - (const Vector4<T>& rhs) const
	{
		return Vector4<T>(m_data[0] + (-rhs.x), m_data[1] + (-rhs.y), m_data[2] + (-rhs.z), m_data[3] + (-rhs.w));
	}

	template<typename T>
	inline T Vector4<T>::operator * (const Vector4<T>& rhs) const
	{
		return (m_data[0] * rhs.m_data[0]) + (m_data[1] * rhs.m_data[1]) + (m_data[2] * rhs.m_data[2]) + (m_data[3] * rhs.m_data[3]);
	}
}