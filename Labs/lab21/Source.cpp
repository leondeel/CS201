/**
 * @file     L21_Trunc_Lab.cpp
 * @author   M. Ariel Hernandez
 * @version  May 12th, 2020
 */

#include "truncstruct.hpp"	
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

void main() 
{
    string str;
    cout << "Enter a string:" << endl << endl;
    std::getline(std::cin, str);
    auto s = trunc8(str);
    cout << s.str << endl << endl << s.len << endl;

}
