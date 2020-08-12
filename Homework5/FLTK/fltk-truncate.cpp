#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

#include <FL\Fl_Button.H>
#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Box.H>
#include <FL\Fl_Input.H>
#include "..\..\my_standard_library.h"
#include <FL\Enumerations.H> 
#include <FL\Fl_Input_.H>

static void myQuit(Fl_Widget* w, void* userData) {
    exit(1);
}
#if 0
string copyInput(Fl_Widget* w, void* userData) {
    w->Fl_Input_::value();
}
#endif

int main(int argc, char** argv) {

    const int dx = 200;
    const int dy = 33;
    string sample = "sample text";
    char s[4] = { 's', 'a', 'm', '\0' };
    char* ps = &s[0];

    Fl_Window* window = new Fl_Window(680, 360);


    Fl_Box infoBox (0, 0, dx, dy, "Instructions go here.");
 
    Fl_Input stringInput(0, 1*dy, dx, dy);
    Fl_Input stringInput2(0, 2 * dy, dx, dy);
    Fl_Button truncateButton(0, 3 * dy, dx, dy, "Truncate.");
    Fl_Button quitButton(0, 4 * dy, dx, dy, "Quit.");
    quitButton.callback(myQuit);
    Fl_Box outputBox(0, 5 * dy, dx, dy, "Output goes here.");

    window->end();
    window->show(argc, argv);
    return Fl::run();
}
