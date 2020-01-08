namespace cheetah
{
	template<typename T>
	Vector4<T>::Vector4(const T& fill)
		: m_data{ fill, fill, fill, fill }, x(m_data[0]), y(m_data[1]), z(m_data[2]), w(m_data[3])
	{
	}

	template<typename T>
	Vector4<T>::Vector4(const T& x, const T& y, const T& z, const T& w)
		: m_data{ x, y, z, w }, x(m_data[0]), y(m_data[1]), z(m_data[2]), w(m_data[3])
	{
	}
}