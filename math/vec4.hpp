#ifndef _ORE_VEC4_HPP_HEADER_FILE_GUARD
#define _ORE_VEC4_HPP_HEADER_FILE_GUARD

#include "_vec4.hpp"

namespace Math {
	class Vec4 {
	public:
		Vec4(float _a = 0) {
			x = _a;
			y = _a;
			z = _a;
			w = _a;
		}
		Vec4(float _x, float _y, float _z, float _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
		Vec4(const Vec4& _other) {
			x = (_other.x);
			y = (_other.y);
			z = (_other.z);
			w = (_other.w);
		}

		float& operator[](size_t _i) {
			return *(((float*)this)+_i);
		}

		Vec4& operator=(const Vec4& _other) {
			x = (_other.x);
			y = (_other.y);
			z = (_other.z);
			w = (_other.w);
			return *this;
		}

		Vec4 operator+(const Vec4& _a) const {
			return Vec4(x + (_a.x), 
						y + (_a.y),
						z + (_a.z),
						w + (_a.w));
		}
		Vec4 operator-(const Vec4& _a) const {
			return Vec4(x - (_a.x), 
						y - (_a.y),
						z - (_a.z),
						w - (_a.w));
		}
		Vec4 operator*(const Vec4& _a) const {
			return Vec4(x * (_a.x), 
						y * (_a.y),
						z * (_a.z),
						w * (_a.w));
		}
		Vec4 operator/(const Vec4& _a) const {
			return Vec4(x / (_a.x), 
						y / (_a.y),
						z / (_a.z),
						w / (_a.w));
		}

		Vec4& operator+=(const Vec4& _a) {
			return (*this) = Vec4(x + (_a.x), 
									y + (_a.y),
									z + (_a.z),
									w + (_a.w));
		}
		Vec4& operator-=(const Vec4& _a) {
			return (*this) = Vec4(x - (_a.x), 
									y - (_a.y),
									z - (_a.z),
									w - (_a.w));
		}
		Vec4& operator*=(const Vec4& _a) {
			return (*this) = Vec4(x * (_a.x), 
									y * (_a.y),
									z * (_a.z),
									w * (_a.w));
		}
		Vec4& operator/=(const Vec4& _a) {
			return (*this) = Vec4(x / (_a.x), 
									y / (_a.y),
									z / (_a.z),
									w / (_a.w));
		}

		bool operator==(const Vec4& _a) const {
			return (x == (_a.x) && y == (_a.y) && z == (_a.z) && w == (_a.w));
		}
		bool operator!=(const Vec4& _a) const {
			return (x != (_a.x) || y != (_a.y) || z != (_a.z) || w != (_a.w));
		}
		bool operator<=(const Vec4& _a) const {
			return (x <= (_a.x) && y <= (_a.y) && z <= (_a.z) && w <= (_a.w));
		}
		bool operator>=(const Vec4& _a) const {
			return (x >= (_a.x) && y >= (_a.y) && z >= (_a.z) && w >= (_a.w));
		}
		bool operator<(const Vec4& _a) const {
			return (x < (_a.x) && y < (_a.y) && z < (_a.z) && w < (_a.w));
		}
		bool operator>(const Vec4& _a) const {
			return (x > (_a.x) && y > (_a.y) && z > (_a.z) && w > (_a.w));
		}
		

		union { /*[0]*/
			float x;
			float u;
			float r;	
		};
		union { /*[1]*/
			float y;
			float v;
			float g;
		};
		union { /*[2]*/
			float z;
			float b;
		};
		union { /*[3]*/
			float w;
			float a;
		};
	};

}

#endif/*_ORE_VEC4_HPP_HEADER_FILE_GUARD*/