#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")


#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Box.H>
#include <FL\Fl_Input.H>


int main(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(680, 360);
    Fl_Box* box = new Fl_Box(0, 0, 200, 33, "Instructions go here.");
    box->box(FL_UP_BOX);
    //box->labelfont(FL_BOLD + FL_ITALIC);
    box->labelsize(14);
    //box->labeltype(FL_SHADOW_LABEL);
    Fl_Input* stringInput = new Fl_Input(0, 33, 200, 33);




    window->end();
    window->show(argc, argv);
    return Fl::run();
}
