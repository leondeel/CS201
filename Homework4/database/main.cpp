
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"


struct DriverLicense {
	string fullName, streetAddress, city, state, eyeColor;
	unsigned int zipCode, birthDate, issueDate, expirationDate, height, weight, licenseNumber;
	char gender;

};
#if 0
bool createRecord(const string& key);
bool readRecord(const string& key, DriverLicense& record);
bool updateRecord(const string& key, const DriverLicense& record);
bool deleteRecord(const string& key);
bool inputRecord(DriverLicense& record);
bool printRecord(const string& key);
#endif

map<string, DriverLicense> theDatabase;

bool createRecord(const string& key) {
	if (theDatabase.find("key") != theDatabase.end()) return false;
	theDatabase["key"] = {};
	return true;
}
bool readRecord(const string& key, DriverLicense& record) {
	if (theDatabase.find("key") == theDatabase.end()) return false;
	record = theDatabase["key"];
	return true;
}



int main() {
	theDatabase["key"].birthDate = 12;
	bool a = createRecord("key");
	cout << theDatabase["key"].birthDate << endl<< a;

	return 0;
}

