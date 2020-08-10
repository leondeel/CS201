#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

#include <FL\Fl_Button.H>
#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Box.H>
#include <FL\Fl_Input.H>
#include "..\..\my_standard_library.h"

int main(int argc, char** argv) {

    const int dx = 200;
    const int dy = 33;
    const char * sample = "sample text";
    Fl_Window* window = new Fl_Window(680, 360);


    Fl_Box* infoBox = new Fl_Box(0, 0, dx, dy, "Instructions go here.");
    infoBox->box(FL_UP_BOX);
    infoBox->labelsize(14);
    Fl_Input* stringInput = new Fl_Input(0, 1*dy, dx, dy);
    Fl_Input* stringInput2 = new Fl_Input(0, 2 * dy, dx, dy);
    Fl_Box* outputBox = new Fl_Box(0, 3 * dy, dx, dy, "Output goes here.");
    outputBox->box(FL_UP_BOX);
    outputBox->labelsize(14);
    Fl_Button* truncateButton = new Fl_Button(0, 4 * dy, dx, dy, "Truncate.");
    Fl_Button* quitButton = new Fl_Button(0, 5 * dy, dx, dy, "Quit.");


    window->end();
    window->show(argc, argv);
    return Fl::run();
}
