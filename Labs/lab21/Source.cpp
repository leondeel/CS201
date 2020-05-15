/**
 * @file     L21_Trunc_Lab.cpp
 * @author   M. Ariel Hernandez
 * @version  May 12th, 2020
 */

#include "my_standard_library.h"
#include "truncstruct.hpp"	
#include <iostream>
#include <iomanip>
#include <string>


void main() 
{
    do {
#if 0
        string str;
        cout << "Enter a string:" << endl << endl;
        std::getline(std::cin, str);
        auto s = trunc8(str);
        cout << s.str << endl << endl << s.len << endl;

#endif
#if 1
        string str;
        cout << "Enter a string:" << endl;
        std::getline(std::cin, str);
        size_t k = getUserInt();//this asks the user for an int
        auto s = trunc(StringInfo{ str, k });
        cout <<"RESULT:    "<< s.str << endl <<"LENGTH OF STRING:     "<< s.len << endl;

#endif
    } while (!userWantsToExit());//This function returns a bool indicating if the user wants to restart or not.
}
