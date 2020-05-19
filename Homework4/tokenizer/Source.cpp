#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Labs\lab21\my_standard_library.h";


#if 1
bool readLine(const string& str) {
	string line;
	getline(cin, line);
	if (line == str) return true;
	return false;
}
#endif
void main() {
	string line = "abc";
	cout << readLine(line) << endl;
	
}