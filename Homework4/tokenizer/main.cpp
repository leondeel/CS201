
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
	unsigned int i = tokens.size() - 1;
	while (myStream)
	{
		if (tokens.size() == i+1) tokens.resize(i+2);
		myStream >> tokens[i];
		i++;
	}
	tokens[i] = '\n';
	tokens.resize(i+1);
	return i+1;
}

void analyzeTokens(const vector<string>& tokens)
{
	istringstream myStream();

	int bitmask;
	string::iterator lastLetter;
	string::iterator letter;
	bool hasInt;
	bool hasLetter;

	for( auto word : tokens)
	{
		lastLetter = word.end() - 1;

		if (
			       word[0] == ' '
				|| word[0] == '/t'
				|| word[0] == '/n'
				|| word[0] == '/v'
				|| word[0] == '/f'
				|| word[0] == '/r'
			)  
			cout << "[whitespace]......." << ' ' << " \" \" " << endl;

		else if (word[0] == '\"' &&  *lastLetter == '\"') 
			cout << "[string literal]..." << ' ' << word << endl;

		else
		{
			hasInt = false;
			hasLetter = false;
			letter = word.begin();
			while(letter<lastLetter)
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
	unsigned int i = 0;
	do {
		if (!readLine(str))  tokens[i] = '\n';

		else i= stringToTokensWS(str, tokens) -1;

	} while (userContinues());
	analyzeTokens(tokens);

}

