#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::min_element;
using std::istringstream;


void printBox(const string& wordInBoxToPrint, const int& boxLayers);
int getUserInt();
void boxer();
bool userWantsToExit();

void main() {
	
	boxer();

}
