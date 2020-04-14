#ifndef _ORE_MAT4_HPP_HEADER_FILE_GUARD
#define _ORE_MAT4_HPP_HEADER_FILE_GUARD

#include "_mat4.hpp"

class Mat4 {
public:
	Mat4() {
		_Mat4::Identity(m);
	}
	Mat4(float* _other) {
		memcpy(m, _other, 16 * sizeof(float));
	}
	Mat4(const Mat4& _other) {
		memcpy(m, _other.m, 16 * sizeof(float));
	}
	~Mat4() {
		
	}
	
	float& operator[](int _i) {
		return m[_i];		
	}
	const float& operator[](int _i) const {
		return m[_i];		
	}
	
	Mat4& operator=(const Mat4& _other) {
		memcpy(m, _other.m, 16 * sizeof(float));
		return *this;
	}
	Mat4& operator*=(const Mat4& _other) {
		_Mat4::Multiply(m, m, _other.m);
		return *this;
	}
	Mat4 operator*(const Mat4& _other) const {
		Mat4 temp;
		_Mat4::Multiply(temp.m, m, _other.m);
		return temp;
	}
	
	static Mat4 Transpose(const Mat4& _in) {
		Mat4 temp = _in;
		_Mat4::Transpose(temp.m);
		return temp;
	}
	static Mat4 Perspective(float _fov, float _aspect, float _near, float _far) {
		Mat4 temp;
		_Mat4::Perspective(temp.m, _fov, _aspect, _near, _far);
		return temp;
	}
	static Mat4 Orthographic(float _left, float _right, float _bottom, float _top, float _near, float _far) {
		Mat4 temp;
		_Mat4::Orthographic(temp.m, _left, _right, _bottom, _top, _near, _far);
		return temp;
	}
	static Mat4 Translate(float _x, float _y, float _z) {
		Mat4 temp;
		_Mat4::Translate(temp.m, _x, _y, _z);
		return temp;
	}
	static Mat4 RotateZ(float _rad) {
		Mat4 temp;
		_Mat4::RotateZ(temp.m, _rad);
		return temp;
	}
	static Mat4 RotateY(float _rad) {
		Mat4 temp;
		_Mat4::RotateY(temp.m, _rad);
		return temp;
	}
	static Mat4 RotateX(float _rad) {
		Mat4 temp;
		_Mat4::RotateX(temp.m, _rad);
		return temp;
	}
	static Mat4 Scale(float _x, float _y, float _z) {
		Mat4 temp;
		_Mat4::Scale(temp.m, _x, _y, _z);
		return temp;
	}
	static Mat4 Scale(float _s) {
		Mat4 temp;
		_Mat4::Scale(temp.m, _s, _s, _s);
		return temp;
	}
public:
	float m[16];		
};

#endif/*_ORE__MAT4_HPP_HEADER_FILE_GUARD*/