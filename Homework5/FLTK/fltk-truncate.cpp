#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include "../../my_standard_library.h"
#include <FL/Enumerations.H> 
#include <FL/Fl_Input_.H>
#include <FL/Fl_Output.H>

Fl_Window* window = new Fl_Window(680, 360);

const int dx = 200;
const int dy = 33;

Fl_Box infoBox(0, 0, dx, dy, "Instructions go here.");
Fl_Input stringInput(0, 1 * dy, dx, dy);
Fl_Button truncateButton(0, 2 * dy, 2 * dx, dy, "Click to display the text you entered.");
Fl_Button quitButton(0, 3 * dy, dx, dy, "Quit.");
Fl_Output outputBox(0, 4 * dy, dx, dy);

static void myQuit(Fl_Widget* w, void* userData) {
    exit(1);
}
#if 1
static void display_input(Fl_Widget* w, void* userData)
{
    outputBox.value(stringInput.value());

}

#endif

int main(int argc, char** argv) {

    truncateButton.callback(display_input);
    quitButton.callback(myQuit);
    // The function I defined above main() is myQuit.  That function gets passed to this so-called
    // "callback function" which is a member function of the object quitButton so that the function myQuit
    // is run every time the user clicks on that button which corresponds to quitButton.

    window->end();
    window->show(argc, argv);
    return Fl::run();

}
