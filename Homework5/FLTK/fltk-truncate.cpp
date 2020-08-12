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
#if 1

static void copyInput(Fl_Widget* w, void* userData) {
   cout << endl << &userData << endl << endl;
}
#endif

int main(int argc, char** argv) {

    Fl_Window* window = new Fl_Window(680, 360);

    const int dx = 200;
    const int dy = 33;

    Fl_Box infoBox (0, 0, dx, dy, "Instructions go here.");
    Fl_Input stringInput(0, 1*dy, dx, dy);
    Fl_Button truncateButton(0, 2 * dy, 2*dx, dy, "Click to display the text you entered.");
    Fl_Button quitButton(0, 3 * dy, dx, dy, "Quit.");
    quitButton.callback(myQuit); 
    // The function I defined above main() is myQuit.  That function gets passed to this so-called
    // "callback function" which is a member function of the object quitButton so that the function myQuit
    // is run every time the user clicks on that button which corresponds to quitButton.
    Fl_Box outputBox(0, 4 * dy, dx, dy, "Output goes here.");

    window->end();
    window->show(argc, argv);
    return Fl::run();

}
