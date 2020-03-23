#include "std_lib_facilities.h"
using std::tuple;


tuple<bool, double, double> quadratic(const double& a, const double& b, const double& c) {
	double discriminant = b*b - 4 * a * c;
	double T = -b / (2 * a);
	//In this case the roots are complex and they are conjugates. 
	//So we only need to communicate the real part and the positive version of the complex part to have all the information we need.
		if (discriminant < 0) {
			return {false, T, sqrt(abs(discriminant)) / (2 * a), };  //I will let 0 indicate that the roots are complex.
	    }
		else {//I will let 1 indicate the roots are real.
			return { true, T + sqrt(discriminant) / (2 * a), T - sqrt(discriminant) / (2 * a) };
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

		tuple<bool, double, double>  {isReal, root1, root2} = quadratic(a, b, c);

		if (isReal) {
			cout << "Your two real roots are " << root1 << " and " << root2 << endl;
		}
		else {
			cout << "The roots of this polynomial are two complex conjugates:  "<< root1 << " + " <<root2<< "  and  "<< root1 << " - " << root2 << endl;
		}
	} while (!userWantsToExit());
}