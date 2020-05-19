#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Labs\lab21\my_standard_library.h";



bool readLine(const string& str) {
	if (str != "") return true;
	return false;
}

#if 1
unsigned int stringToTokensWS(const string& input, const vector<string>& tokens) {

}
#endif


void main() {
	string line = "abc";
	cout << readLine(line) << endl;
	
}
