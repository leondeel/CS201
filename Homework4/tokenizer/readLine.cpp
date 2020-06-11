#ifndef _MY_STANDARD_LIBRARY_
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h";
#endif


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

