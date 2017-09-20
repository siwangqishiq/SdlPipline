#pragma once
#include <iostream>
#include <math.h>



class Vec3 {
public:
	float x, y, z;
public:
	Vec3() {
		x = y = z = 0;
	}

	Vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3& operator=(const Vec3& rgh) {
		this->x = rgh.x;
		this->y = rgh.y;
		this->z = rgh.z;

		return *this;
	}

	Vec3 operator+(const Vec3& rgh) {
		Vec3 result;
		result.x = x + rgh.x;
		result.y = y + rgh.y;
		result.z = z + rgh.z;
		return result;
	}

	Vec3& operator+=(const Vec3& rgh) {
		x += rgh.x;
		y += rgh.y;
		z += rgh.z;
		return *this;
	}

	Vec3 operator-(const Vec3& rgh) {
		Vec3 result;
		result.x = x - rgh.x;
		result.y = y - rgh.y;
		result.z = z - rgh.z;
		return result;
	}

	Vec3& operator-=(const Vec3& rgh) {
		x -= rgh.x;
		y -= rgh.y;
		z -= rgh.z;
		return *this;
	}

	float operator*(const Vec3& rgh) {
		return x * rgh.x + y *rgh.y + z*rgh.z;
	}

	Vec3 operator*(float value) {
		Vec3 result = *this;
		result.x *= value;
		result.y *= value;
		result.z *= value;
		return result;
	}

	Vec3& operator*=(float value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	float length() {
		return sqrtf(x*x + y*y);
	}

	void normalize() {
		float len = length();
		(*this) = (*this) * (1 / len);
	}

	Vec3 operator%(const Vec3& rgh) {
		Vec3 result;
		result.x = y * rgh.z - z * rgh.y;
		result.y = - (x * rgh.z - z * rgh.x);
		result.z = x * rgh.y - y *rgh.x;
		return result;
	}

	void debugShow() {
		std::cout << "[ " << x << "   "
			<< y << "   "
			<< z << " ]";
	}
};//end class

class Vec4 {
public:
	float x, y, z, w;
public:
	Vec4(const Vec4 &v) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	Vec4() {
		x = y = z = w = 0;
	}

	Vec4(const Vec3 v) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = 1;
	}

	Vec4(float x, float y,float z,float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vec4(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = 1;
	}

	Vec4& operator=(const Vec4& rgh) {
		this->x = rgh.x;
		this->y = rgh.y;
		this->z = rgh.z;
		this->w = rgh.w;
	}

	Vec4 operator+(const Vec4& rgh) {
		Vec4 result;
		result.x = x + rgh.x;
		result.y = y + rgh.y;
		result.z = z + rgh.z;
		result.w = w + rgh.w;
		return result;
	}

	Vec4& operator+=(const Vec4& rgh) {
		x += rgh.x;
		y += rgh.y;
		z += rgh.z;
		w += rgh.w;
		return *this;
	}

	Vec4 operator-(const Vec4& rgh) {
		Vec4 result;
		result.x = x - rgh.x;
		result.y = y - rgh.y;
		result.z = z - rgh.z;
		result.w = w - rgh.w;
		return result;
	}

	Vec4& operator-=(const Vec4& rgh) {
		x -= rgh.x;
		y -= rgh.y;
		z -= rgh.z;
		w -= rgh.w;
		return *this;
	}

	void debugShow() {
		std::cout << "[ " << x << "   "
			<< y << "   "
			<< z << "   "
			<< w << " ]";
	}

	Vec3 toVec3() {
		return Vec3(x , y ,z);
	}
};//end class

  // Matrix 4x4 matrix
class Mat4 {
public:
	float data[4][4];

public:
	Mat4() {
		data[0][0] = 1;
		data[0][1] = 0;
		data[0][2] = 0;
		data[0][3] = 0;

		data[1][0] = 0;
		data[1][1] = 1;
		data[1][2] = 0;
		data[1][3] = 0;

		data[2][0] = 0;
		data[2][1] = 0;
		data[2][2] = 1;
		data[2][3] = 0;

		data[3][0] = 0;
		data[3][1] = 0;
		data[3][2] = 0;
		data[3][3] = 1;
	}

