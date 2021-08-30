#include "../include/quaternion.h"
#include <iostream>

int main() 
{
	
	double rotate_angle = 3.1415926 / 2;
	const double axis[3] = { 0.0, 0.0, 1.0 };
	Quaternion rotate_qua(rotate_angle, axis);
	double pos[3] = { 1., 0., 0. };
	double * res = rotate_qua.rotate(pos);
	std::cout << res[0] << res[1] << res[2];
	return 0;
}

