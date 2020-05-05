/**
 * @file     L12_Floating_Point.cpp
 * @author   M. Ariel Hernandez
 * @version  May 5th, 2020
 * John Quan 
 *
 * Useful trigonometric functions.
 */

#include "floating_point.hpp"	
#include <iostream>

using std::cout;
using std::endl;
using std::vector;



int main() {
	// TODO Turn on "error on warnings" so this doesn't*****************
	// compile.  Make it compile by using std::size_t
	// You can comment this for loop out after that.

#if 0
	vector<int> v { 1, 2, 3, 4, 5 };
	for (std::size_t i = 2; i < v.size(); ++i) {
		++v[i];
		cout << v[i] << endl;
	}	
	cout << endl << endl;

#endif

	// *****************************************************************

	// TODO Declare and initialize a vector of radians by calling*******
	//        degreesToRadians(360).
	//      Print degree,cos(radian),sin(radian) as a comma separated
	//        values (CSV) list.


	// *****************************************************************
#if 1
	vector<double> x = degreesToRadians(360);
	
	cout << "degree" << " , " << "cos" << endl;
	for (size_t i = 0; i < 361; i++) {
		cout << i << " , " << cos(x[i]) << " , " << sin(x[i]) << endl;
	}

#endif

	// For the additional assignment in this lab, I will show that sqrt(73)^2 does not return 73 like it ideally should.

	cout<<endl;

#if 1

	if ( sqrt(73)* sqrt(73) == 73) {
		cout << "Right" << endl;
	}
	else{
		cout << "WRONG!" << endl;
	}

#endif





	return 0;

}
