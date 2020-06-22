
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\readLine.h"


struct DriverLicense {
	string fullName ="", streetAddress = "", city = "", state = "";
};
map<string, DriverLicense> theDatabase;

bool createRecord(const string& key) {
	if (theDatabase.count(key) == 1 ) return false;
	theDatabase[key] = {"a", "b", "c", "d"};
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
	bool contin;
	do {
		contin = false;
		do {
			cout << "Enter a string with no white spaces:  ";
		} while (!(readLine(key)));
		for (auto n : key)
		{
			if (
				n == ' '  || 
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

int main() {
	string key;
	DriverLicense record;

	cout << "Hello! Welcome to My Simple DataBase Manager for Driver's Licenses." << endl;
	do {
		cout << "Would you like to CREATE, READ, UPDATE, or DELETE a record in this database?" << endl;
		do {
			cout << "Please answer only with the lowercase letters c, r, u, d, respectively:  ";
			getline(cin, key);
				
		} while (
			key[0] != 'c' &&
			key[0] != 'r' &&
			key[0] != 'u' &&
			key[0] != 'd'
			);
		cout << endl;
		if (key[0] == 'c') {
			cout << "Alright! So you wish to CREATE a new record." << endl;
				do {
					cout<< "Please enter a Driver's License Number (or Driver's License String) for the new record. " << endl;
					key = getkey();
					if (createRecord(key)) {
						cout <<endl<<
							"You have sucessfuly entered a Driver's License String. Now, do you wish to CREATE a record from " << endl << 
							"a copy of a previously READ record, or do you wish to write it from scratch?" << endl <<
							"If you wish to write it from scratch, enter \"yes\", " << endl <<
							"else, if you wish to CREATE with a copy (assuming you've already made a copy by using READ), " << endl <<
							"enter anything else that doesn't start with the letter 'y'." << endl;

						if (userYesNo) {
							inputRecord(record);
							updateRecord(key, record);
							cout << "A new record has succesfully been created with the License String: " << key << endl << endl;
						}
						else {
							updateRecord(key, record);
							cout << "The record has been successfully updated. Note that if the copy was blank, so is this record now." << endl << endl;
						}
						break;
					}
					cout <<endl<< "That License String already exists! Are you done trying to create a new record? ";
				} while (userContinues());
		}
		else if (key[0] == 'r') {
			cout <<
				"Alright! So you wish to READ a record. " << endl <<
				"(Or you wish to just find a record with a matching key, " << endl <<
				"or copy it to UPDATE another by overwriting the other later with what you just copied.)"
				<< endl;
			do {
				cout << "Please enter a Driver's License Number (or Driver's License String) to search for. " << endl;
				key = getkey();
				if (readRecord(key, record)) {
					cout << endl <<
						"We have found the record with that License String. This record has now been copied, " <<endl<<
						"so you can overwrite another record by doing UPDATE, if you want. " << endl <<
						"Here is what the record you searched for contains: " << endl;
					printRecord(key);
				}
				else {
					cout <<endl<< "That License String doesn't exist! ";
				}
				cout << "Are you done searching for and reading records? ";
			} while (userContinues());
		}
		else if (key[0] == 'u') {
			cout << "Alright! So you wish to UPDATE a record! Now, do you wish to UPDATE a record by overwriting "<<endl<<
				"it from a copy of a previously READ record, or do you wish to re-write it from scratch?" << endl <<
				"If you wish to rewrite it from scratch, enter \"yes\", " << endl <<
				"else, if you wish to UPDATE with a copy (assuming you've already made a copy by using READ), " << endl <<
				"enter anything else that doesn't start with the letter 'y'." << endl;
			if (userYesNo()) {
				cout << "First enter all of the following information with which you will overwrite the record." << endl;
				inputRecord(record);
				cout << "Please enter the Driver's License String whose record you wish to update: " << endl;
				do {
					key = getkey();
					if (updateRecord(key, record)) {
						cout <<endl<< "The record has been successfully updated." << endl;
						break;
					}
					cout <<endl<< "That License String doesn't exist! Are you sure you want to UPDATE a record?" << endl;
				} while (userContinues());
			}
			else {
				cout << "Please enter the Driver's License String whose record you wish to replace with the copy: " << endl;
				do {
					key = getkey();
					if (updateRecord(key, record)) {
						cout <<endl<< "The record has been successfully updated. Note that if the copy was blank, so is this record now." 
							<< endl<<endl;
						break;
					}
					cout << "That License String doesn't exist! Are you sure you want to UPDATE a record?" << endl;
				} while (userContinues());
			}
		}
		else {
			cout << "Alright! So you wish to DELETE a record." << endl
				<< "Please enter the Driver's License String for the record you wish to DELETE. " << endl;
			do {
				key = getkey();
				if (deleteRecord(key)) {
					cout << endl<<"The record has been successfully deleted." << endl;
					break;
				}
				cout << "That License String doesn't exist! Do you still wish to DELETE a record? Yes or no? ";
			} while (userYesNo());
		}
		cout << "Are you done managing the database? ";
	} while (userContinues());
	return 0;
}

