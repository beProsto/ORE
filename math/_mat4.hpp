#ifndef _ORE__MAT4_HPP_HEADER_FILE_GUARD
#define _ORE__MAT4_HPP_HEADER_FILE_GUARD

#include <cmath>
#include <cstring>
#include <utility>

/* Matrix Operations */
/* All of these require a pointer to float and name it _mat. 
Some of these require a pointer to float and name it _in.
These pointers should point to a predefined array of floats, with 16 elements. */
namespace Math {
namespace _Mat4 {
	void Copy(float* _mat, const float* _in) {
		memcpy(_mat, _in, 16 * sizeof(float));
	}
	void Identity(float* _mat) {
		memset(_mat, 0, 16 * sizeof(float));
		_mat[0] = _mat[5] = _mat[10] = _mat[15] = 1.0f;
	}
	void Transpose(float* _mat) {
		std::swap(_mat[1], _mat[4]);
		std::swap(_mat[2], _mat[8]);
		std::swap(_mat[3], _mat[12]);
		std::swap(_mat[7], _mat[13]);
		std::swap(_mat[11], _mat[14]);
		std::swap(_mat[6], _mat[9]);
	}
	void Inverse(float* _mat) {
		float inv[16];
		float det = 0.0f;
		int i = 0;

		inv[0] =  _mat[5] *  _mat[10] *  _mat[15] -  _mat[5] *  _mat[11] *  _mat[14] -  _mat[9] *  _mat[6] *  _mat[15] +  _mat[9] *  _mat[7] *  _mat[14] +  _mat[13] *  _mat[6] *  _mat[11] -  _mat[13] *  _mat[7] *  _mat[10];
		inv[4] = - _mat[4] *  _mat[10] *  _mat[15] +  _mat[4] *  _mat[11] *  _mat[14] +  _mat[8] *  _mat[6] *  _mat[15] -  _mat[8] *  _mat[7] *  _mat[14] -  _mat[12] *  _mat[6] *  _mat[11] +  _mat[12] *  _mat[7] *  _mat[10];
		inv[8] =  _mat[4] *  _mat[9] *  _mat[15] -  _mat[4] *  _mat[11] *  _mat[13] -  _mat[8] *  _mat[5] *  _mat[15] +  _mat[8] *  _mat[7] *  _mat[13] +  _mat[12] *  _mat[5] *  _mat[11] -  _mat[12] *  _mat[7] *  _mat[9];
		inv[12] = - _mat[4] *  _mat[9] *  _mat[14] +  _mat[4] *  _mat[10] *  _mat[13] + _mat[8] *  _mat[5] *  _mat[14] -  _mat[8] *  _mat[6] *  _mat[13] -  _mat[12] *  _mat[5] *  _mat[10] +  _mat[12] *  _mat[6] *  _mat[9];
		inv[1] = - _mat[1] *  _mat[10] *  _mat[15] +  _mat[1] *  _mat[11] *  _mat[14] +  _mat[9] *  _mat[2] *  _mat[15] -  _mat[9] *  _mat[3] *  _mat[14] -  _mat[13] *  _mat[2] *  _mat[11] +  _mat[13] *  _mat[3] *  _mat[10];
		inv[5] =  _mat[0] *  _mat[10] *  _mat[15] -  _mat[0] *  _mat[11] *  _mat[14] -  _mat[8] *  _mat[2] *  _mat[15] +  _mat[8] *  _mat[3] *  _mat[14] +  _mat[12] *  _mat[2] *  _mat[11] -  _mat[12] *  _mat[3] *  _mat[10];
		inv[9] = - _mat[0] *  _mat[9] *  _mat[15] +  _mat[0] *  _mat[11] *  _mat[13] +  _mat[8] *  _mat[1] *  _mat[15] -  _mat[8] *  _mat[3] *  _mat[13] -  _mat[12] *  _mat[1] *  _mat[11] +  _mat[12] *  _mat[3] *  _mat[9];
		inv[13] =  _mat[0] *  _mat[9] *  _mat[14] -  _mat[0] *  _mat[10] *  _mat[13] -  _mat[8] *  _mat[1] *  _mat[14] +  _mat[8] *  _mat[2] *  _mat[13] +  _mat[12] *  _mat[1] *  _mat[10] -  _mat[12] *  _mat[2] *  _mat[9];
		inv[2] =  _mat[1] *  _mat[6] *  _mat[15] -  _mat[1] *  _mat[7] *  _mat[14] -  _mat[5] *  _mat[2] *  _mat[15] +  _mat[5] *  _mat[3] *  _mat[14] +  _mat[13] *  _mat[2] *  _mat[7] -  _mat[13] *  _mat[3] *  _mat[6];
		inv[6] = - _mat[0] *  _mat[6] *  _mat[15] +  _mat[0] *  _mat[7] *  _mat[14] +  _mat[4] *  _mat[2] *  _mat[15] -  _mat[4] *  _mat[3] *  _mat[14] -  _mat[12] *  _mat[2] *  _mat[7] +  _mat[12] *  _mat[3] *  _mat[6];
		inv[10] =  _mat[0] *  _mat[5] *  _mat[15] -  _mat[0] *  _mat[7] *  _mat[13] -  _mat[4] *  _mat[1] *  _mat[15] +  _mat[4] *  _mat[3] *  _mat[13] +  _mat[12] *  _mat[1] *  _mat[7] -  _mat[12] *  _mat[3] *  _mat[5];
		inv[14] = - _mat[0] *  _mat[5] *  _mat[14] +  _mat[0] *  _mat[6] *  _mat[13] +  _mat[4] *  _mat[1] *  _mat[14] -  _mat[4] *  _mat[2] *  _mat[13] -  _mat[12] *  _mat[1] *  _mat[6] +  _mat[12] *  _mat[2] *  _mat[5];
		inv[3] = - _mat[1] *  _mat[6] *  _mat[11] +  _mat[1] *  _mat[7] *  _mat[10] +  _mat[5] *  _mat[2] *  _mat[11] -  _mat[5] *  _mat[3] *  _mat[10] -  _mat[9] *  _mat[2] *  _mat[7] +  _mat[9] *  _mat[3] *  _mat[6];
		inv[7] =  _mat[0] *  _mat[6] *  _mat[11] -  _mat[0] *  _mat[7] *  _mat[10] -  _mat[4] *  _mat[2] *  _mat[11] +  _mat[4] *  _mat[3] *  _mat[10] +  _mat[8] *  _mat[2] *  _mat[7] -  _mat[8] *  _mat[3] *  _mat[6];
		inv[11] = - _mat[0] *  _mat[5] *  _mat[11] +  _mat[0] *  _mat[7] *  _mat[9] +  _mat[4] *  _mat[1] *  _mat[11] -  _mat[4] *  _mat[3] *  _mat[9] -  _mat[8] *  _mat[1] *  _mat[7] +  _mat[8] *  _mat[3] *  _mat[5];
		inv[15] =  _mat[0] *  _mat[5] *  _mat[10] -  _mat[0] *  _mat[6] *  _mat[9] -  _mat[4] *  _mat[1] *  _mat[10] +  _mat[4] *  _mat[2] *  _mat[9] +  _mat[8] *  _mat[1] *  _mat[6] -  _mat[8] *  _mat[2] *  _mat[5];

		det =  _mat[0] * inv[0] +  _mat[1] * inv[4] +  _mat[2] * inv[8] +  _mat[3] * inv[12];
		if(det == 0) return;
		det = 1.0 / det;

		_mat[0] = inv[0] * det;
		_mat[1] = inv[1] * det;
		_mat[2] = inv[2] * det;
		_mat[3] = inv[3] * det;
		_mat[4] = inv[4] * det;
		_mat[5] = inv[5] * det;
		_mat[6] = inv[6] * det;
		_mat[7] = inv[7] * det;
		_mat[8] = inv[8] * det;
		_mat[9] = inv[9] * det;
		_mat[10] = inv[10] * det;
		_mat[11] = inv[11] * det;
		_mat[12] = inv[12] * det;
		_mat[13] = inv[13] * det;
		_mat[14] = inv[14] * det;
		_mat[15] = inv[15s] * det;
	}
	void Multiply(float* _mat, const float* _a, const float* _b) {
		float* a = (float*)_a; 
		bool aAllocated = false;
		if(_a == _mat) {
			a = new float[16];	
			aAllocated = true;
			memcpy(a, _a, 16 * sizeof(float));	
		}

		float b0 = _b[0],
			b1 = _b[1],
			b2 = _b[2],
			b3 = _b[3];

		_mat[0] = b0 * a[0] + b1 * a[4] + b2 * a[8] + b3 * a[12];
		_mat[1] = b0 * a[1] + b1 * a[5] + b2 * a[9] + b3 * a[13];
		_mat[2] = b0 * a[2] + b1 * a[6] + b2 * a[10] + b3 * a[14];
		_mat[3] = b0 * a[3] + b1 * a[7] + b2 * a[11] + b3 * a[15];

		b0 = _b[4];
		b1 = _b[5];
		b2 = _b[6];
		b3 = _b[7];

		_mat[4] = b0 * a[0] + b1 * a[4] + b2 * a[8] + b3 * a[12];
		_mat[5] = b0 * a[1] + b1 * a[5] + b2 * a[9] + b3 * a[13];
		_mat[6] = b0 * a[2] + b1 * a[6] + b2 * a[10] + b3 * a[14];
		_mat[7] = b0 * a[3] + b1 * a[7] + b2 * a[11] + b3 * a[15];

		b0 = _b[8];
		b1 = _b[9];
		b2 = _b[10];
		b3 = _b[11];

		_mat[8] = b0 * a[0] + b1 * a[4] + b2 * a[8] + b3 * a[12];
		_mat[9] = b0 * a[1] + b1 * a[5] + b2 * a[9] + b3 * a[13];
		_mat[10] = b0 * a[2] + b1 * a[6] + b2 * a[10] + b3 * a[14];
		_mat[11] = b0 * a[3] + b1 * a[7] + b2 * a[11] + b3 * a[15];

		b0 = _b[12];
		b1 = _b[13];
		b2 = _b[14];
		b3 = _b[15];

		_mat[12] = b0 * a[0] + b1 * a[4] + b2 * a[8] + b3 * a[12];
		_mat[13] = b0 * a[1] + b1 * a[5] + b2 * a[9] + b3 * a[13];
		_mat[14] = b0 * a[2] + b1 * a[6] + b2 * a[10] + b3 * a[14];
		_mat[15] = b0 * a[3] + b1 * a[7] + b2 * a[11] + b3 * a[15];
		
		if(aAllocated) {
			delete[] a;
		}
	}
	void Perspective(float* _mat, float _fov, float _aspect, float _near, float _far) {
		memset(_mat, 0, 16 * sizeof(float));
		float frustumScale = 1.0 / std::tan(_fov / 2);
		_mat[0] = frustumScale / _aspect;
		_mat[5] = frustumScale;
		_mat[10] = (_far + _near) / (_near - _far);
		_mat[14] = (2 * _far * _near) / (_near - _far);
		_mat[11] = -1.0f;
	}
	void Orthographic(float* _mat, float _left, float _right, float _bottom, float _top, float _near, float _far) {
		memset(_mat, 0, 16 * sizeof(float));
		_mat[0] = 2.0f / (_right - _left);
		_mat[5] = 2.0f / (_top - _bottom);
		_mat[10] = -(2.0f / (_far - _near));
		_mat[12] = -((_right + _left) / (_right - _left));
		_mat[13] = -((_top + _bottom) / (_top - _bottom));
		_mat[14] = -((_far + _near) / (_far - _near));
		_mat[15] = 1.0f;
	}
	void Translate(float* _mat, float _x, float _y, float _z) {
		_mat[12] += _x;
		_mat[13] += _y;
		_mat[14] += _z;
	}
	void Translate(float* _mat, const float* _in, float _x, float _y, float _z) {
		_mat[12] = _in[12] + _x;
		_mat[13] = _in[13] + _y;
		_mat[14] = _in[14] + _z;
	}
	void RotateZ(float* _mat, float _rad) {
		float s = std::sin(_rad);
		float c = std::cos(_rad);
		float in00 = _mat[0];
		float in01 = _mat[1];
		float in02 = _mat[2];
		float in03 = _mat[3];
		float in10 = _mat[4];
		float in11 = _mat[5];
		float in12 = _mat[6];
		float in13 = _mat[7];

		_mat[0] = in00 * c + in10 * s;
		_mat[1] = in01 * c + in11 * s;
		_mat[2] = in02 * c + in12 * s;
		_mat[3] = in03 * c + in13 * s;
		_mat[4] = in10 * c - in00 * s;
		_mat[5] = in11 * c - in01 * s;
		_mat[6] = in12 * c - in02 * s;
		_mat[7] = in13 * c - in03 * s;
	}
	void RotateZ(float* _mat, const float* _in, float _rad) {
		float s = std::sin(_rad);
		float c = std::cos(_rad);
		float in00 = _in[0];
		float in01 = _in[1];
		float in02 = _in[2];
		float in03 = _in[3];
		float in10 = _in[4];
		float in11 = _in[5];
		float in12 = _in[6];
		float in13 = _in[7];

		_mat[8] = _in[8];
		_mat[9] = _in[9];
		_mat[10] = _in[10];
		_mat[11] = _in[11];
		_mat[12] = _in[12];
		_mat[13] = _in[13];
		_mat[14] = _in[14];
		_mat[15] = _in[15];

		_mat[0] = in00 * c + in10 * s;
		_mat[1] = in01 * c + in11 * s;
		_mat[2] = in02 * c + in12 * s;
		_mat[3] = in03 * c + in13 * s;
		_mat[4] = in10 * c - in00 * s;
		_mat[5] = in11 * c - in01 * s;
		_mat[6] = in12 * c - in02 * s;
		_mat[7] = in13 * c - in03 * s;
	}
	void RotateY(float* _mat, float _rad) {
		float s = std::sin(_rad);
		float c = std::cos(_rad);
		float in00 = _mat[0];
		float in01 = _mat[1];
		float in02 = _mat[2];
		float in03 = _mat[3];
		float in20 = _mat[8];
		float in21 = _mat[9];
		float in22 = _mat[10];
		float in23 = _mat[11];

		_mat[0] = in00 * c - in20 * s;
		_mat[1] = in01 * c - in21 * s;
		_mat[2] = in02 * c - in22 * s;
		_mat[3] = in03 * c - in23 * s;
		_mat[8] = in00 * s + in20 * c;
		_mat[9] = in01 * s + in21 * c;
		_mat[10] = in02 * s + in22 * c;
		_mat[11] = in03 * s + in23 * c;
	}
	void RotateY(float* _mat, const float* _in, float _rad) {
		float s = std::sin(_rad);
		float c = std::cos(_rad);
		float in00 = _in[0];
		float in01 = _in[1];
		float in02 = _in[2];
		float in03 = _in[3];
		float in20 = _in[8];
		float in21 = _in[9];
		float in22 = _in[10];
		float in23 = _in[11];

		_mat[4] = _in[4];
		_mat[5] = _in[5];
		_mat[6] = _in[6];
		_mat[7] = _in[7];
		_mat[12] = _in[12];
		_mat[13] = _in[13];
		_mat[14] = _in[14];
		_mat[15] = _in[15];
		
		_mat[0] = in00 * c - in20 * s;
		_mat[1] = in01 * c - in21 * s;
		_mat[2] = in02 * c - in22 * s;
		_mat[3] = in03 * c - in23 * s;
		_mat[8] = in00 * s + in20 * c;
		_mat[9] = in01 * s + in21 * c;
		_mat[10] = in02 * s + in22 * c;
		_mat[11] = in03 * s + in23 * c;
	}
	void RotateX(float* _mat, float _rad) {
		float s = std::sin(_rad);
		float c = std::cos(_rad);
		float in10 = _mat[4];
		float in11 = _mat[5];
		float in12 = _mat[6];
		float in13 = _mat[7];
		float in20 = _mat[8];
		float in21 = _mat[9];
		float in22 = _mat[10];
		float in23 = _mat[11];

		_mat[4] = in10 * c + in20 * s;
		_mat[5] = in11 * c + in21 * s;
		_mat[6] = in12 * c + in22 * s;
		_mat[7] = in13 * c + in23 * s;
		_mat[8] = in20 * c - in10 * s;
		_mat[9] = in21 * c - in11 * s;
		_mat[10] = in22 * c - in12 * s;
		_mat[11] = in23 * c - in13 * s;
	}
	void RotateX(float* _mat, const float* _in, float _rad) {
		float s = std::sin(_rad);
		float c = std::cos(_rad);
		float in10 = _in[4];
		float in11 = _in[5];
		float in12 = _in[6];
		float in13 = _in[7];
		float in20 = _in[8];
		float in21 = _in[9];
		float in22 = _in[10];
		float in23 = _in[11];

		_mat[0] = _in[0];
		_mat[1] = _in[1];
		_mat[2] = _in[2];
		_mat[3] = _in[3];
		_mat[12] = _in[12];
		_mat[13] = _in[13];
		_mat[14] = _in[14];
		_mat[15] = _in[15];

		_mat[4] = in10 * c + in20 * s;
		_mat[5] = in11 * c + in21 * s;
		_mat[6] = in12 * c + in22 * s;
		_mat[7] = in13 * c + in23 * s;
		_mat[8] = in20 * c - in10 * s;
		_mat[9] = in21 * c - in11 * s;
		_mat[10] = in22 * c - in12 * s;
		_mat[11] = in23 * c - in13 * s;
	}
	void Scale(float* _mat, float _x, float _y, float _z) {
		_mat[0] *= _x;
		_mat[5] *= _y;
		_mat[10] *= _z;
	}
	void Scale(float* _mat, const float* _in, float _x, float _y, float _z) {
		memcpy(_mat, _in, 16 * sizeof(float));
		_mat[0] *= _x;
		_mat[5] *= _y;
		_mat[10] *= _z;
	}
}
}

#endif/*_ORE__MAT4_HPP_HEADER_FILE_GUARD*/
