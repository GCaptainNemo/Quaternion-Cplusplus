#pragma once
//template <typename T>
#include <ostream>

class Quaternion 
{
public:
	// methods
	// construction function
	Quaternion(double w , double x, double y, double z);
	Quaternion(double theta, const double rotate_axis[3]);
	Quaternion();
	Quaternion(Quaternion & B);

	// operator
	Quaternion operator+(const Quaternion & B);
	Quaternion operator*(const double & val);
	Quaternion operator*(const Quaternion & B);
	Quaternion conjugate();

	// convert to Roderigus vector and rotate matrix
	void ToRotateMatrix(double matrix[3][3]);


	// print
	friend std::ostream &operator<<(std::ostream &stream, const Quaternion &p)
	{
		stream << p.w <<", "<< p.x << ", " << p.y <<", " <<p.z << std::endl;
		return stream;
	}
	double * rotate(const double pos[3]);
	
public:
	// attributes
	//T w; T x; T y; T z;
	double w; double x; double y; double z;

	
};


