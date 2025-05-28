#include "funcs.h"
#include <windows.h>

int main() {
SetConsoleOutputCP(65001);
setlocale (LC_ALL, "RU");
    int w, h;
    char** field = nullptr;

    fieldcreate(field, w, h);
    initConfig(field, w, h);

    gameLoop(field, w, h);

    fielddelete(field, h);

cout << "Натисніть Enter, щоб завершити...";
cin.get();  
cin.get();
    return 0;
}