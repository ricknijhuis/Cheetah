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

		template<typename T>
		class Vector4;

		template<template <typename> class T, typename Y>
		void operator += (T<Y>& rhs, const T<Y>& lhs);

		template<typename T, size_t size, VectorType type>
		class Vector
		{
		public:
			// getters
			inline const T* get() const
			{
				return &data[0];
			}

			union
			{
				struct
				{
					T data[size];
				};
			};
		};

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

			Vector(const T fill[4])
				: data{ fill[0], fill[1], fill[2] }
			{
			}

			Vector(const Vector<T, 3, VectorType::Color>& fill)
				: data{ fill.r, fill.g, fill.b }
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
					T r, g, b;
				};
			};
		};

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

			friend void operator += <, 4>(Vector4<T>& rhs, const Vector4<T>& lhs);
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
				: data{ fill.r, fill.x, fill.b, a }
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

		template<class U, typename T, size_t size>
		void operator += (Vector4<T>& rhs, const Vector4<T>& lhs)
		{
			for (int i = 0; i < size, i++)
				rhs.data[i] += rhs.data[i];
		}
	}
}

#endif // !CHEETAH_ENGINE_MATH_VECTOR_H_
