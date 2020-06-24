// Homework assignment #4 coded by M. Ariel Hernandez for class Computer Science 201, June 2020

//#warning tokenizer.h included
#ifndef tokenizer_header
#define tokenizer_header
#include "..\..\my_standard_library.h"

// All of the following functions perform EXACTLY according to their description in Homework # 4.
// For more documentation on what these functions accomplish, refer to the homework assignment.
void analyzeTokens(const vector<string>& tokens);
bool readLine(string& str);
unsigned int stringToTokensWS(const string& input, vector<string>& tokens);

#endif // tokenizer_header
