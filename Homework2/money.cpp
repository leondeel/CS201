#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::min_element;
using std::istringstream;


void main() {
	vector<string> coins = { 0,0,0,0,0 };
	const vector<string> coinTypes = { "pennies", "nickles", "dimes", "quaters", "half-dollars" };

	for (int i = 0; i < 5; i++) {
		cout << "How many "<< coinTypes[i] << " do you have?" << endl;
		getline(cin, coins[i]);
		istringstream instream(coins[i]);
		int amount;
		instream >> amount; // Read number from line
		while (!instream) // Error check
		{
			cout << "Please only type an INTEGER for the number of " << coinTypes[i] << " you have.  It can be negative if you want." << endl
				<< "How many " << coinTypes[i] << " do you have?" << endl;
			getline(cin, coins[i]);
			istringstream instream(coins[i]);
			int amount;
			instream >> amount; // Read number from line
		}
		}

	cout << "You have " << cents << endl
		<< "You have " << cents / 5 << endl
		<< "You have " << cents / 10 << endl
		<< "You have " << cents / 25 << endl
		<< "You have " << cents / 50 << endl
		<< "The value of all your coins is " << cents << endl;
}