	Mat4(const Mat4 &mat) {
		data[0][0] = mat.data[0][0];
		data[0][1] = mat.data[0][1];
		data[0][2] = mat.data[0][2];
		data[0][3] = mat.data[0][3];

		data[1][0] = mat.data[1][0];
		data[1][1] = mat.data[1][1];
		data[1][2] = mat.data[1][2];
		data[1][3] = mat.data[1][3];

		data[2][0] = mat.data[2][0];
		data[2][1] = mat.data[2][1];
		data[2][2] = mat.data[2][2];
		data[2][3] = mat.data[2][3];

		data[3][0] = mat.data[3][0];
		data[3][1] = mat.data[3][1];
		data[3][2] = mat.data[3][2];
		data[3][3] = mat.data[3][3];
	}

	inline Mat4& operator=(Mat4& m) {
		data[0][0] = m.data[0][0];
		data[0][1] = m.data[0][1];
		data[0][2] = m.data[0][2];
		data[0][3] = m.data[0][3];

		data[1][0] = m.data[1][0];
		data[1][1] = m.data[1][1];
		data[1][2] = m.data[1][2];
		data[1][3] = m.data[1][3];

		data[2][0] = m.data[2][0];;
		data[2][1] = m.data[2][1];;
		data[2][2] = m.data[2][2];;
		data[2][3] = m.data[2][3];;

		data[3][0] = m.data[3][0];
		data[3][1] = m.data[3][1];
		data[3][2] = m.data[3][2];
		data[3][3] = m.data[3][3];

		return *this;
	}

	inline Mat4 operator+(Mat4& m) {
		Mat4 result;

		result.data[0][0] = data[0][0] + m.data[0][0];
		result.data[0][1] = data[0][1] + m.data[0][1];
		result.data[0][2] = data[0][2] + m.data[0][2];
		result.data[0][3] = data[0][3] + m.data[0][3];

		result.data[1][0] = data[1][0] + m.data[1][0];
		result.data[1][1] = data[1][1] + m.data[1][1];
		result.data[1][2] = data[1][2] + m.data[1][2];
		result.data[1][3] = data[1][3] + m.data[1][3];

		result.data[2][0] = data[2][0] + m.data[2][0];
		result.data[2][1] = data[2][1] + m.data[2][1];
		result.data[2][2] = data[2][2] + m.data[2][2];
		result.data[2][3] = data[2][3] + m.data[2][3];

		result.data[3][0] = data[3][0] + m.data[3][0];
		result.data[3][1] = data[3][1] + m.data[3][1];
		result.data[3][2] = data[3][2] + m.data[3][2];
		result.data[3][3] = data[3][3] + m.data[3][3];

		return result;
	}

	inline Mat4& operator+=(Mat4& m) {
		data[0][0] += m.data[0][0];
		data[0][1] += m.data[0][1];
		data[0][2] += m.data[0][2];
		data[0][3] += m.data[0][3];

		data[1][0] += m.data[1][0];
		data[1][1] += m.data[1][1];
		data[1][2] += m.data[1][2];
		data[1][3] += m.data[1][3];

		data[2][0] += m.data[2][0];
		data[2][1] += m.data[2][1];
		data[2][2] += m.data[2][2];
		data[2][3] += m.data[2][3];

		data[3][0] += m.data[3][0];
		data[3][1] += m.data[3][1];
		data[3][2] += m.data[3][2];
		data[3][3] += m.data[3][3];

		return *this;
	}

	inline Mat4 operator-(Mat4& m) {
		Mat4 result;

		result.data[0][0] = data[0][0] - m.data[0][0];
		result.data[0][1] = data[0][1] - m.data[0][1];
		result.data[0][2] = data[0][2] - m.data[0][2];
		result.data[0][3] = data[0][3] - m.data[0][3];

		result.data[1][0] = data[1][0] - m.data[1][0];
		result.data[1][1] = data[1][1] - m.data[1][1];
		result.data[1][2] = data[1][2] - m.data[1][2];
		result.data[1][3] = data[1][3] - m.data[1][3];

		result.data[2][0] = data[2][0] - m.data[2][0];
		result.data[2][1] = data[2][1] - m.data[2][1];
		result.data[2][2] = data[2][2] - m.data[2][2];
		result.data[2][3] = data[2][3] - m.data[2][3];

		result.data[3][0] = data[3][0] - m.data[3][0];
		result.data[3][1] = data[3][1] - m.data[3][1];
		result.data[3][2] = data[3][2] - m.data[3][2];
		result.data[3][3] = data[3][3] - m.data[3][3];

		return result;
	}

