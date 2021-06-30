#include "menu.hpp"

Menu::Menu ()
    : one {newwin (0,0,0,0)},
      author {new char []{"author: eren jeager"}}
{
    len = strlen (author);
    getmaxyx (stdscr,y,x);
    wbkgd (one,COLOR_PAIR (100) | A_BOLD);
    keypad (one,TRUE);
    wtimeout (one,10);
}

Menu::~Menu ()
{
    delete [] author;
}
void Menu::reset ()
{
    for (int i = 0 ; i < raw ; ++i)
    {
        if (position==i)
            wstandout (one);
        tes (one,(y/4)+(i*4),x/2-10,text [i]);
    }
}

void Menu::refresh ()
{
    touchwin (one);
    wnoutrefresh (one);
}

void Menu::fall ()
{
    mvwaddch (one,num,index,' ' | COLOR_PAIR (100));
    mvwaddch (one,++num,index,author [index] | COLOR_PAIR (101));
    if (num >= y-1){
        num = 0;
        ++index;
    }
    if (index == len)
        index = 0;
    wnoutrefresh (one);
}

void Menu::loop ()
{
    this->refresh ();
    while (true)
    {
        key = wgetch (one);
        this->reset ();
        this->fall ();
        doupdate ();
        switch (key)
        {
            case KEY_UP:
                if (position > 0)
                    --position;
                break;
            case KEY_DOWN:
                if (position < raw-1)
                    ++position;
                break;
            case KEY_RESIZE:
                this->reize ();
                break;
            case 'q':
                return;
        }
    }
}

void Menu::reize ()
{
    wresize (one,0,0);
    getmaxyx (one,y,x);
    werase (one);
}





