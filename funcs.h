#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
using namespace std;

void fieldcreate(char**&, int&, int&);
void fieldout(char**, int, int);
void fielddelete(char**, int);
void initConfig(char** f, int w, int h);
int countAliveSusid(char** f, int x, int y, int w, int h);

void testandrii();
void testihor();

#endif