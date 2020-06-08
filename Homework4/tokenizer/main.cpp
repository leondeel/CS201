
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

unsigned int stringToTokensWS(const string& input, vector<string>& tokens) 
{
	istringstream myStream(input);
	unsigned int i = 0;

	while (myStream)
	{
		if (tokens.size() == i) tokens.resize(i+1);
		myStream >> tokens[i];
		cout << tokens[i];
		i++;
	}
	tokens.resize(--i);
	return i;;
}

void analyzeTokens(const vector<string>& tokens)
{

}


#if 0
bool readLine(const string& str);
unsigned int stringToTokensWS(const string& input, const vector<string>& tokens);
void analyzeTokens(const vector<string>& tokens);
#endif


void main() {
	do {

		string str;
		getline(cin, str);
		vector<string> tokens;

	} while (userContinues());
}

