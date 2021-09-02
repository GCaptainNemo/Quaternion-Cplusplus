#pragma once
#include <ostream>

template<class T>
class Quaternion 
{
public:
	// methods
	// construction function
	Quaternion(T w_, T x_, T y_, T z_) : w(w_), x(x_), y(y_), z(z_){};
	Quaternion(const T  theta, const T rotate_axis[3]);
	Quaternion():w(0), x(0), y(0), z(0){};;
	Quaternion(Quaternion & B):w(B.w), x(B.x), y(B.y), z(B.z){};

	// operator
	Quaternion operator+(const Quaternion & B);
	Quaternion operator*(const T & val);
	Quaternion operator*(const Quaternion & B);
	Quaternion conjugate();

	// convert to Roderigus vector and rotate matrix
	void ToRotateMatrix(T matrix[3][3]);


	// print
	friend std::ostream &operator<<(std::ostream &stream, const Quaternion &p)
	{
		stream << p.w <<", "<< p.x << ", " << p.y <<", " <<p.z << std::endl;
		return stream;
	}
	T * rotate(const T pos[3]);
	
public:
	// attributes
	T w; T x; T y; T z;
};


