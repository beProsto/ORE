#ifndef _ORE_MATH_HPP_HEADER_FILE_GUARD
#define _ORE_MATH_HPP_HEADER_FILE_GUARD

#include <cmath>
#include "mat4.hpp"

/* Math Operations */
namespace Math {
	float Rad(float _a) {
		return _a * (M_PI / 180.0f);
	}
	float Deg(float _a) {
		return _a / (M_PI / 180.0f);
	}
}


#endif/*_ORE_MATH_HPP_HEADER_FILE_GUARD*/
