// Homework assignment #4 coded by M. Ariel Hernandez for class Computer Science 201, June 2020
#ifndef database_header
#define database_header
#include "..\..\my_standard_library.h"
#include "..\tokenizer\readLine.h"

// Struct used for database in Homework # 4
struct DriverLicense {
	string fullName = "", streetAddress = "", city = "", state = "";
};
// Note: except for getKey()
// all of the following functions perform EXACTLY according to their description in Homework # 4.
// For more documentation on what these functions accomplish, refer to the homework assignment.
bool createRecord(const string& key);
bool readRecord(const string& key, DriverLicense& record);
bool updateRecord(const string& key, const DriverLicense& record);
bool deleteRecord(const string& key);
bool printRecord(const string& key);
bool inputRecord(DriverLicense& record);

string getkey();  //Prompts user to enter string with no whitespaces.  This is used as the database key.

#endif
