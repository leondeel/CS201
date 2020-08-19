// Homework assignment #5 coded by M. Ariel Hernandez for class Computer Science 201, August 2020
// All of the following code performs EXACTLY according to the description in Homework # 5.
// For more documentation on what this code accomplishes, refer to the homework assignment.
// This is the additional program that the homework entitles "bulls and cows"

#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

#include "..\my_standard_library.h"
#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Double_Window.H>



//I HAD NO CHOICE but to use global variables because I have no other idea on how to get this done.
//  The lecture on FLTK was never recorded, so I had to figure it out without
// help.  the website FLTK.ORG was not as helpful as it ought to be for beginners.


vector<unsigned short> fourDigits(4);  //initializes a vector of 4 of unsigned shorts.
string userInput;
char bulls =0, cows = 0;
string bu, c;

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
	Fl_Window* window = new Fl_Window(650, 350);
	Fl_Box* box = new Fl_Box(20, 40, 600, 300, "Instructions!\n This program generates a digit string "
		"of unequal numbers chosen from 0 through 9.\nThen you input 4 digits and press the \"guess\" button "
		"to see if you got the right answer.\nYou are awarded a \"bull\" for each digit you correctly guess in"
		" its right location in the string, \n"
		" and you are awarded a cow for each digit you guess in its incorrect location."
		"\nTo exit press the quit button.");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(12);
	box->show();
	window->show();
	
}


void truncButton(Fl_Widget* w, void* userdata)
{
	//Grabs input from StringInput
	Fl_Button* b = (Fl_Button*)w;
	//StringInput
	Fl_Input* si = (Fl_Input*)b->parent()->child(0);


	//string st is stringinput
	userInput = si->value();

		bulls = '0';
		cows = '0';
		for (char i = 0; i < 4; i++) {
			for (char k = 0; k < 4; k++) {
				if (userInput[i] == fourDigits[k]) {
					if (i == k) bulls++;
					else cows++;
				}
			}
		}
		bu = { bulls };
		c = { cows };
	userInput = userInput + "  You got " +  bu  + " bulls and " +  c + " cows!";


	//Printing finaloutput to the output box
	//Must be a c style string
	Fl_Output* so = (Fl_Output*)b->parent()->child(3);
	so->value(userInput.c_str());
}



//////////////////////////////////////////////////////////////////////
// F U N C T I O N S /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


Fl_Window* CreateWindow() {

	//Window
	Fl_Double_Window* window = new Fl_Double_Window(606, 392, "Bulls and Cows");
	window->resizable(window);

	//String input Child 0
	Fl_Input* StringInput = new Fl_Input(155, 45, 310, 45, "Input 4 numbers:");
	

	//Truncate Button Child 1
	Fl_Button* TruncButton = new Fl_Button(245, 125, 130, 50, "Guess");
	TruncButton->callback(truncButton);
	

	//Quit Button Child 2
	Fl_Button* QuitButton = new Fl_Button(245, 325, 130, 50, "Quit!");
	QuitButton->callback(quitButton);
	

	//Truncate Output Child 3
	Fl_Output* Output = new Fl_Output(150, 220, 320, 65, "Output");
	

	//Help Button Child 4
	Fl_Button* HelpButton = new Fl_Button(0, 0, 80, 25, "Help");
	HelpButton->callback(helpButton);
	


	window->end();
	return window;

}


int main(int argc, char** argv)
{
	std::random_device seed;
	// "seed" returns a RANDOM number when called, 
	// which will be used to prepare a list of pseudo-random numbers.

	std::mt19937 generator(seed());
	// "generator" for pseudo-random numbers takes "seed" as a parameter only once upon initialization.

	std::uniform_int_distribution<unsigned short> distribution('0', '9');
	//"distribution" will behave as a function that takes "generator"
	// as a parameter, and the "distribution" will RETURN a random short from 0 to 9
	// every single time "distribuiton" is called with "generator" as the parameter.

	fourDigits[0] = (distribution(generator));

	do { fourDigits[1] = (distribution(generator)); } while (fourDigits[1] == fourDigits[0]);

	do { fourDigits[2] = (distribution(generator)); } while (fourDigits[2] == fourDigits[0] ||
		fourDigits[2] == fourDigits[1]);

	do { fourDigits[3] = (distribution(generator)); } while (fourDigits[3] == fourDigits[0] ||
		fourDigits[3] == fourDigits[1] ||
		fourDigits[3] == fourDigits[2]);

	Fl_Window* window = CreateWindow();
	window->end();
	window->show(argc, argv);
	return Fl::run();
}
