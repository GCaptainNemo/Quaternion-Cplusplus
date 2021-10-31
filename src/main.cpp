#include "./quaternion.hpp"
#include <iostream>

int main() 
{
	
	double rotate_angle = 3.1415926 / 2;
	const double axis[3] = { 0.0, 0.0, 1.0 };
	Quaternion<double> rotate_qua(rotate_angle, axis);
	double pos[3] = { 1., 0., 0. };
	double * res = rotate_qua.rotate(pos);
	std::cout << "after rotate vec = ";
	std::cout << res[0] << ", " << res[1] << ", " << res[2] << std::endl;
	double rotate_mat[3][3];
	rotate_qua.ToRotateMatrix(rotate_mat);
	for (int i = 0; i < 3; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			printf("%f ,", rotate_mat[i][j]);
		
		}
		printf("\n");
	}
	return 0;
}

