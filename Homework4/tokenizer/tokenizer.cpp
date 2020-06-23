#include "tokenizer.h"

void analyzeTokens(const vector<string>& tokens)
{
	string::iterator lastLetter;
	string::iterator letter;
	bool hasInt;
	bool hasLetter;

	for (auto word : tokens)
	{
		lastLetter = word.end() - 1;
		letter = word.begin();

		if (*lastLetter == '\n')
		{
			cout << "[whitespace]......." << " \"\" " << endl;
		}
		else if (*letter == '\"' && *lastLetter == '\"')
		{
			cout << "[string literal]..." << " \"\\";
			while (letter != lastLetter)
			{
				cout << *letter;
				letter++;
			}
			cout << "\\\"\"" << endl;
		}
		else
		{
			hasInt = false;
			hasLetter = false;
			if (*letter == '-')
			{
				letter++;
				while (letter <= lastLetter)
				{
					if (*letter >= '0' && *letter <= '9')
					{
						letter++;
						hasInt = true;
					}
					else
					{
						cout << "[unknown].........." << " \"" << word << "\"" << endl;
						hasInt = false;
						hasLetter = false;
						break;
					}
				}
			}
			else
			{
				while (letter <= lastLetter)
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
						cout << "[unknown].........." << " \"" << word << "\"" << endl;
						hasInt = false;
						hasLetter = false;
						break;
					}
				}
			}
			if (hasInt && !hasLetter)
				cout << "[integer].........." << " \"" << word << "\"" << endl;
			else if (hasLetter)
				cout << "[identifier]......." << " \"" << word << "\"" << endl;
		}
	}
}

bool readLine(string& str)
{
	getline(cin, str);
	if (str.size() == 0) return false;
	for (auto n : str)
	{
		if (
			!(n == ' '
				|| n == '\t'
				|| n == '\n'
				|| n == '\v'
				|| n == '\f'
				|| n == '\r')
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
		if (tokens[0] == "End" || tokens[0] == "END" || tokens[0] == "end") return (unsigned int)(tokens.size());
	}
	while (true)
	{
		myStream >> myString;
		if (myStream) tokens.push_back(myString);
		else break;
		if (myString.size() == 3)
		{
			if (myString == "End" || myString == "END" || myString == "end") return (unsigned int)(tokens.size());
		}
	}

	tokens.push_back("\n");
	return (unsigned int)(tokens.size());
}


