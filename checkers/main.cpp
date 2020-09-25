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
    y0 = (int) input[1] - 48 - 1; // makes char int

    cout << "type 'to' coordinate:" << endl;
    cin >> input;
    x1 = charToInt[input[0]];
    y1 = (int) input[1] - 48 - 1; // makes char int

    Move move{x0, y0, x1, y1};

    return move;
}

Move makeDecision1(Board board) {
    Move move;

    // tries to move top checkers
    for (int y = 7; y >= 0; --y) {
        for (int x = 0; x < 8; ++x) {
            if (board.getCell(x, y).color == 1) {
                // try move top right
                for (int i = 1; x + i < 8 and y + i < 8; ++i) {
                    move = {x, y, x + i, y + i};
                    if (board.isMoveValid(1, move)) {
                        return move;
                    }
                }
                // try move top left
                for (int i = 1; x - i >= 0 and y + i < 8; ++i) {
                    move = {x, y, x - i, y + i};
                    if (board.isMoveValid(1, move)) {
                        return move;
                    }
                }
                // try move bottom right
                for (int i = 1; x + i < 8 and y - i >= 0; ++i) {
                    move = {x, y, x + i, y - i};
                    if (board.isMoveValid(1, move)) {
                        return move;
                    }
                }
                // try move bottom left
                for (int i = 1; x - i >= 0 and y - i >= 0; ++i) {
                    move = {x, y, x - i, y - i};
                    if (board.isMoveValid(1, move)) {
                        return move;
                    }
                }
            }
        }
    }

    return move;
}

Move makeDecision2(Board board) {
    Move move;

    // tries to move bottom checkers
    for (int y = 8; y > 0; --y) {
        for (int x = 0; x < 8; ++x) {
            if (board.getCell(x, y).color == 2) {
                // try move top right
                for (int i = 1; x + i < 8 and y + i < 8; ++i) {
                    move = {x, y, x + i, y + i};
                    if (board.isMoveValid(2, move)) {
                        return move;
                    }
                }
                // try move top left
                for (int i = 1; x - i >= 0 and y + i < 8; ++i) {
                    move = {x, y, x - i, y + i};
                    if (board.isMoveValid(2, move)) {
                        return move;
                    }
                }
                // try move bottom right
                for (int i = 1; x + i < 8 and y - i >= 0; ++i) {
                    move = {x, y, x + i, y - i};
                    if (board.isMoveValid(2, move)) {
                        return move;
                    }
                }
                // try move bottom left
                for (int i = 1; x - i >= 0 and y - i >= 0; ++i) {
                    move = {x, y, x - i, y - i};
                    if (board.isMoveValid(2, move)) {
                        return move;
                    }
                }
            }
        }
    }

    return move;
}


int main() {
    Board board;
    Graphics graphics;
    int colorTurn = 1;
    bool autoPlay;
    cout << "autoPlay: (1/0)" << endl;
    cin >> autoPlay;
    graphics.display(board);

    Move newMove;

    while (board.gameResult() == 3) {
        if (colorTurn == 1) {
            cout << "white turn" << endl;
        } else {
            cout << "black turn" << endl;
        }

        if (autoPlay) {
            if (colorTurn == 1) {
                newMove = makeDecision1(board);
            } else {
                newMove = makeDecision2(board);
            }
        } else {
            newMove = getMoveByInput();
        }

        if (board.isMoveValid(colorTurn, newMove)) {
            board.makeMove(colorTurn, newMove);
            graphics.display(board);
            while (board.shouldCheckerEat(newMove.x1, newMove.y1)) {
                cout << "eat more" << endl;
                if (autoPlay) {
                    if (colorTurn == 1) {
                        newMove = makeDecision1(board);
                    } else {
                        newMove = makeDecision2(board);
                    }
                } else {
                    newMove = getMoveByInput();
                }
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