// Homework assignment #4 coded by M. Ariel Hernandez for class Computer Science 201, June 2020
#include "..\..\my_standard_library.h"

// All of the following code performs EXACTLY according to its description in Homework # 4.
// This code plays a game called "Bulls and Cows".
// For more documentation on what this accomplishes, refer to the homework assignment.
int main(){

	std::random_device seed;		
	// "seed" returns a RANDOM number when called, 
	// which will be used to prepare a list of pseudo-random numbers.

	std::mt19937 generator(seed()); 
	// "generator" for pseudo-random numbers takes "seed" as a parameter only once.

	std::uniform_int_distribution<unsigned short> distribution('0', '9'); 
	//"distribution" will behave as a function that takes "generator"
    // as a parameter, and the "distribution" will RETURN a random short from 0 to 9
	// every single time "distribuiton" is called with "generator" as the parameter.

	vector<unsigned short> fourDigits(4);  //initializes a vector of 4 of unsigned shorts.
	string userInput;
	unsigned short bulls, cows;

	do {
		fourDigits[0] = (distribution(generator));

		do { fourDigits[1] = (distribution(generator)); } while (fourDigits[1] == fourDigits[0]);

		do { fourDigits[2] = (distribution(generator)); } while (fourDigits[2] == fourDigits[0] ||
																 fourDigits[2] == fourDigits[1] );

		do { fourDigits[3] = (distribution(generator)); } while (fourDigits[3] == fourDigits[0] ||
																 fourDigits[3] == fourDigits[1] ||
																 fourDigits[3] == fourDigits[2] );
		do {
			do {
				cout << "Enter 4 distinct digits:  ";
				getline(cin, userInput);
			} while
				(
					userInput.size() != 4 &&
					(
						userInput[1] == userInput[0] ||
						userInput[2] == userInput[0] ||
						userInput[2] == userInput[1] ||
						userInput[3] == userInput[0] ||
						userInput[3] == userInput[1] ||
						userInput[3] == userInput[2]
						)
					);
			bulls = 0;
			cows = 0;
			for (char i = 0; i < 4; i++) {
				for (char k = 0; k < 4; k++) {
					if (userInput[i] == fourDigits[k]) {
						if (i == k) bulls++;
						else cows++;
					}
				}
			}
			cout << "You got " << bulls << " bulls and " << cows << " cows!" << endl << endl;
		} while (bulls != 4);
		cout << "Congratulations! ";
	} while (userContinues());
	return 0;
}