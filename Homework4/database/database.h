#ifndef database_header
#define database_header
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\my_standard_library.h"
#include "C:\Users\M. Ariel Hernandez\source\repos\cs201\Homework4\tokenizer\readLine.h"


struct DriverLicense {
	string fullName = "", streetAddress = "", city = "", state = "";
};

bool createRecord(const string& key);
bool readRecord(const string& key, DriverLicense& record);
bool updateRecord(const string& key, const DriverLicense& record);
bool deleteRecord(const string& key);
bool printRecord(const string& key);
bool inputRecord(DriverLicense& record);
string getkey();


#endif
