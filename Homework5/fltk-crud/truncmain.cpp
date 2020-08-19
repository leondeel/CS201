
//CS201
//Oct. 30, 2019
//Truncate with GUI
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

std::random_device seed;
// "seed" returns a RANDOM number when called, 
// which will be used to prepare a list of pseudo-random numbers.

std::mt19937 generator(seed());
// "generator" for pseudo-random numbers takes "seed" as a parameter only once upon initialization.

std::uniform_int_distribution<unsigned short> distribution('0', '9');
//"distribution" will behave as a function that takes "generator"
// as a parameter, and the "distribution" will RETURN a random short from 0 to 9
// every single time "distribuiton" is called with "generator" as the parameter.

vector<unsigned short> fourDigits(4);  //initializes a vector of 4 of unsigned shorts.
string userInput;
unsigned short bulls, cows;



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

	do {
		do {
			cout << "Enter 4 distinct digits:  ";
			getline(cin, userInput);
		} while
			(
				userInput.size() == 0 || userInput.size() != 4 &&
				(
					userInput[1] == userInput[0] ||
					userInput[2] == userInput[0] ||
					userInput[2] == userInput[1] ||
					userInput[3] == userInput[0] ||
					userInput[3] == userInput[1] ||
					userInput[3] == userInput[2]
					)
				);
		bulls = 0;
		cows = 0;
		for (char i = 0; i < 4; i++) {
			for (char k = 0; k < 4; k++) {
				if (userInput[i] == fourDigits[k]) {
					if (i == k) bulls++;
					else cows++;
				}
			}
		}
		cout << "You got " << bulls << " bulls and " << cows << " cows!" << endl << endl;
	} while (bulls != 4);
	cout << "Congratulations! You have 4 bulls!";




	//Grabs input from StringInput
	Fl_Button* b = (Fl_Button*)w;
	//StringInput
	Fl_Input* si = (Fl_Input*)b->parent()->child(0);


	//string st is stringinput
	string finaloutput = si->value();
	finaloutput = finaloutput + "You got " + char(bulls) + " bulls and " + char(cows) + " cows!";


	//Printing finaloutput to the output box
	//Must be a c style string
	Fl_Output* so = (Fl_Output*)b->parent()->child(3);
	so->value(finaloutput.c_str());
	
	
}



//////////////////////////////////////////////////////////////////////
// F U N C T I O N S /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


Fl_Window* CreateWindow() {

	//Window
	Fl_Double_Window* window = new Fl_Double_Window(606, 392, "Bulls and Cows");
	window->resizable(window);

	//String input Child 0
	Fl_Input* StringInput = new Fl_Input(70, 45, 310, 45, "Input 4 numbers:");
	

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
