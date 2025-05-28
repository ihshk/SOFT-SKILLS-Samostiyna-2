#ifndef FUNCS2_H
#define FUNCS2_H

#include <iostream>
using namespace std;

void fieldcreate(char**&, int&, int&);
void fieldout(char**, int, int);
void fielddelete(char**, int);
void seekAliveCells(char**, int, int);

bool askRestart();

void initConfig(char** f, int w, int h);
int countAliveSusid(char** f, int x, int y, int w, int h);
bool allCellsDead(char** f, int w, int h);
void gameLoop(char**& field, int w, int h);

#endif