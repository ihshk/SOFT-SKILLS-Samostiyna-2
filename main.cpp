#include "funcs.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    char **field;
    int w, h;

    fieldcreate(field, w, h);
    fieldout(field, w, h);
    initConfig(field, w, h);

    seekAliveCells(field, w, h);
    fieldout(field, w, h);

    seekAliveCells(field, w, h);
    fieldout(field, w, h);

    fielddelete(field, h);
}