	inline Mat4 operator-=(Mat4& m) {
		data[0][0] -= m.data[0][0];
		data[0][1] -= m.data[0][1];
		data[0][2] -= m.data[0][2];
		data[0][3] -= m.data[0][3];

		data[1][0] -= m.data[1][0];
		data[1][1] -= m.data[1][1];
		data[1][2] -= m.data[1][2];
		data[1][3] -= m.data[1][3];

		data[2][0] -= m.data[2][0];
		data[2][1] -= m.data[2][1];
		data[2][2] -= m.data[2][2];
		data[2][3] -= m.data[2][3];

		data[3][0] -= m.data[3][0];
		data[3][1] -= m.data[3][1];
		data[3][2] -= m.data[3][2];
		data[3][3] -= m.data[3][3];

		return *this;
	}

	inline Mat4 operator*(Mat4& m) {
		Mat4 result;
		float sub_result = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				sub_result = 0;
				for (int k = 0; k < 4; k++) {
					sub_result += data[i][k] * m.data[k][j];
				}//end for k
				result.setValue(i, j, sub_result);
			}//end for j
		}//end for i
		return result;
	}

	inline Mat4& operator*=(Mat4& m) {
		Mat4 result;
		float sub_result = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				sub_result = 0;
				for (int k = 0; k < 4; k++) {
					sub_result += data[i][k] * m.data[k][j];
				}//end for k
				result.setValue(i, j, sub_result);
			}//end for j
		}//end for i

		*this = result;
		return *this;
	}

	inline Mat4 operator*(float value) {
		Mat4 result;
		result.data[0][0] *= value;
		result.data[0][1] *= value;
		result.data[0][2] *= value;
		result.data[0][3] *= value;

		result.data[1][0] *= value;
		result.data[1][1] *= value;
		result.data[1][2] *= value;
		result.data[1][3] *= value;

		result.data[2][0] *= value;
		result.data[2][1] *= value;
		result.data[2][2] *= value;
		result.data[2][3] *= value;

		result.data[3][0] *= value;
		result.data[3][1] *= value;
		result.data[3][2] *= value;
		result.data[3][3] *= value;
		return result;
	}

	inline Mat4& operator*=(float value) {
		data[0][0] *= value;
		data[0][1] *= value;
		data[0][2] *= value;
		data[0][3] *= value;

		data[1][0] *= value;
		data[1][1] *= value;
		data[1][2] *= value;
		data[1][3] *= value;

		data[2][0] *= value;
		data[2][1] *= value;
		data[2][2] *= value;
		data[2][3] *= value;

		data[3][0] *= value;
		data[3][1] *= value;
		data[3][2] *= value;
		data[3][3] *= value;
		return *this;
	}

	inline Vec3 operator*(const Vec3 vec) {
		Vec4 result;
		Vec4 vec4(vec.x , vec.y , vec.z , 1);
		result.x = data[0][0]*  vec4.x + data[0][1] * vec4.y + data[0][2] * vec4.z+ data[0][3] * vec4.w ;
		result.y = data[1][0] * vec4.x + data[1][1] * vec4.y + data[1][2] * vec4.z + data[1][3] * vec4.w;
		result.z = data[2][0] * vec4.x + data[2][1] * vec4.y + data[2][2] * vec4.z + data[2][3] * vec4.w;
		result.w = data[3][0] * vec4.x + data[3][1] * vec4.y + data[3][2] * vec4.z + data[3][3] * vec4.w;

		return result.toVec3();
	}

	void setValue(int row, int col, float value) {
		if (row < 0 || row >3 || col < 0 || col >3) {
			return;
		}

		data[row][col] = value;
	}

	void debugShow() {
		std::cout << "*************************************************************************" << std::endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				std::cout << data[i][j] << "\t";
			}//end for j
			std::cout << std::endl;
		}//end for i
		std::cout << "*************************************************************************" << std::endl;
	}

};//end class