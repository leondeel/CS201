
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"


struct DriverLicense {
	string fullName, streetAddress, city, state, eyeColor;
	unsigned int zipCode, birthDate, issueDate, expirationDate, height, weight, licenseNumber;
	char gender;

};

map<string, DriverLicense> theDatabase;

#if 0
bool createRecord(const string& key);
bool readRecord(const string& key, DriverLicense& record);
bool updateRecord(const string& key, const DriverLicense& record);
bool deleteRecord(const string& key);
bool inputRecord(DriverLicense& record);
bool printRecord(const string& key);
#endif

bool createRecord(const string& key) {
	if (theDatabase.count("key") == 1 ) return false;
	theDatabase["key"];
	return true;
}
bool readRecord(const string& key, DriverLicense& record) {
	if (theDatabase.count("key") == 0) return false;
	record = theDatabase["key"];
	return true;
}

int main() {
	createRecord("key");
	if (theDatabase.count("key") == 1) {
		theDatabase["key"].birthDate = 12;
		cout << theDatabase["key"].birthDate << endl<< theDatabase["key"].eyeColor<<endl;
	}
	return 0;
}

