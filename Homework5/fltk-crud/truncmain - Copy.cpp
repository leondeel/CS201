
//CS201
//Oct. 30, 2019
//Truncate with GUI
#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;
using std::toupper;


#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Double_Window.H>

/**
 * Holds string and info about its length.
 */
struct StringInfo {
	std::string str;
	std::size_t len;
};

// trunc
// (See header for description.)
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




//////////////////////////////////////////////////////////////////////
// C A L L B A C K S /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


//Closes program
void quitButton(Fl_Widget* w, void* userdata)
{
	exit(0);
}

//Opens tutorial
void helpButton(Fl_Widget*, void*)
{
	Fl_Window* window = new Fl_Window(340, 220);
	Fl_Box* box = new Fl_Box(20, 40, 300, 140, "Instructions!\n Enter a string and the amount"
		" of characters\n you'd like to truncate in their respective boxes.\n"
		"***CHARACTERS MUST BE AN INTEGER***\n Then press truncate!\n"
		"Your output will then be shown below.\n"
		"To exit press the quit button.");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(12);
	box->show();
	window->show();
	
}

//Grabs string from input on Truncate button press.
void truncButton(Fl_Widget* w, void* userdata)
{
	//Grabs input from StringInput
	Fl_Button* b = (Fl_Button*)w;
	//StringInput
	Fl_Input* si = (Fl_Input*)b->parent()->child(0);
	//CharInput
	Fl_Input* ci = (Fl_Input*)b->parent()->child(1);


	//string st is stringinput
	string st = si->value();
	//string ch is charinput
	string ch = ci->value();

	//Covnerting the char string to an int for truncate
	int tr;
	istringstream(ch) >> tr;

	//Creating the struct with user
	//inputted string and char length
	StringInfo sz{ st, tr };

	//Grabbing return value from trunc
	StringInfo a = trunc(sz);
	
	//Assigning the truncated string as final ouput
	string finaloutput = a.str;

	//Printing finaloutput to the output box
	//Must be a c style string
	Fl_Output* so = (Fl_Output*)b->parent()->child(4);
	so->value(finaloutput.c_str());
	
	
}



//////////////////////////////////////////////////////////////////////
// F U N C T I O N S /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


Fl_Window* CreateWindow() {

	//Window
	Fl_Double_Window* window = new Fl_Double_Window(606, 392, "Truncate");
	window->resizable(window);

	//String input Child 0
	Fl_Input* StringInput = new Fl_Input(70, 45, 310, 45, "String");
	

	//Char input Child 1
	Fl_Input* CharInput = new Fl_Input(470, 45, 85, 45, "Characters");
	

	//Truncate Button Child 2
	Fl_Button* TruncButton = new Fl_Button(245, 125, 130, 50, "Truncate");
	TruncButton->callback(truncButton);
	

	//Quit Button Child 3
	Fl_Button* QuitButton = new Fl_Button(245, 325, 130, 50, "Quit!");
	QuitButton->callback(quitButton);
	

	//Truncate Output Child 4
	Fl_Output* Output = new Fl_Output(150, 220, 320, 65, "Output");
	

	//Help Button Child 5
	Fl_Button* HelpButton = new Fl_Button(0, 0, 80, 25, "Help");
	HelpButton->callback(helpButton);
	


	window->end();
	return window;

}


int main(int argc, char** argv)
{
	Fl_Window* window = CreateWindow();
	window->end();
	window->show(argc, argv);
	return Fl::run();
}
