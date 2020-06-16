#include "readLine.h"




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
