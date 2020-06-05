
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h";


bool readLine(string& str)
{
	getline(cin, str);
	if (str.size() == 0) return false;
	return true;
}


#if 0
bool readLine(const string& str);
unsigned int stringToTokensWS(const string& input, const vector<string>& tokens);
void analyzeTokens(const vector<string>& tokens);
#endif


void main() {
	do {
		string str;
		cout << readLine(str) << endl;


	} while (userContinues());
}



