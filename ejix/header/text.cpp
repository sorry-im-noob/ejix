#include "text.hpp"
void bor (WINDOW* one,int y,int x,const char * text)
{
    wattron (one,COLOR_PAIR (101) | A_BOLD);
    int len = strlen (text);
    // box session
    mvwhline (one,y,x,ACS_HLINE,len);
    mvwhline (one,y+2,x,ACS_HLINE,len);
    mvwaddch (one,y,x-1,ACS_ULCORNER);
    mvwaddch (one,y,x+len,ACS_URCORNER);
    mvwaddch (one,y+2,x-1,ACS_LLCORNER);
    mvwaddch (one,y+2,x+len,ACS_LRCORNER);
    mvwaddch (one,y+1,x-1,ACS_VLINE);
    mvwaddch (one,y+1,x+len,ACS_VLINE);
    mvwaddstr (one,y+1,x,text);
    wstandend (one);
}

void bor2 (WINDOW* one,int y,int x,const char * text)
{
    //wbkgd (one,COLOR_PAIR (102) | A_BOLD);
    //box (one,0,0);
    wattron (one,COLOR_PAIR (102) | A_BOLD);
    int len = strlen (text);
    // box session
    mvwhline (one,y,x,ACS_HLINE,len);
    mvwhline (one,y+2,x,ACS_HLINE,len);
    mvwaddch (one,y,x-1,ACS_ULCORNER);
    mvwaddch (one,y,x+len,ACS_URCORNER);
    mvwaddch (one,y+2,x-1,ACS_LLCORNER);
    mvwaddch (one,y+2,x+len,ACS_LRCORNER);
    mvwaddch (one,y+1,x-1,ACS_VLINE);
    mvwaddch (one,y+1,x+len,ACS_VLINE);
    mvwaddstr (one,y+1,x,text);
    wstandend (one);
//    touchwin (one);
//    wnoutrefresh (one);
}

void tex (WINDOW* one,int y,int x, const char * text)
{
    wattron (one,COLOR_PAIR (101)); // pink
    mvwaddstr (one,y,x,text);
    wstandend (one);
}

void tes (WINDOW* one,int y,int x,const char * text)
{
    wattron (one,COLOR_PAIR (100)); // blue
    mvwaddstr (one,y,x,text);
    wstandend (one);
}

void hor (WINDOW* one,int y,chtype ch,int n,int p)
{
    mvwhline (one,y,1,ch | COLOR_PAIR (p),n);
}

void tes2 (WINDOW* one,int y,int x,const char * text)
{
    wattron (one,COLOR_PAIR (102)); // lighter blue
    mvwaddstr (one,y,x,text);
    wstandend (one);
}
