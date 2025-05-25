#include "funcs.h"

void fieldcreate(char**& f, int& w, int& h) {
    cout << "Введіть розмір поля в довжину: ";
    cin >> w;

    cout << "Введіть розмір поля в висоту: ";
    cin >> h;

    f = new char*[h];
    for (int i = 0; i < h; i++) {
        f[i] = new char[w];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            f[i][j] = '*';
        }
    }
}

void fieldout(char** f, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

void fielddelete(char** f, int h) {
    for (int i = 0; i < h; i++) {
        delete[] f[i];
    }

    delete[] f;
}

void testandrii() {
    cout << "Hello! (andrii)";
}