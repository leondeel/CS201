#include "analyzeTokens.h"



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
