
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\analyzeTokens.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\readLine.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\stringToTokenWS.h"

struct DriverLicense {
	string fullName ="", streetAddress = "", city = "", state = "";
	unsigned int  licenseNumber = 0;
};
map<string, DriverLicense> theDatabase;

bool createRecord(const string& key) {
	if (theDatabase.count(key) == 1 ) return false;
	theDatabase[key];
	return true;
}
bool readRecord(const string& key, DriverLicense& record) {
	if (theDatabase.count(key) == 0) return false;
	record = theDatabase[key];
	return true;
}
bool updateRecord(const string& key, const DriverLicense& record) {
	if (theDatabase.count(key) == 0) return false;
	theDatabase[key] = record;
	return true;
}
bool deleteRecord(const string& key) {
	if (theDatabase.count(key) == 0) return false;
	theDatabase.erase(key);
	return true;
}
bool printRecord(const string& key) {
	if (theDatabase.count(key) == 0) return false;
	cout << endl 
		<< theDatabase[key].fullName << endl << theDatabase[key].streetAddress << endl
		<< theDatabase[key].city << endl << theDatabase[key].state <<endl
		<< "License Number: " << theDatabase[key].licenseNumber << endl << endl;
	return true;
}
bool inputRecord(DriverLicense& record) {

	string userInput;
	unsigned int i;
	cout << endl;

	do {
		cout << "Enter full name: ";
	} while (!(readLine(userInput)));
	record.fullName = userInput;

	do {
		cout << "Enter street address: ";
	} while (!(readLine(userInput)));
	record.streetAddress = userInput;

	do {
		cout << "Enter city: ";
	} while (!(readLine(userInput)));
	record.city = userInput;

	do {
		cout << "Enter state: ";
	} while (!(readLine(userInput)));
	record.state = userInput;

	cout << "Enter License number. ";
	i = getPosInt();
	record.licenseNumber = i;

	cout << endl;
	return true;
}

int main() {

	return 0;
}

