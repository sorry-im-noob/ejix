#include "../header/text.hpp"
#include "menu.hpp"
#include "message.hpp"

int main ()
{
    initscr ();
    start_color ();
    noecho ();
    curs_set (0);
    #include  "../header/color.hpp"
    //Menu man;
    touchwin (stdscr);
    wnoutrefresh (stdscr);
    //man.loop ();
    Message mes;
    mes.loop ();
    standend ();
    endwin ();
}
