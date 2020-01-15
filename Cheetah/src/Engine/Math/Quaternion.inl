namespace cheetah
{
	namespace math
	{
		// ctors
		template<typename T>
		inline Quaternion<T>::Quaternion()
			: Vector<T, 4>()
		{
		}

		template<typename T>
		inline Quaternion<T>::Quaternion(const T& x, const T& y, const T& z, const T& degrees)
			: Vector<T, 4>(x, y, z, degrees)
		{
		}

		template<typename T>
		inline Quaternion<T>::Quaternion(const Vector3<T>& axis, const T& degrees)
			: Vector<T, 4>(axis, degrees)
		{
		}

		template<typename T>
		inline Quaternion<T>::Quaternion(const T fill[4])
			: Vector<T, 4>(fill)
		{
		}

		// getters
		template<typename T>
		inline const T* Quaternion<T>::get() const
		{
			return &data[0];
		}

		template<>
		inline Mat4x4<double> Quaterniond::getMatrix() const
		{
			auto quat = normalize(*this);
			auto mat = std::vector<double>
			{
				1.0 - 2.0 * quat.data[1] * quat.data[1] - 2.0 * quat.data[2] * quat.data[2],		2.0 * quat.data[0] * quat.data[1] - 2.0 * quat.data[2] * quat.data[3],			2.0 * quat.data[0] * quat.data[2] + 2.0 * quat.data[1] * quat.data[3],			0.0,
				2.0 * quat.data[0] * quat.data[1] + 2.0 * quat.data[2] * quat.data[3],				1.0 - 2.0 * quat.data[0] * quat.data[0] - 2.0 * quat.data[2] * quat.data[2],	2.0 * quat.data[1] * quat.data[2] - 2.0 * quat.data[0] * quat.data[3],			0.0,
				2.0 * quat.data[0] * quat.data[2] - 2.0 * quat.data[1] * quat.data[3],				2.0 * quat.data[1] * quat.data[2] + 2.0 * quat.data[0] * quat.data[3],			1.0 - 2.0 * quat.data[0] * quat.data[0] - 2.0 * quat.data[1] * quat.data[1],	0.0,
				0.0,																				0.0,																			0.0,																			1.0
			};

			return Mat4x4d(mat);
		}

		template<>
		inline Mat4x4<float> Quaternionf::getMatrix() const
		{
			auto quat = normalize(*this);
			auto mat = std::vector<float>
			{
				1.0f - 2 * quat.data[1] * quat.data[1] - 2.0f * quat.data[2] * quat.data[2],		2.0f * quat.data[0] * quat.data[1] - 2.0f * quat.data[2] * quat.data[3],			2.0f * quat.data[0] * quat.data[2] + 2.0f * quat.data[1] * quat.data[3],			0.0f,
				2.0f * quat.data[0] * quat.data[1] + 2.0f * quat.data[2] * quat.data[3],			1.0f - 2.0f * quat.data[0] * quat.data[0] - 2.0f * quat.data[2] * quat.data[2],		2.0f * quat.data[1] * quat.data[2] - 2.0f * quat.data[0] * quat.data[3],			0.0f,
				2.0f * quat.data[0] * quat.data[2] - 2.0f * quat.data[1] * quat.data[3],			2.0f * quat.data[1] * quat.data[2] + 2.0f * quat.data[0] * quat.data[3],			1.0f - 2.0f * quat.data[0] * quat.data[0] - 2.0f * quat.data[1] * quat.data[1],		0.0f,
				0.0f,																				0.0f,																				0.0f,																				1.0f
			};

			return Mat4x4f(mat);
		}

		template<typename T>
		inline Mat4x4<T> Quaternion<T>::getMatrix() const
		{
		}


		// math
		template<>
		inline void Quaterniond::normalize()
		{
			const double n = 1 / sqrt(x * x + y * y + z * z + w * w);
			data[0] *= n;
			data[1] *= n;
			data[2] *= n;
			data[3] *= n;
		}

		template<>
		inline void Quaternionf::normalize()
		{
			const float n = 1.0f / sqrt(x * x + y * y + z * z + w * w);
			data[0] *= n;
			data[1] *= n;
			data[2] *= n;
			data[3] *= n;
		}

		template<typename T>
		inline void Quaternion<T>::normalize()
		{
		}

		template<>
		inline Quaterniond Quaterniond::normalize(const Quaterniond& quat) const
		{
			const double n = 1 / sqrt(quat.x * quat.x + quat.y * quat.y + quat.z * quat.z + quat.w * quat.w);
			Quaterniond q(quat.x, quat.y, quat.z, quat.w);
			q.data[0] *= n;
			q.data[1] *= n;
			q.data[2] *= n;
			q.data[3] *= n;

			return quat;
		}

		template<>
		inline Quaternionf Quaternionf::normalize(const Quaternionf& quat) const
		{
			const float n = 1.0f / sqrt(quat.x * quat.x + quat.y * quat.y + quat.z * quat.z + quat.w * quat.w);
			Quaternionf q(quat.x, quat.y, quat.z, quat.w);
			q.data[0] *= n;
			q.data[1] *= n;
			q.data[2] *= n;
			q.data[3] *= n;

			return quat;
		}

		template<typename T>
		inline Quaternion<T> Quaternion<T>::normalize(const Quaternion<T>& quat) const
		{
		}

		template<typename T>
		inline void Quaternion<T>::operator *= (const T& rhs)
		{
			data[0] *= rhs;
			data[1] *= rhs;
			data[2] *= rhs;
			data[3] *= rhs;
		}

		template<typename T>
		inline void Quaternion<T>::operator += (const T& rhs)
		{
			data[0] += rhs;
			data[1] += rhs;
			data[2] += rhs;
			data[3] += rhs;
		}

		template<typename T>
		inline void Quaternion<T>::operator -= (const T& rhs)
		{
			data[0] -= rhs;
			data[1] -= rhs;
			data[2] -= rhs;
			data[3] -= rhs;
		}

		template<typename T>
		inline void Quaternion<T>::operator /= (const T& rhs)
		{
			data[0] /= rhs;
			data[1] /= rhs;
			data[2] /= rhs;
			data[3] /= rhs;
		}

		template<typename T>
		inline Quaternion<T> Quaternion<T>::operator + (const Vector4<T>& rhs) const
		{
			return { data[0] + rhs.x, data[1] + rhs.y, data[2] + rhs.z, data[3] + rhs.w };
		}

		template<typename T>
		inline Quaternion<T> Quaternion<T>::operator - (const Vector4<T>& rhs) const
		{
			return { data[0] + (-rhs.x), data[1] + (-rhs.y), data[2] + (-rhs.z), data[3] + (-rhs.w) };
		}

		template<typename T>
		inline T Quaternion<T>::operator * (const Vector4<T>& rhs) const
		{
			return (data[0] * rhs.x) + (data[1] * rhs.y) + (data[2] * rhs.z) + (data[3] * rhs.w);
		}
	}
}