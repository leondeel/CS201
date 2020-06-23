#include "database.h"
map<string, DriverLicense> theDatabase;  //  I think this is a global variable.  But WHY can't I just declare it in the header for database?!


bool createRecord(const string& key) {
	if (theDatabase.count(key) == 1) return false;
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
		<< theDatabase[key].city << endl << theDatabase[key].state << endl << endl;
	return true;
}
bool inputRecord(DriverLicense& record) {
	string userInput;
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

	cout << endl;
	return true;
}
string getkey() {
	string key;
	bool contin;
	do {
		contin = false;
		do {
			cout << "Enter a string with no white spaces:  ";
		} while (!(readLine(key)));
		for (auto n : key)
		{
			if (
				n == ' ' ||
				n == '\t' ||
				n == '\n' ||
				n == '\v' ||
				n == '\f' ||
				n == '\r'
				) contin = true;
		}
	} while (contin);
	return key;
}
