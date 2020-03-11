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

void money() {
	vector<int> coins(5);
	const vector<string> coinTypes = { "pennies", "nickles", "dimes", "quaters", "half-dollars" };
	string line;

	for (int i = 0; i < 5; i++) {
		cout << "How many " << coinTypes[i] << " do you have?" << endl;
		getline(cin, line);
		istringstream instream(line);
		instream >> coins[i]; // Read number from line
		while (!instream) // Error check
		{
			cout << "Please type an INTEGER for the number of " << coinTypes[i] << " you have.  It can be negative if you want." << endl
				<< "How many " << coinTypes[i] << " do you have?" << endl;
			getline(cin, line);
			istringstream instream(line);
			instream >> coins[i]; // Read number from line
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << "You have " << coins[i] << ' ' << coinTypes[i] << '.' << endl;
	}
	cout << "The value of all your coins is "
		<< coins[0] + coins[1] * 5 + coins[2] * 10 + coins[3] * 25 + coins[4] * 50 << " cents." << endl;
}


