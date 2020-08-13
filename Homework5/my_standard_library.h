// Coded by M. Ariel Hernandez for class Computer Science 201, June 2020

#ifndef my_standard_library_header
#define my_standard_library_header
//#warning my_standard_library.h included

//Comment out this whole Section of includes when you generate your source units
//If you don't the code file that you genereate will so huge and full functions
//That it will be unreadable!
//You are only interested in debugging you custom includes, so comment out all of
//the C++ standard stuff
#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <random>

using std::bitset;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::min_element;
using std::istringstream;
using std::map;
#endif

// useful functions I often use.
bool userYesNo();
unsigned int getPosInt();
bool userContinues();
long double getDouble();

#endif  // my_standard_library_header
