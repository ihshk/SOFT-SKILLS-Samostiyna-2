#include "funcs.h"
#include <windows.h>

void initConfig(char** f, int w, int h) { //користувач задає кількість живих клітин
    int count;
    cout << "Скільки живих клітин ви хочете ввести? ";
    cin >> count;

    for (int i = 0; i < count; i++) { //користувач вводить координати кожної клітини
        int x, y;
        cout << "Клітина #" << i + 1 << " — введіть x y: ";
        cin >> x >> y;

//Перевірка того що координати в межах поля
        if (x >= 0 && x < w && y >= 0 && y < h) {
            f[y][x] = 'o'; //замінює мертву клітину * на живу o
        } else {
            cout << "Невірні координати, ця клітина буде пропущена." << endl;
        }
    }
}

int countAliveSusid(char** f, int x, int y, int w, int h) {
    int count = 0; // лічильник живих сусідів

    //перебирає всі сусідні клітини навколо (x y)
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; 
            //пропускаємо саму клітину (x y)

            int nx = x + dx; //нові координати по x
            int ny = y + dy; //нові координати по y

            //перевірка, чи не виходять координати за межі поля
            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                //перевіряємо, чи ця сусідня клітина жива
                if (f[ny][nx] == 'o') {
                    count++; //якщо клітина жива - додаємо до лічильника
                }
            }
        }
    }

    return count;
}

bool allCellsDead(char** f, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (f[i][j] == 'o') {
                return false; // знайдена хоча б одна жива клітина
            }
        }
    }
    return true; // всі клітини мертві
}

void gameLoop(char**& field, int w, int h) {
    int generation = 0;

    while (true) {
        system("cls"); // очищення екрану

        cout << "Покоління #" << generation << endl;
        fieldout(field, w, h);

        int aliveCount = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (field[i][j] == 'o') aliveCount++;
            }
        }

        cout << "Живих клітин: " << aliveCount << endl;

        if (aliveCount == 0) {
            cout << "Усі клітини мертві. Гру завершено!" << endl;
            break;
        }

        seekAliveCells(field, w, h);
        generation++;

        Sleep(750); // затримка перед наступним поколінням
    }
}