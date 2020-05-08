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

#if 0
	vector<double> x = degreesToRadians(360);
	
	cout << "degree" << "  " <<"cos(degree)" << std::fixed<<  endl;
	for (size_t i = 0; i < 181; i+=5) {
		if (cos(x[i]) >= 0) {
			cout << std::setw(3) << i << "    " << std::setw(8) << cos(x[i]) << endl;
		}
		else {
			cout << std::setw(3) << i << "   " << std::setw(8) << cos(x[i]) << endl;
		}
	}

#endif

#if 1
	vector<double> x = degreesToRadians(360);

	cout << "degree" << "  " << "cos(degree)" << std::fixed << endl;
	for (size_t i = 0; i < 181; i += 5) {
		if (cos(x[i]) >= 0) {
			cout << std::setw(3) << i << "    " << std::setw(8) << cos(x[i]) << endl;
		}
		else {
			cout << std::setw(3) << i << "   " << std::setw(8) << cos(x[i]) << endl;
		}
	}

#endif

	return 0;

}
