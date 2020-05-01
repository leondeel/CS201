/**
 * @file     L19_Floating_Point.cpp
 * @author   M. Ariel Hernandez
 * @version  Jan 28, 2019
 * John Quan 
 *
 * Useful trigonometric functions.
 */

#include <stdexcept>
#include <tuple>
using std::tuple;


#include "floating_point.hpp"	
#include <iostream>
#include <vector>
// using sin, cos
#include <cmath>
using std::cout;
using std::endl;





int main() {
	// TODO Turn on "error on warnings" so this doesn't*****************
	// compile.  Make it compile by using std::size_t
	// You can comment this for loop out after that.
#if 0
	std::vector<int> v { 1, 2, 3, 4, 5 };
	for (std::size_t i = 2; i < v.size(); ++i) {
		++v[i];
		std::cout << v[i] << std::endl;
	}	
	std::cout << std::endl << std::endl;

	cout << x[2] << " , " << cos(x[2]) << " , " << sin(x[2]) << endl;
#endif

	// *****************************************************************

	// TODO Declare and initialize a vector of radians by calling*******
	//        degreesToRadians(360).
	//      Print degree,cos(radian),sin(radian) as a comma separated
	//        values (CSV) list.


	// *****************************************************************
#if 1
	std::vector<double> x = degreesToRadians(360);
	
	cout << "degree" << " , " << "cos" << " , " << "sin" << endl;
	for (size_t i = 0; i < 361; i++) {
		cout << i << " , " << cos(x[i]) << " , " << sin(x[i]) << endl;
	}

#endif

	// For the additional assignment in this lab, I will 


#if 1

	if( sqrt(73)^2 == 73)




#endif





	return 0;

}
