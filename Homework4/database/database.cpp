// Homework assignment #4 coded by M. Ariel Hernandez for class Computer Science 201, June 2020
#include "database.h"

//ALL of the following code performs EXACTLY according to its description in Homework # 4.
// It's a primitive database manager.
// For more documentation on what these functions accomplish, refer to the homework assignment.
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
					cout<< "Please enter a Driver's License Number (or Driver's License String) for the new record. " 
						<< endl;
					key = getkey();
					if (createRecord(key)) {
						cout <<endl<<
						"You have sucessfuly entered a Driver's License String. Now, do you wish to CREATE a record from " 
						<< endl << 
						"a copy of a previously READ record, or do you wish to write it from scratch?" << endl <<
						"If you wish to write it from scratch, enter \"yes\", " << endl <<
						"else, if you wish to CREATE with a copy (assuming you've already made a copy by using READ), " << endl <<
						"enter anything else that doesn't start with the letter 'y'." << endl;

						if (userYesNo()) {
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
		cout << "Are you still working on this database? ";
	} while (userContinues());
	return 0;
}
