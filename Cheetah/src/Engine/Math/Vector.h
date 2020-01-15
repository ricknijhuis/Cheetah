#ifndef CHEETAH_ENGINE_MATH_VECTOR_H_
#define CHEETAH_ENGINE_MATH_VECTOR_H_

namespace cheetah
{
	namespace math
	{
		template<typename T, size_t size>
		class Vector
		{
		public:
			union
			{
				struct
				{
					T data[size];
				};
			};

			// getters
			inline const T* get() const
			{
				return &data[0];
			}
		};

		template<typename T>
		class Vector<T, 3>
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

			Vector(const Vector<T, 3>& fill)
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
		class Vector<T, 4>
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

			Vector(const Vector<T, 3>& fill, const T& w)
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
	}
}

#endif // !CHEETAH_ENGINE_MATH_VECTOR_H_
