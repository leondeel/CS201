// Homework assignment #5 coded by M. Ariel Hernandez for class Computer Science 201, August 2020
// All of the following code performs EXACTLY according to the description in Homework # 5.
// For more documentation on what this code accomplishes, refer to the homework assignment.

#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

#include <string>
using std::string;

#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Counter.H>

#include <cctype>
using std::toupper;

//I HAD NO CHOICE but to use global variables because I have no other idea on how to get this done.
//  I knew of no other way, because the lecture on FLTK was never recorded, so I had to figure it out without
// help.  the website FLTK.ORG was not as helpful as it ought to be for beginners.
//  Because of the global variables I could not get this code to work by including truncstruct.hpp and 
// truncstruct.cpp but instead I had to copy and paste sections of the code above main() and above the functions
 //  that used code from the truncstruct project.  I knew of no other way to make this work.


//  Pasted from truncstruct.cpp and truncstruct.hpp
//************************************************************************************************************
//************************************************************************************************************
struct StringInfo {
    std::string str;
    std::size_t len;
};
StringInfo trunc(const StringInfo& stringInfo) {
    // Get input string & maxlen
    string s = stringInfo.str;
    auto maxlen = stringInfo.len;
    if (maxlen < 0) {
        maxlen = 0;
    }
    // Truncate string & get its new length
    s = s.substr(0, maxlen);
    auto len = (s.size());

    // Convert string to upper-case
    for (std::size_t i = 0; i < len; ++i) {
        s[i] = char(toupper(s[i]));
    }
    // Create return value
    return StringInfo{ s, len };
}
//*************************************************************************************************************



//Initializing global objects
//*************************************************************************************************************
//************************************************************************************************************

Fl_Window* window = new Fl_Window(680, 360);
const int dx = 200;
const int dy = 33;
Fl_Box infoBox(0, 0, 2.5*dx, dy, "Type in some line of text, then pick a number by which to truncate that text.");
Fl_Input stringInput(0, 1 * dy, 2*dx, dy);
Fl_Counter numberInput(0, 2 * dy, dx, dy);
Fl_Button truncateButton(
    0, 3 * dy, 2.5 * dx, dy, "Click to truncate, convert to upper-case, and then display the result.");
Fl_Output outputBox(0, 4 * dy, 2*dx, dy);
Fl_Button quitButton(0, 5 * dy, dx, dy, "Quit.");

//*************************************************************************************************************


// Code for the quit button *******
static void myQuit(Fl_Widget* w, void* userData) {
    exit(1);
}

//  This is the function that uses the global objects and the code from truncstruct  *************************
static void display_input(Fl_Widget* w, void* userData){
    size_t a = numberInput.value();
    StringInfo output{ stringInput.value(), a};
    outputBox.value(&trunc(output).str[0]);
}

int main() {
    truncateButton.callback(display_input);
    quitButton.callback(myQuit);
   // This uses the function I defined above main(), called myQuit.  That function gets passed to this so-called
   // "callback function" which is a member function of the object quitButton so that the function myQuit
   // is run every time the user clicks on that button which corresponds to quitButton.
   // What I just explained also applies to truncateButton.callback(display_input)
    window->end();
    window->show();
    return Fl::run();
}
