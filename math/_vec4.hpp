#ifndef _ORE__VEC4_HPP_HEADER_FILE_GUARD
#define _ORE__VEC4_HPP_HEADER_FILE_GUARD

#include <cmath>

namespace Math {
	namespace _Vec4 {
		void MultiplyByMat4(float* _retX, float* _retY, float* _retZ, float* _retW, float _x, float _y, float _z, float _w, float* _mat) {
			*_retX = _mat[0] * _x + _mat[1] * _y + _mat[2] * _z + _mat[3] * _w;
			*_retY = _mat[4] * _x + _mat[5] * _y + _mat[6] * _z + _mat[7] * _w;
			*_retZ = _mat[8] * _x + _mat[9] * _y + _mat[10] * _z + _mat[11] * _w;
			*_retW = _mat[12] * _x + _mat[13] * _y + _mat[14] * _z + _mat[15] * _w;
		}

	}
}

#endif/*_ORE__VEC4_HPP_HEADER_FILE_GUARD*/