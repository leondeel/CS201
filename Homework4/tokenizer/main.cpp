
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

#if 0
unsigned int stringToTokensWS(const string& input, const vector<string>& tokens) 
{
	istringstream myStream(input);


}
#endif

#if 0
bool readLine(const string& str);
unsigned int stringToTokensWS(const string& input, const vector<string>& tokens);
void analyzeTokens(const vector<string>& tokens);
#endif


void main() {
	do {
		string text("   \n   \t  /r  word x 13 9");
		istringstream instream(text);
		string w;
		string num;
		string c;
		string d;
		bool sign;
		instream >> w;
		sign = !(!(instream));
		cout << sign << endl;
		instream >> c;
		sign = !(!(instream));
		cout << sign << endl; 
		instream>> num;
		sign = !(!(instream));
		cout << sign << endl;
		instream >> d;
		sign = !(!(instream));
		cout << sign << endl;
		cout << w << c << num << d<< endl;
	} while (userContinues());
}

