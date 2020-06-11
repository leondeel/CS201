
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h";


bool readLine(string& str);
unsigned int stringToTokensWS(const string& input, vector<string>& tokens);
void analyzeTokens(const vector<string>& tokens);



int main() {
	do {
		vector<string> tokens(1);
		string str;

		cout << "Please type in some text.  You may hit enter to insert a newline.  Type and enter \"end \" when done." << endl;

		if (!readLine(str))  tokens[0] = "\n";
		else stringToTokensWS(str, tokens);

		while (*(tokens.end()-1) != "End" && *(tokens.end()-1) != "END" && *(tokens.end()-1) != "end")
		{
			if (!readLine(str)) tokens.push_back("\n");
			else stringToTokensWS(str, tokens);
		}
		cout << endl;
		analyzeTokens(tokens);

	} while (userContinues());
	return 0;
}

