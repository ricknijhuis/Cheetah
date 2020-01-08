namespace cheetah
{
	template<typename T>
	Mat4x4<T>::Mat4x4()
		: m_data(16, 0)
	{
	}

	template<typename T>
	Mat4x4<T>::Mat4x4(const T& identity)
		: m_data(16)
	{
		for (short i = 0; i < 4; i++)
			m_data[i * ((4 * 4) >> 2) + i] = identity;
	}

	template<typename T>
	Mat4x4<T>::Mat4x4(std::vector<T>& data)
	{
		m_data = data;
	}

	template<typename T>
	std::vector<T> Mat4x4<T>::get() const
	{
		return m_data;
	}

	template<typename T>
	T Mat4x4<T>::get(int col, int row) const
	{
		return m_data[(row * 4) + col];
	}

	template<typename T>
	Mat4x4<T>  Mat4x4<T>::operator * (const Mat4x4<T>& rh)
	{
		std::vector<T> data = std::vector<T>(16);
		for (int i = 0; i < m_data.size() / 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				data[(i * 4) + j] = (
					(m_data[(i * 4)] * (rh.get(0, j))) +
					(m_data[(i * 4) + 1] * (rh.get(1, j))) +
					(m_data[(i * 4) + 2] * (rh.get(2, j))) +
					(m_data[(i * 4) + 3] * (rh.get(3, j)))
					);
			}
		}
		return Mat4x4<T>(data);
	}

	template<typename T>
	Vector4<T> Mat4x4<T>::operator * (const Vector4<T>& rh)
	{
		std::vector<T> data = std::vector<T>(16);
		for (int i = 0; i < m_data.size() / 4; i++)
		{
			data[i] = (
				(m_data[(i * 4)] * (rh.x)) +
				(m_data[(i * 4) + 1] * (rh.y)) +
				(m_data[(i * 4) + 2] * (rh.z)) +
				(m_data[(i * 4) + 3] * (rh.w))
				);
		}
		return Vector4<T>(data[0], data[1], data[2], data[3]);
	}

	template<typename T>
	Mat4x4<T> Mat4x4<T>::scale(const Vector3<T>& vector)
	{
		std::vector<T> data = {
			vector.x, 0, 0, 0,
			0, vector.y, 0, 0,
			0, 0, vector.z, 0,
			0, 0, 0, 1
		};
		return Mat4x4(data);
	}

	template<typename T>
	Mat4x4<T> Mat4x4<T>::ortho(const T& left, const T& right, const T& top, const T& bottom, const T& zNear, const T& zFar, const T& aspectRatio)
	{
		const T aspectScale = 1 / aspectRatio;
		std::vector<T> data = {
			aspectScale / (right - left), 0, 0, 0,
			0, aspectScale / (top - bottom), 0, 0,
			0, 0, -2 / (zFar - zNear), 0,
			-((right + left) / (right - left)), -((top + bottom) / (top - bottom)), -((zFar + zNear) / (zFar - zNear)), 1
		};

		return Mat4x4(data);
	}

	template<typename T>
	Mat4x4<T> Mat4x4<T>::translate(const Mat4x4<T>& mat, const Vector3<T>& vector)
	{
		std::vector<T> data = mat.m_data;
		data[3] += vector.x;
		data[7] += vector.y;
		data[11] += vector.z;

		return Mat4x4(data);
	}
}