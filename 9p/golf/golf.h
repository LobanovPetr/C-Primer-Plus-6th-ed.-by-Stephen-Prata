#ifndef _GOLF_
#define _GOLF_

#include <iostream>
#include <cstring>

const int Len = 40;
struct golf
{
    char fullname[Len];
    int handicap;
};

void setgolf(golf &, const char* name, int hc); // not interactive
int setgolf(golf &); // interactive, let user to enter name and handicap
                      // return 1 if name was entered return 0 if empty string
void handicap(golf &, int hc);
void showgolf(const golf&);

#endif
