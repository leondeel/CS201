
#include "std_lib_facilities.h"


double ctok()
{
string inputDouble;
		double outputDouble;
		cout << "Enter a temperature in Celsius to convert to Kelvin:  ";
		getline(cin, inputDouble);
		istringstream instream(inputDouble);
		instream >> outputDouble; // Read number from line

		while (!instream || outputDouble < -273.15) // Error check
		{
			cout << "It is physically impossible for anything to be colder than -273.15 Celsius.\nEnter a higher temperature:  ";
			instream.clear();
			instream.ignore();
			getline(cin, inputDouble);
			istringstream instream(inputDouble);
			instream >> outputDouble; // Read number from line
		}
		instream.clear();
		instream.ignore();
		cout << "Thank you!" << endl;
		return outputDouble + 273.15;

}
int main()
{
	double k;
	do {
		k = ctok();
		cout << "Your temperature in kelvin is " << k << " ." << endl;

	} while (!userWantsToExit());
}



#if 0
double ctok(double c)
{
	int k = c + 273.15;// "k" should be declared as a double, and that is what should be returned.
	return int; //This is supposed to return the double-type "k", which should be a double, not an int.
}   //Actually, just return "c+273.15", since there is no need to make a variable k in which to save it.
int main()
{
	double c = 0;
	cin >> d;// The letter d should be replaced with the letter c.
	double k = ctok("c");// The string "c" should be replaced with a double: Just the letter c without quotation marks.
	Cout << k << '/n'; //What should be written is "cout", not "Cout".

	//By the way, this code does not account for the input not being a double.
}
#endif
