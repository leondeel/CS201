//Written in March 2020, by M. Ariel Hernandez
// For the "quadratic" portion of homework 3, of CS 201 at UAF.


#include "std_lib_facilities.h"
#include <stdexcept>
#include <tuple>
using std::tuple;
using std::get;


tuple<bool, double, double> quadratic(const double& a, const double& b, const double& c) {
	//The bool output returns "false" if the roots are complex.  The other two outputs are double-types and they return the real roots, or 
	//they return information about the complex roots.

	double discriminant = b*b - 4 * a * c;//  en.wikipedia.org/wiki/Discriminant

	double T = -b / (2 * a);//This part is the real part of the root is the root is complex, 
	//but if the root is real-only, then this part can be used later to get the real root.

//If the roots are complex then they are conjugates because all the coeffcients of the polynomial are real.
//so we only need to communicate the real part and the positive version of the imaginary part to have all the information we need to convey the complex root.
		if (discriminant < 0) {
			return {false, T, sqrt(abs(discriminant)) / (2 * a), };
	    }
		else {//I will let "true" indicate the roots are real.
			return { true, T + sqrt(discriminant) / (2 * a), T - sqrt(discriminant) / (2 * a) };
		}
}


void main() {
	do {//This do-while loop will terminate when the user indicates he wants to stop running the program.
		cout << 
			"Let ( a*x^2 + b*x + c ) be a second-degree, single-variable polynomial, with variable x, with REAL coeffcients a,b,c."<<endl<<
			"  Now, please define a,b,c.  Note that 'a' cannot be zero, or else the polynomial is not second-degree." 
			<< endl;
		double a;
		do {//This do-while loops makes sure that 'a' doesn't equal zero.  if 'a' is zero the quadratic formula fails.
			cout << "a = ";
			//This getDouble function is just like my getInt function, with minor changes.  It wrote it in my header file.
			//It gets a double from the user.
			//There is a bug in getDouble() that acts out from time to time if you type something improper, like just the "enter" button, or just "e".
			//I haven't been able to fix it.  Fixing it may mean re-writting the entire function again from scratch in a much more cumbersome way.
			a = getDouble();
			if (a == 0)
			{
				cout << "Note that 'a' cannot be zero, or else the polynomial is not second-degree.  Please define a,b,c." << endl;
			}
		} while ( a == 0 );
		cout << "b = ";
		double b = getDouble();
		cout << "c = ";
		double c = getDouble();

		auto roots = quadratic(a, b, c);

		if (get<0>(roots)) {
			cout << "Your two real roots are " << get<1>(roots) << " and " << get<2>(roots) << endl<<endl;
		}
		else {
			cout << "The roots of this polynomial are two complex conjugates:  " << get<1>(roots) << " + i* " 
				<< get<2>(roots) << "  and  "<< get<1>(roots) << " - i* " << get<2>(roots) << endl<<endl;
		}
//Yes. We can check to see if the root is true.  I can just uncomment the code below to do that.
//sometimes the computer will correctly approximate the roots, but if the approximate roots don't make the polynomial exactly equal zero,
		// then the commented code below will say that the roots are incorrect, even if they are approximately correct.
#if 0
		if (get<0>(roots)) {
			cout << "(a * (root1 ^ 2 + b * root1 + c) = " << a * get<1>(roots) * get<1>(roots) + b * get<1>(roots) + c << endl;
			if (a * get<1>(roots)* get<1>(roots) + b * get<1>(roots) + c == 0)
				cout << "root 1 works." << endl;
			else cout << "root 1 failed." << endl;
			
			cout <<endl << "(a * (root2 ^ 2 + b * root2 + c) = " << a * get<2>(roots) * get<2>(roots) + b * get<2>(roots) + c << endl;

			if (a * get<2>(roots)* get<2>(roots) + b * get<2>(roots) + c == 0)
				cout << "root 2 works." << endl;
			else cout << "root 2 failed." << endl;
		}
		else {
			cout << 
				"The roots of this polynomial are complex and I would prefer not to invest more energy into something that the assignment does not require."
				<< endl;
		}
#endif
	} while (!userWantsToExit()); //I wrote this userWantstoExit() function in the header file.  It works great.  It is self-explanatory.
}