#include "header/text.hpp"
#include <ctype.h>
#include <string.h>
int main ()
{
    WINDOW *screen,*command;
    initscr ();
    start_color ();
// getting len of screen
    int y,x;
    getmaxyx (stdscr,y,x);
// declare new window
    screen = newwin (y-3,x,0,0);
    command = newwin (3,x,y-3,0);
// set background for both screen and command
    #include "header/color.hpp"
    wbkgd (screen,COLOR_PAIR (100) | A_BOLD);
    wbkgd (command,COLOR_PAIR (100) | A_BOLD);
// set box for addition
    box (screen,0,0);
    box (command,0,0);
// refresh the windows
    wnoutrefresh (stdscr);
    wnoutrefresh (screen);
    wnoutrefresh (command);
    doupdate ();
    noecho ();
    curs_set (1);

    int key;
    char message[50]{};
    int index{0};
    int position{1};
    attron (COLOR_PAIR (102) | A_BOLD);
    while (true)
    {
        while (true)
        {
            // move to spesified line
            mvaddstr (y-2,1,message);
            move (y-2,index+1);
            key = getch ();
            
            // checking session
            if (isprint (key) && index < 49 && index < x-4)
                message [index++] = key;
            else if (key==127 && index > 0){
                // delete message and clear char
                message [--index] = '\0';
                mvaddch (y-2,index+1,' '|COLOR_PAIR (100));
            }else if (key==10)
                break;
        }
        if (strcmp (message,"exit")==0)
            break;
        else if (index>0){
            // printing text to screen
            ((position&1)==0) ?
            bor2  (stdscr,position,(x-index)-2,message):
            bor  (stdscr,position,(x-index)-2,message);
            // clearing screen in command
            mvhline (y-2,1,' '|COLOR_PAIR (100),x-2);
            position += 3;
            index = 0;
            // reset message back to normal
            memset (message,'\0',sizeof (message));
        }
    }
    standend ();
    endwin ();
}
