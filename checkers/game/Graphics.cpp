//
// Created by Philipp on 24.09.2020.
//

#include "Graphics.h"
#include "iostream"
using namespace std;

void Graphics::display(Board board) {
    system("cls");
    cout << "------------     ------------- ------------ ------------ ------------ ------------ ------------ ------------ ------------" << endl;
    for (int y = 7; y >= 0; --y) {
        if (y != 7) {
            cout << "------------    ||------------+------------+------------+------------+------------+------------+------------+------------|" << endl;
        }
        for (int row = 0; row < 5; ++row) {
            cout << NumbersStr[y][row] << "    ||";
            for (int x = 0; x < 8; ++x) {
                if (board.getCell(x, y).color == 3) {
                    if ((x + y) % 2 == 0) {
                        cout << CellStr[5][row];
                    } else {
                        cout << CellStr[4][row];
                    }
                } else if (! board.getCell(x, y).isQueen and board.getCell(x, y).color == 1) {
                    cout << CellStr[0][row];
                } else if (board.getCell(x, y).isQueen and board.getCell(x, y).color == 1) {
                    cout << CellStr[1][row];
                } else if (! board.getCell(x, y).isQueen and board.getCell(x, y).color == 2) {
                    cout << CellStr[2][row];
                } else if (board.getCell(x, y).isQueen and board.getCell(x, y).color == 2) {
                    cout << CellStr[3][row];
                }
                cout << "|";
            }
            cout << endl;
        }
    }
    cout << "------------     ------------- ------------ ------------ ------------ ------------ ------------ ------------ ------------" << endl;
    cout << endl;

    for (int row = 0; row < 5; ++row) {
        cout << "                 |";
        for (int x = 0; x < 8; ++x) {
            cout << CharacterStr[x][row];
            cout << "|";
        }
        cout << endl;
    }

}
