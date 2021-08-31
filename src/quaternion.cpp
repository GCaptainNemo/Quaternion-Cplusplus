#include "../include/quaternion.h"
#include <math.h>
#include <iostream>

Quaternion::Quaternion(double w_, double x_, double y_, double z_): w(w_), x(x_), y(y_), z(z_)
{};

Quaternion::Quaternion(double theta, const double rotate_axis[3]) 
{
	// initialize by rotate axis and rotate angle theta:
	// [w, x, y, z] = [pcos(theta / 2), v1 * sin(theta / 2), 
	// v2 * sin(theta / 2), v3 * sin(theta / 2)] 
	double normalize_factor = sqrt(pow(rotate_axis[0], 2) + 
								   pow(rotate_axis[1], 2) +
								   pow(rotate_axis[2], 2));
	this->w = cos(theta / 2);
	this->x = rotate_axis[0] * sin(theta / 2) / normalize_factor;
	this->y = rotate_axis[1] * sin(theta / 2) / normalize_factor;
	this->z = rotate_axis[2] * sin(theta / 2) / normalize_factor;
};

Quaternion::Quaternion(): w(0), x(0), y(0), z(0)
{};

Quaternion::Quaternion(Quaternion & B) : w(B.w), x(B.x), y(B.y), z(B.z)
{};

Quaternion Quaternion::conjugate() 
{
	Quaternion C;
	C.w = this->w;
	C.x = -this->x;
	C.y = -this->y;
	C.z = -this->z;
	return C;
}

double * Quaternion::rotate(const double pos[3]) 
{
	// Use quaternion to rotate pos: new pos = h * p * conjugate(h)
	Quaternion pos_qua(0.0, pos[0], pos[1], pos[2]);
	std::cout << pos_qua;
	Quaternion res = (*this) * pos_qua * (*this).conjugate();
	std::cout << res;

	double * re = new double[3];
	re[0] = res.x;
	re[1] = res.y;
	re[2] = res.z;
	return re;
};


Quaternion Quaternion::operator*(const double & val) 
{
	Quaternion C;
	C.w = this->w * val;
	C.x = this->x * val;
	C.y = this->y * val;
	C.z = this->z * val;
	return C;
};

Quaternion Quaternion::operator*(const Quaternion & B)
{
	Quaternion C;
	C.w = this->w * B.w - this->x * B.x - this->y * B.y - this->z * B.z;
	C.x = this->w * B.x + this->x * B.w + this->y * B.z - this->z * B.y;
	C.y = this->w * B.y + this->y * B.w + this->z * B.x - this->x * B.z;
	C.z = this->w * B.z + this->z * B.w + this->x * B.y - this->y * B.x;
	return C;
};


Quaternion Quaternion::operator+(const Quaternion & B) 
{
	Quaternion C;
	C.w = this->w + B.w;
	C.x = this->x + B.x;
	C.y = this->y + B.y;
	C.z = this->z + B.z;
	return C;
};


//template <typename T>
//Quaternion<T>::Quaternion(T w_, T x_, T y_, T z_) :w(w_), x(x_), y(y_), z(z_) 
//{};
//
//template <class T>
//Quaternion<T> Quaternion<T>::operator+(const Quaternion<T> & B) 
//{
//	Quaternion<T> C;
//	C.w = this->w + B.w;
//	C.x = this->x + B.x;
//	C.y = this->y + B.y;
//	C.z = this->z + B.z;
//	return C;
//};


