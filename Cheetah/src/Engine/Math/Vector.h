#ifndef CHEETAH_ENGINE_MATH_VECTOR_H_
#define CHEETAH_ENGINE_MATH_VECTOR_H_

namespace cheetah
{
	namespace math
	{
		enum class VectorType
		{
			Vector = 0,
			Color = 1
		};

		// vector
		template<typename T, size_t size, VectorType type>
		class Vector;

		// specializations
		// vector 3
		template<typename T>
		class Vector<T, 3, VectorType::Vector>
		{
		public:
			Vector()
				: data{ 0, 0, 0 }
			{
			}

			Vector(const T& fill)
				: data{ fill, fill, fill }
			{
			}

			Vector(const T& x, const T& y, const T& z)
				: data{ x, y, z }
			{
			}

			Vector(const T fill[4])
				: data{ fill[0], fill[1], fill[2] }
			{
			}

			Vector(const Vector<T, 3, VectorType::Vector>& fill)
				: data{ fill.x, fill.y, fill.z }
			{
			}

			inline const T* get() const
			{
				return &data[0];
			}

			union
			{
				struct
				{
					T data[4];
				};
				struct
				{
					T x, y, z;
				};
			};
		};

		template<typename T>
		class Vector<T, 3, VectorType::Color>
		{
		public:
			Vector()
				: data{ 0, 0, 0 }
			{
			}

			Vector(const T& fill)
				: data{ fill, fill, fill }
			{
			}

			Vector(const T& r, const T& g, const T& b)
				: data{ r, g, b }
			{
			}

			Vector(const T fill[3])
				: data{ fill[0], fill[1], fill[2] }
			{
			}

			Vector(const Vector<T, 3, VectorType::Color>& fill)
				: data{ fill.r, fill.g, fill.b }
			{
			}

			//inline const T* get() const
			//{
			//	return &data[0];
			//}

			union
			{
				struct
				{
					T data[4];
				};
				struct
				{
					T r, g, b;
				};
			};
		};

		// vector 4
		template<typename T>
		class Vector<T, 4, VectorType::Vector>
		{
		public:
			Vector()
				: data{ 0, 0, 0, 0 }
			{
			}

			Vector(const T& fill)
				: data{ fill, fill, fill, fill }
			{
			}

			Vector(const T& x, const T& y, const T& z, const T& w)
				: data{ x, y, z, w }
			{
			}

			Vector(const T fill[4])
				: data{ fill[0], fill[1], fill[2], fill[3] }
			{
			}

			Vector(const Vector<T, 3, VectorType::Vector>& fill, const T& w)
				: data{ fill.x, fill.y, fill.z, w }
			{
			}

			inline const T* get() const
			{
				return &data[0];
			}

			union
			{
				struct
				{
					T data[4];
				};
				struct
				{
					T x, y, z, w;
				};
			};
		};

		template<typename T>
		class Vector<T, 4, VectorType::Color>
		{
		public:
			Vector()
				: data{ 0, 0, 0, 0 }
			{
			}

			Vector(const T& fill)
				: data{ fill, fill, fill, fill }
			{
			}

			Vector(const T& r, const T& g, const T& b, const T& a)
				: data{ r, g, b, a }
			{
			}

			Vector(const T fill[4])
				: data{ fill[0], fill[1], fill[2], fill[3] }
			{
			}

			Vector(const Vector<T, 3, VectorType::Color>& fill, const T& a)
				: data{ fill.r, fill.g, fill.b, a }
			{
			}

			inline const T* get() const
			{
				return &data[0];
			}

			union
			{
				struct
				{
					T data[4];
				};
				struct
				{
					T r, g, b, a;
				};
			};
		};
	}
}

#endif // !CHEETAH_ENGINE_MATH_VECTOR_H_
