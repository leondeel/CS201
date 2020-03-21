#include "std_lib_facilities.h"


vector<double> quadratic(const double &a, const double &b, const double &c) {
	double discriminant = b*b - 4 * a * c;
	double T = -b / (2 * a);
	//In this case the roots are complex and they are conjugates. 
	//So we only need to communicate the real part and the positive version of the complex part to have all the information we need.
		if (discriminant < 0) {
			return {0, T, sqrt(abs(discriminant)) / (2 * a), };  //I will let 0 indicate that the roots are complex.
	    }
		else {//I will let 1 indicate the roots are real.
			return { 1, T + sqrt(discriminant) / (2 * a), T - sqrt(discriminant) / (2 * a) };
		}
}


void main() {
	do {
		cout << "Let ( a*x^2 + b*x + c ) be  a single-variable polynomial, with variable x, with real coeffcients a,b,c.  Now, please define a,b,c." << endl;
		cout << "a = ";
		double a = getDouble();
		cout << "b = ";
		double b = getDouble();
		cout << "c = ";
		double c = getDouble();
		vector<double> roots = quadratic(a, b, c);
		if (roots[0] == 0) {
			cout << "The roots of this polynomial are two complex conjugates." << endl;
		}
		else {
			cout << "Your roots are " << roots[1] << " and " << roots[2] << endl;
		}
	} while (!userWantsToExit());
}