#ifndef _OGR_MATH_HPP_HEADER_FILE_GUARD
#define _OGR_MATH_HPP_HEADER_FILE_GUARD

/* Math Operations */
namespace Math {
	float Rad(float _a) {
		return _a * (M_PI / 180.0f);
	}
	float Deg(float _a) {
		return _a / (M_PI / 180.0f);
	}
}

#include "mat4.hpp"

#endif/*_OGR_MATH_HPP_HEADER_FILE_GUARD*/