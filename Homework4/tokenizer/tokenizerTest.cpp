// Homework assignment #4 coded by M. Ariel Hernandez for class Computer Science 201, June 2020
#include "tokenizer.h"

// The following main() satisifies the requirements of Homework # 4.
// For more documentation on what this code accomplishes, refer to the homework assignment.
int main() {
	do {
		vector<string> tokens(1);
		string str;

		cout << "Please type in some text.  You may hit enter to insert a newline.  Type and enter \"end\" when done." << endl;

		if (!readLine(str))  tokens[0] = "\n";
		else stringToTokensWS(str, tokens);

		while (*(tokens.end() - 1) != "End" && *(tokens.end() - 1) != "END" && *(tokens.end() - 1) != "end")
		{
			if (!readLine(str)) tokens.push_back("\n");
			else stringToTokensWS(str, tokens);
		}
		cout << endl;
		analyzeTokens(tokens);

	} while (userContinues());

	return 0;
}

