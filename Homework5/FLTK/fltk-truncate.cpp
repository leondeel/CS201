#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")
#include "../../my_standard_library.h"
#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Counter.H>

#include <cctype>
using std::toupper;

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

static void myQuit(Fl_Widget* w, void* userData) {
    exit(1);
}
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
