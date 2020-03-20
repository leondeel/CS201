
#include "std_lib_facilities.h"


double ctok(double c)
{
	if (c < -273.15)
		return -1; //-1 means an error.  Celsius can't go below -273.15.
	else return c + 273.15;
}
int main()
{
	double c;
	do {
		cout << "Enter a temperature in Celcius to convert to Kelvin:  ";
		cin >> c;
		double k = ctok(c);
		while (k == -1) {
			cout << "ERROR. Input must be equal to or greater than -273.15.  Try again:  ";
			cin.clear();
			cin >> c;
			k = ctok(c);
		}
		cout << "Your temperature in kelvin is " << k << " ." << endl;
		cin.clear();
		cin.ignore();
	} while (!userWantsToExit());
}



#if 0
double ctok(double c)
{
	int k = c + 273.15;// "k" should be declared as a double, and that is what should be returned.
	return int; //This is supposed to return the double-type "k", which should be a double, not an int.
}   //Actually, just return "c+273.16", since there is no need to make a variable k in which to save it.
int main()
{
	double c = 0;
	cin >> d;// The letter d should be replaced with the letter c.
	double k = ctok("c");// The string "c" should be replaced with a double: Just the letter c without quotation marks.
	Cout << k << '/n'; //What should be written is "cout", not "Cout".
}
#endif
