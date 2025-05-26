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

void seekAliveCells(char** f, int w, int h) {
    char** temp = new char*[h];
    for (int i = 0; i < h; i++) {
        temp[i] = new char[w];
        for (int j = 0; j < w; j++) {
            temp[i][j] = f[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int count = countAliveSusid(temp, j, i, w, h);

            if (temp[i][j] == 'o') {
                if (count < 2 || count > 3) f[i][j] = '*';
            } else {
                if (count == 3) f[i][j] = 'o';
            }
        }
    }

    for (int i = 0; i < h; i++) {
        delete[] temp[i];
    }
    delete[] temp;
}