#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")


#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Box.H>
#include <FL\Fl_Input.H>
#include "..\..\my_standard_library.h"

int main(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(680, 360);
    const int dx = 200;
    const int dy = 33;
    string sample = "sample text";

    Fl_Box* box = new Fl_Box(0, 0, dx, dy, "Instructions go here.");
    box->box(FL_UP_BOX);
    //box->labelfont(FL_BOLD + FL_ITALIC);
    box->labelsize(14);
    //box->labeltype(FL_SHADOW_LABEL);
    Fl_Input* stringInput = new Fl_Input(0, 1*dy, dx, dy);




    window->end();
    window->show(argc, argv);
    return Fl::run();
}
