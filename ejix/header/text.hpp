#ifndef TEXT
#define TEXT

#include <ncurses.h>
#include <string.h>
const int DARK_PURPLE = {55};
const int DARK_BLUE = {17}; // 17
const int NEON_BLUE = {87}; // 87
const int NEON_PINK = {207}; // 207
const int LIGHTER_BLUE = {20};
void bor (WINDOW* one,int y,int x,const char * text);
void bor2 (WINDOW* one,int y,int x,const char * text);
void tex (WINDOW* one,int y,int x,const char * text);
void tes (WINDOW* one,int y,int x,const char * text);
void tes2 (WINDOW* one,int y,int x,const char * text);
void hor (WINDOW* one,int y,chtype ch,int n,int p);
#endif
