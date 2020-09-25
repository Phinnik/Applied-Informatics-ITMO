//
// Created by Philipp on 24.09.2020.
//

#include "game/Game.h"
#include "game/Graphics.h"
#include "iostream"
using namespace std;


Move getMoveByInput() {
    int x0, y0, x1, y1;
    map<char, int> charToInt = {
            {'a', 0},
            {'b', 1},
            {'c', 2},
            {'d', 3},
            {'e', 4},
            {'f', 5},
            {'g', 6},
            {'h', 7},
    };
    string input;
    cout << "type 'from' coordinate:" << endl;
    cin >> input;
    x0 = charToInt[input[0]];
    y0 = (int)input[1] - 48 - 1; // makes char int

    cout << "type 'to' coordinate:" << endl;
    cin >> input;
    x1 = charToInt[input[0]];
    y1 = (int)input[1] - 48 - 1; // makes char int

    Move move{x0, y0, x1, y1};

    return move;
}

Move makeRandomDecision(Board board) {

    Move move{1,1,1,1};
    return move;
}

Move makeSafeDecision(Board board) {
    Move move{1,1,1,1};
    return move;
}


int main() {
    Board board;
    Graphics graphics;
    int colorTurn = 1;
    bool autoPlay;
    cout << "autoPlay: (1/0)" << endl;
    cin >> autoPlay;

//    board.clear();
//    board.setCell(0, 0, 1, false);
//    board.setCell(1, 1, 2, false);
//    board.setCell(3, 3, 2, false);

    graphics.display(board);


    while (board.gameResult() == 3) {
        if (colorTurn == 1) {
            cout << "white turn" << endl;
        } else {
            cout << "black turn" << endl;
        }
        Move newMove = getMoveByInput();
        if (board.isMoveValid(colorTurn, newMove)) {
            board.makeMove(colorTurn, newMove);
            graphics.display(board);
            while (board.shouldCheckerEat(newMove.x1, newMove.y1)) {
                cout << "eat more" << endl;
                newMove = getMoveByInput();
                board.makeMove(colorTurn, newMove);
                graphics.display(board);
            }
            colorTurn = colorTurn % 2 + 1;
            graphics.display(board);
        }
    }

    if (board.gameResult() == 1) {
        cout << "White won!" << endl;
    } else {
        cout << "Black won!" << endl;
    }



    return 0;
}