#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include <random>


int main(){
									
	std::random_device seed;		// Source of RANDOM seed.

	std::mt19937 generator(seed()); // Generator for pseudo-random numbers.  
									// The generator is only seeded once at the begninning of main.

	std::uniform_int_distribution<int> distribution(0, 9); //"distribution" will behave as a function that has "generator" as
														   // a parameter, and the "distribution" will RETURN a random integer from 0 to 9.



	return 0;
}