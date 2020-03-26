#include "std_lib_facilities.h"
#include <stdexcept>
#include <tuple>
using std::tuple;
using std::get;



tuple<bool, double, double> quadratic(const double& a, const double& b, const double& c) {
	double discriminant = b*b - 4 * a * c;
	double T = -b / (2 * a);
	//In this case the roots are complex and they are conjugates. 
	//So we only need to communicate the real part and the positive version of the imaginary part to have all the information we need.
		if (discriminant < 0) {
			return {false, T, sqrt(abs(discriminant)) / (2 * a), };  //I will let "false" indicate that the roots are complex.
	    }
		else {//I will let "true" indicate the roots are real.
			return { true, T + sqrt(discriminant) / (2 * a), T - sqrt(discriminant) / (2 * a) };
		}
}


void main() {
	do {
		cout << 
			"Let ( a*x^2 + b*x + c ) be a single-variable polynomial, with variable x, with real coeffcients a,b,c.  Now, please define a,b,c." 
			<< endl;
		cout << "a = ";
		double a = getDouble();
		cout << "b = ";
		double b = getDouble();
		cout << "c = ";
		double c = getDouble();

		auto roots = quadratic(a, b, c);

		if (get<0>(roots)) {
			cout << "Your two real roots are " << get<1>(roots) << " and " << get<2>(roots) << endl;
		}
		else {
			cout << "The roots of this polynomial are two complex conjugates:  " << get<1>(roots) << " + i* " 
				<< get<2>(roots) << "  and  "<< get<1>(roots) << " - i* " << get<2>(roots) << endl;
		}
	} while (!userWantsToExit());
}