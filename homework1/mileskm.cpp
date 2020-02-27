#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {

	double miles, km;

	cout << "Enter an amount of miles:  ";
	cin >> miles;
	km = 1.60934 * miles;
	cout << "In kilometers that's " << km << endl;


}
