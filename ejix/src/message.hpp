#ifndef MESSAGE
#define MESSAGE
#include "../header/text.hpp"
class Message {
    private:
        WINDOW* one;
        WINDOW* two;
        WINDOW* thr;
        WINDOW* msg;
        int y;
        int x;
        char myMessage [50]{};
        int index{0};
        int position{0};
        int key;
    public:
        Message ();
        void refresh ();
        void loop ();
        void reize ();
};

#endif
