
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
	string myString;

	if (tokens.size() == 1)
	{
		myStream >> tokens[0];
	}
	while (true)
	{
		myStream >> myString;
		if (myStream) tokens.push_back(myString);
		else break;
	}

	tokens.push_back("\n");
	return unsigned int(tokens.size());
}

void analyzeTokens(const vector<string>& tokens)
{
	string::iterator lastLetter;
	string::iterator letter;
	bool hasInt;
	bool hasLetter;

	for( auto word : tokens)
	{
		lastLetter = word.end() - 1;
		letter = word.begin();

		if (*lastLetter == '\n') {
			cout << "[whitespace]......." << ' ' << " \" \" " << endl;
		}
		else if (*letter == '\"' && *lastLetter == '\"') {
			cout << "[string literal]..." << ' ' << word << endl;
		}
		else
		{
			hasInt = false;
			hasLetter = false;
			while(letter<=lastLetter)
			{
				if (*letter >= '0' && *letter <= '9')
				{
					hasInt = true;
					letter++;
				}
				else if ((*letter >= 'a' && *letter <= 'z')
					|| (*letter >= 'A' && *letter <= 'Z')
					|| (*letter == '_'))
				{
					hasLetter = true;
					letter++;
				}
				else 
				{
					cout << "[unknown].........." << ' ' << word << endl;
					hasInt = false;
					hasLetter = false;
					break;
				}
			}
			if (hasInt && !hasLetter)
				cout << "[integer].........." << ' ' << word << endl;
			else if (hasLetter )
				cout << "[identifier]......." << ' ' << word << endl;
		}
	}
}

#if 0
bool readLine(const string& str);
unsigned int stringToTokensWS(const string& input, const vector<string>& tokens);
void analyzeTokens(const vector<string>& tokens);
#endif


void main() {
	vector<string> tokens(1);
	string str;

	if (!readLine(str))  tokens[0] = "\n";
	else stringToTokensWS(str, tokens);

	do {
		if (!readLine(str)) tokens.push_back("\n");

		else stringToTokensWS(str, tokens);

	} while (userContinues());

	analyzeTokens(tokens);

}

