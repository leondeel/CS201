/**
 * @file     L20_Formatted_Output.cpp
 * @author   M. Ariel Hernandez
 * @version  May 5th, 2020
 */

#include "floating_point.hpp"	
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;



int main() {

#if 1
	vector<double> x = degreesToRadians(360);
	
	cout << "degree" << "  " <<"cos(degree)" << std::fixed<<  endl;
	for (size_t i = 0; i < 361; i+=5) {
		cout << std::setw(3) << i << "   " << std::setw(7) << cos(x[i]) << endl;
	}

#endif


	return 0;

}
