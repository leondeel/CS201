#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include <random>


int main(){
									
	std::random_device seed;		// "seed" is a RANDOM number which will be used to prepare a list of pseudo-random numbers.

	std::mt19937 generator(seed()); // Generator for pseudo-random numbers.  
									// The generator is only seeded once at the begninning of main.

	std::uniform_int_distribution<int> distribution(0, 9); //"distribution" will behave as a function that has "generator" as
														   // a parameter, and the "distribution" will RETURN a random int from 0 to 9.
	
	vector<int> fourDigits(4);  //initializes a vector of 4 integers.
	

	do {
		fourDigits[0] = (distribution(generator));

		do { fourDigits[1] = (distribution(generator)); } while (fourDigits[0] == fourDigits[1]);

		do { fourDigits[2] = (distribution(generator)); } while (fourDigits[2] == fourDigits[0] ||
																 fourDigits[2] == fourDigits[1]);

		do { fourDigits[3] = (distribution(generator)); } while (fourDigits[3] == fourDigits[0] ||
																 fourDigits[3] == fourDigits[1] ||
																 fourDigits[3] == fourDigits[2] );





		cout << endl << endl;
	} while (userContinues());

	return 0;
}