
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\analyzeTokens.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\readLine.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\stringToTokenWS.h"

struct DriverLicense {
	string fullName ="", streetAddress = "", city = "", state = "", eyeColor = "";
	unsigned int zipCode =0, birthDate = 0, issueDate = 0, expirationDate = 0, height = 0, weight = 0, licenseNumber = 0;
	char gender = 'O';
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
		<< theDatabase[key].city << endl << theDatabase[key].state << endl << theDatabase[key].zipCode << endl 
		<< endl
		<< "Birth_Date....... " << theDatabase[key].birthDate << endl 
		<< "Gender .......... " << theDatabase[key].gender 
						   	   << "  ...(Using letters M,F,O, to indicate Male, Female, or Other)"<< endl
		<< "Height .......... " << theDatabase[key].height 
							   << "  ...(Three digit integer: first digit represents feet; last two represent inches)" << endl
		<< "Weight .......... " << theDatabase[key].weight 
							   << "  ...(in pounds)" << endl
		<< "Eye_Color........ " << theDatabase[key].eyeColor << endl 
		<< endl 
		<< "License_Number... " << theDatabase[key].licenseNumber << endl 
		<< "Expiration_Date.. " << theDatabase[key].expirationDate << endl
		<< "Issue_Date....... " << theDatabase[key].issueDate << endl 
		<< endl;
	return true;
}
bool inputRecord(DriverLicense& record) {

	string userInput;
	int i;

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

	do {
		cout << "Enter the 5 digit zip code. ";
		i = (int)(getPosInt());
	} while ( i > 99999 );
	record.zipCode = i;

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

