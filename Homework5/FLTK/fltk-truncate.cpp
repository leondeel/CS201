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


    Fl_Box* box = new Fl_Box(0, 0, dx, dy, "Instructions go here.");
    box->box(FL_UP_BOX);
    box->labelsize(14);
    Fl_Input* stringInput = new Fl_Input(0, 1*dy, dx, dy);
    Fl_Input* stringInput2 = new Fl_Input(0, 2 * dy, dx, dy);
    Fl_Box* box2 = new Fl_Box(0, 3 * dy, dx, dy, "Output goes here.");
    box2->box(FL_UP_BOX);
    box2->labelsize(14);
    Fl_Button* button1 = new Fl_Button(0, 4 * dy, dx, dy, "Truncate.");


    window->end();
    window->show(argc, argv);
    return Fl::run();
}
