
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h";


bool readLine(string& str)
{
	getline(cin, str);
	if (str.size() == 0) return false;
	for (auto n: str)
	{
		if (
		     !(n == ' '
			|| n == '/t'
			|| n == '/n'
			|| n == '/v'
			|| n == '/f'
			|| n == '/r')
			) return true;
	}
	return false;
}

unsigned int stringToTokensWS(const string& input, const vector<string>& tokens) 
{
	istringstream myStream(input);


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



