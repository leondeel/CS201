
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\readLine.h"


struct DriverLicense {
	string fullName ="", streetAddress = "", city = "", state = "";
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
		<< theDatabase[key].city << endl << theDatabase[key].state <<endl<< endl;
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
	bool contin = true;
	do {
		cout << "Enter a string with no white spaces:  ";
		getline(cin, key);
		for (auto n : key)
		{
			if (
				(n == ' '
					|| n == '\t'
					|| n == '\n'
					|| n == '\v'
					|| n == '\f'
					|| n == '\r')
				) contin = false;
		}
	} while (contin);
	return key;
}

int main() {
	string key;
	cout << "Hello! Welcome to My Simple DataBase Manager for Driver's Licenses." << endl;
	do {
		cout << "Would you like to Create, Read, Update, or Delete a record in this database?" << endl;
		do {
			cout << "Please answer only with the letters c, r, u, d, respectively:  ";
			getline(cin, key);
			if (
				key[0] == 'c' ||
				key[0] == 'r' ||
				key[0] == 'u' ||
				key[0] == 'd'
				) break;
		} while (true);

		if (key[0] == 'c') {
			cout << "Alright! So you wish to create a new record." << endl
				<< "Please enter a Driver's License Number (or Driver's License String) for the new record. "<<endl;
				do {
					key = getkey();
					if (createRecord(key)) {

						break;
					}
					cout << "That License String already exists! Are you done trying to create a new record?"<<endl;
				} while (userContinues());
		}

		cout << "Are you done managing the database? ";
	} while (userContinues());
	return 0;
}

