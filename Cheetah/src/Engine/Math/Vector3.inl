namespace cheetah
{
	template<typename T>
	Vector3<T>::Vector3(const T& fill)
		: m_data{ fill, fill, fill }, x(m_data[0]), y(m_data[1]), z(m_data[2])
	{
	}

	template<typename T>
	Vector3<T>::Vector3(const T& x, const T& y, const T& z)
		: m_data{ x, y, z }, x(m_data[0]), y(m_data[1]), z(m_data[2])
	{
	}
}