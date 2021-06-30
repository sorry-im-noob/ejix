#include "message.hpp"

Message::Message ():
    one {newwin (0,0,0,0)}
{
    getmaxyx (one,y,x);
    two = derwin (one,y-3,x,0,0);
    thr = derwin (one,3,x,y-3,0);
    msg = derwin (two,y-5,x-2,1,1);
    wbkgd (two,COLOR_PAIR (100) | A_BOLD);
    wbkgd (thr,COLOR_PAIR (100) | A_BOLD);
    wbkgd (msg,COLOR_PAIR (100) | A_BOLD);
    keypad (one,TRUE);
    box (two,0,0);
    box (thr,0,0);
    curs_set (1);
    scrollok (msg,TRUE);
}

void Message::refresh ()
{
    touchwin (one);
    touchwin (msg);
    wnoutrefresh (one);
    wnoutrefresh (msg);
}

void Message::loop ()
{
   this->refresh ();
   bool temp {false};
   while (true)
   {
       while (true)
       {
           wnoutrefresh (msg);
           doupdate ();
           mvwhline (one,y-2,1,' ' | COLOR_PAIR (100),x-2);
           tes (one,y-2,2,myMessage);
           key = wgetch (one);
           if (32 <= key && key <= 126 && index < 49 && index < x-4){
               myMessage [index++] = key;
           }
           else if (key==127 && index > 0){
               myMessage [--index] = '\0';
               mvwaddch (one,y-2,index+2,' ' | COLOR_PAIR (100));
           }
           else if (key==KEY_UP){
               return;
           }
           else if (key == 10 && index > 0){
               break;
           }
       }
       if (position>=y-9) {
           wscrl (msg,4);
           mvwhline (msg,position,1,'-',20);
        }
       (temp)?
       bor (msg,position,2,myMessage):
       bor2 (msg,position,x-(index+3),myMessage);
       if (position < y-9)
           position+=3;
       index = 0;
       temp = !temp;
       memset (&myMessage,'\0',sizeof (myMessage));
   }
}

void Message::reize ()
{
    getmaxyx (stdscr,y,x);
    wresize (one,y,x);
    wresize (two,y-3,x);
    wresize (thr,3,x);
}
