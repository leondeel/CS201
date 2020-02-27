#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {


	int Input, Greatest;

	cout << "Enter a a sequence of positive integers ending with zero \nI will print the greatest positive integer entered.\nNow enter a positive integer (or enter 0 to end):  ";
	cin >> Input;

	while (cin.fail() || Input < 0) {
		if (cin.fail()) {
			cout << "You didn't enter an integer.  Enter a positive integer (or enter 0 to end):  ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> Input;
		}
		else {
			cout << "You entered a negative integer.  Enter a positive integer (or enter 0 to end):  ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> Input;
		}
	}
	Greatest = Input;

	while (Input != 0) {

		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter a positive integer (or enter 0 to end):  ";
		cin >> Input;

		while (cin.fail() || Input < 0) {
			if (cin.fail()) {
				cout << "You didn't enter an integer.  Enter a positive integer (or enter 0 to end):  ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> Input;
			}
			else {
				cout << "You entered a negative integer.  Enter a positive integer (or enter 0 to end):  ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> Input;

			}
		}
		if (Input > Greatest) {
			Greatest = Input;
		}
	}
	cout << "The greatest integer you entered is " << Greatest << "." << endl;

}

