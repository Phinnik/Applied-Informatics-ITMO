//
// Created by Philipp on 24.09.2020.
//

#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H


#include <vector>

struct Move {
    int x0;
    int y0;
    int x1;
    int y1;
};



class Board {
private:
    struct Cell {
        int color; // 1 - white, 2 - black, 3 - none
        bool isQueen;
        bool isHighlighted;
    };

    Cell table[8][8];

public:
    Board();

    Cell getCell(int x, int y);

    void setCell(int x, int y, int color, bool isQueen = false);

    void clear();

    bool shouldCheckerEat(int x, int y);

    bool shouldPlayerEat(int color);

    bool isEatMoveValid(Move move);

    bool isMoveValid(int color, Move move);

    void makeMove(int color, Move move);

    int gameResult(); // 1 - white won, 2 - black won, 3 - still playing

};

class Player {

};


class Game {
private:
    Board board;
    Player player1;
    Player player2;
    int turn = 1;
    Move getMove();
public:
    void play();

};


#endif //CHECKERS_GAME_H
