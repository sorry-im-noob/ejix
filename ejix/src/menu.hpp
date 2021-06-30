#ifndef MENU
#define MENU
#include "../header/text.hpp"
#include <cstdlib>
#include <string.h>
using std::rand;
class Menu {
private:
    WINDOW* one;
    //int index;
    int y;
    int x;
    char text [4][50] {"message","friend","add friend","exit"};
    char * author;
    int len;
    int raw {4};
    int num{0};
    int index {0};
    int key{0};
    int position{0};
    //int col {50};
public:
    Menu ();
    ~Menu ();
    void reset ();
    void refresh ();
    void fall ();
    void loop ();
    void reize ();
};

#endif
