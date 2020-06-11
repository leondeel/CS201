#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h";


unsigned int stringToTokensWS(const string& input, vector<string>& tokens) 
{
	istringstream myStream(input);
	string myString;

	if (tokens.size() == 1)
	{
		myStream >> tokens[0];
		if (tokens[0] == "End" || tokens[0] == "END" || tokens[0] == "end") return unsigned int(tokens.size());
	}
	while (true)
	{
		myStream >> myString;
		if (myStream) tokens.push_back(myString);
		else break;
		if (myString.size() == 3)
		{
			if (myString == "End" || myString == "END" || myString == "end") return unsigned int(tokens.size());
		}
	}

	tokens.push_back("\n");
	return unsigned int(tokens.size());
}

