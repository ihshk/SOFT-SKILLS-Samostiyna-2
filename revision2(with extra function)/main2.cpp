#include "funcs2.h"
#include <windows.h>
#include <cctype> // для tolower()

bool askRestart() {
    char answer;
    cout << "Бажаєте почати гру заново? (y/n): ";
    cin >> answer;
    cin.ignore(10000, '\n'); // очищає залишки вводу
    return tolower(answer) == 'y';
}

int main() {
    SetConsoleOutputCP(65001); 
    setlocale(LC_ALL, "RU");   

    do {
        int w, h;
        char** field = nullptr;

        fieldcreate(field, w, h);
        initConfig(field, w, h);
        gameLoop(field, w, h);
        fielddelete(field, h);

        cout << endl;
    } while (askRestart());

    cout << "Дякуємо за гру!" << endl;
    cout << "Натисніть Enter для виходу...";
    cin.get();
    return 0;
}