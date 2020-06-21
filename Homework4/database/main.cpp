
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"


struct DriverLicense {
	string fullName ="", streetAddress = "", city = "", state = "", eyeColor = "";
	unsigned int zipCode =0, birthDate = 0, issueDate = 0, expirationDate = 0, height = 0, weight = 0, licenseNumber = 0;
	char gender = 'O';

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
#if 1
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
// Instructions for inputRecord are confusing.  Am I supposed to input a new record into the database, 
// or am I supposed to extract a record from the databased and input it into a user-defined place?
// If I am supposed to input a new record into the database, then what is its key supposed to be, 
// and why is the function parameter not a const like in the other functions?  Doesn't the function updateRecord do this anyway?
// If I am supposed to extract a record from the database into the function parameter, why isn't a "key" given as a parameter?
// Doesn't readRecord do this anyway?  What's going on here?
bool inputRecord(DriverLicense& record) {

}
#endif
int main() {
	createRecord("key");
	if (theDatabase.count("key") == 1) {
		theDatabase["key"].birthDate = 12;
		cout << theDatabase["key"].birthDate << endl<< theDatabase["key"].eyeColor<<endl;
	}
	return 0;
}

