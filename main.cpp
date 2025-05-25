#include "funcs.h"
#include <iostream>
using namespace std;

int main() {
    char **field;
    int w, h;

    fieldcreate(field, w, h);

    fieldout(field, w, h);

    fielddelete(field, h);
}