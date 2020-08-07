#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")


#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Box.H>


int main(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(680, 360);
    Fl_Box* box = new Fl_Box(0, 0, 300, 100, "Hello, World!");
    box->box(FL_UP_BOX);
    //box->labelfont(FL_BOLD + FL_ITALIC);
    box->labelsize(14);
    //box->labeltype(FL_SHADOW_LABEL);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}
