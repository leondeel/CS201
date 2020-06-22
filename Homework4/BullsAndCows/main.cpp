#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include <random>


int main(){

	std::random_device seed;		// "seed" is a RANDOM number which will be used to prepare a list of pseudo-random numbers.

	std::mt19937 generator(seed()); // Generator for pseudo-random numbers.  
									// The generator is only seeded once at the begninning of main.

	std::uniform_int_distribution<unsigned short> distribution('0', '9'); //"distribution" will behave as a function that has "generator" as
														   // a parameter, and the "distribution" will RETURN a random short from 0 to 9.
	
	vector<char> fourDigits(4);  //initializes a vector of 4 characters. I chose type char instead of int because char only takes a byte.
	string userInput;
	unsigned char bulls = 0, cows = 0;

	do {
		fourDigits[0] = (distribution(generator));

		do { fourDigits[1] = (distribution(generator)); } while (fourDigits[1] == fourDigits[0]);

		do { fourDigits[2] = (distribution(generator)); } while (fourDigits[2] == fourDigits[0] ||
																 fourDigits[2] == fourDigits[1] );

		do { fourDigits[3] = (distribution(generator)); } while (fourDigits[3] == fourDigits[0] ||
																 fourDigits[3] == fourDigits[1] ||
																 fourDigits[3] == fourDigits[2] );

		do {
			cout << "Enter 4 distinct digits:  " << fflush;
			getline(cin, userInput);
		} while 
			(
			userInput.size() != 4  &&
				(
				userInput[1] == userInput[0] ||
				userInput[2] == userInput[0] ||
				userInput[2] == userInput[1] ||
				userInput[3] == userInput[0] ||
				userInput[3] == userInput[1] ||
				userInput[3] == userInput[2] 
				)
			);



		cout << endl << endl;
	} while (userContinues());

	return 0;
}