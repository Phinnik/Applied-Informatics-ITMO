//
// Created by Philipp on 24.09.2020.
//

#include <map>
#include "Game.h"
#include "cmath"
#include "iostream"

using namespace std;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Board::Board() {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if ((x + y) % 2 == 0 and y < 3) {
                table[y][x].color = 1;
            } else if ((x + y) % 2 == 0 and y > 4) {
                table[y][x].color = 2;
            } else {
                table[y][x].color = 3;
            }
            table[y][x].isQueen = false;
            table[y][x].isHighlighted = false;
        }
    }
}


void Board::setCell(int x, int y, int color, bool isQueen) {
    table[y][x].color = color;
    table[y][x].isQueen = isQueen;
}

void Board::clear() {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            setCell(x, y, 3);
        }
    }
}

Board::Cell Board::getCell(int x, int y) {
    return table[y][x];
}

bool Board::shouldCheckerEat(int x, int y) {
    Cell checker = getCell(x, y);
    if (!checker.isQueen) {
        if ((x + 2 < 7) and (y + 2 < 7) and getCell(x + 1, y + 1).color != checker.color and
            getCell(x + 1, y + 1).color != 3 and getCell(x + 2, y + 2).color == 3) {
            return true;
        }
        if ((x - 2 >= 0) and (y + 2 < 7) and getCell(x - 1, y + 1).color != checker.color and
            getCell(x - 1, y + 1).color != 3 and getCell(x - 2, y + 2).color == 3) {
            return true;
        }
        if ((x + 2 < 7) and (y - 2 >= 0) and getCell(x + 1, y - 1).color != checker.color and
            getCell(x + 1, y - 1).color != 3 and getCell(x + 2, y - 2).color == 3) {
            return true;
        }
        if ((x - 2 >= 0) and (y - 2 >= 0) and getCell(x - 1, y - 1).color != checker.color and
            getCell(x - 1, y - 1).color != 3 and getCell(x - 2, y - 2).color == 3) {
            return true;
        }
    } else {
        bool checkerOnRoad = false;
        // top right
        for (int i = 1; (x + i + 1 < 7) and (y + i + 1 < 7); ++i) {
            if (getCell(x + i, y + i).color != 3 and
                getCell(x + i, y + i).color != checker.color and
                getCell(x + i + 1, y + i + 1).color == 3) {

                return true;
            } else if (getCell(x + i, y + i).color != 3 and
                       getCell(x + i, y + i).color != checker.color and
                       getCell(x + i + 1, y + i + 1).color != 3) {
                break;
            } else if (getCell(x + i, y + i).color == checker.color) {
                break;
            }
        }

        // TODO: top left
        for (int i = 1; (x - i - 1 >= 0) and (y + i + 1 < 7); ++i) {
            if (getCell(x - i, y + i).color != 3 and
                getCell(x - i, y + i).color != checker.color and
                getCell(x - i - 1, y + i + 1).color == 3) {

                return true;
            } else if (getCell(x - i, y + i).color != 3 and
                       getCell(x - i, y + i).color != checker.color and
                       getCell(x - i - 1, y + i + 1).color != 3) {
                break;
            } else if (getCell(x - i, y + i).color == checker.color) {
                break;
            }
        }

        // TODO: bottom left
        for (int i = 1; (x - i - 1 >= 0) and (y - i - 1 >= 0); ++i) {
            if (getCell(x - i, y - i).color != 3 and
                getCell(x - i, y - i).color != checker.color and
                getCell(x - i - 1, y - i - 1).color == 3) {

                return true;
            } else if (getCell(x - i, y - i).color != 3 and
                       getCell(x - i, y - i).color != checker.color and
                       getCell(x - i - 1, y - i - 1).color != 3) {
                break;
            } else if (getCell(x - i, y - i).color == checker.color) {
                break;
            }
        }

        // TODO: bottom right
        for (int i = 1; (x + i + 1 < 7) and (y - i - 1 >= 0); ++i) {
            if (getCell(x + i, y - i).color != 3 and
                getCell(x + i, y - i).color != checker.color and
                getCell(x + i + 1, y - i - 1).color == 3) {

                return true;
            } else if (getCell(x + i, y - i).color != 3 and
                       getCell(x + i, y - i).color != checker.color and
                       getCell(x + i + 1, y - i - 1).color != 3) {
                break;
            } else if (getCell(x + i, y - i).color == checker.color) {
                break;
            }
        }
    }
    return false;
}


bool Board::shouldPlayerEat(int color) {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (getCell(x, y).color == color) {
                if (shouldCheckerEat(x, y)) {
                    return true;
                }
            }
        }
    }
    return false;
}


bool Board::isEatMoveValid(Move move) {
    Cell checker = getCell(move.x0, move.y0);
    int distance = abs(move.y1 - move.y0);
    int x_vector = (move.x1 - move.x0) / distance;
    int y_vector = (move.y1 - move.y0) / distance;

    int friendlyCheckerCount = 0;
    int enemyCheckerCount = 0;


    for (int i = 1; i < distance; ++i) {
        Cell currentCell = getCell(move.x0 + x_vector * i, move.y0 + y_vector * i);
        if (currentCell.color != 3 and currentCell.color != checker.color) {
            enemyCheckerCount++;
        } else if (currentCell.color != 3 and currentCell.color == checker.color) {
            friendlyCheckerCount++;
        }
    }

    return friendlyCheckerCount == 0 and enemyCheckerCount == 1;
}


bool Board::isMoveValid(int color, Move move) {
    Cell checker = getCell(move.x0, move.y0);

    if (checker.color != color) { // check if player moved !his checker
        return false;
    }
    if (move.x1 < 0 or move.x1 > 7 or move.y1 < 0 or move.y1 > 7) { // check if player moved on table
        return false;
    }
    if (abs(move.x1 - move.x0) != abs(move.y1 - move.y0)) { // check if player moved diagonally
        return false;
    }
    if (getCell(move.x1, move.y1).color != 3) { // check if destination is empty cell
        return false;
    }
    if (!checker.isQueen) { // check regular checker move forward 1 cell
        if (abs(move.y1 - move.y0) > 2) { // check if movement distance is smaller than 2
            return false;
        }
        if ((move.y1 - move.y0 == 1 and checker.color != 1) or
            (move.y1 - move.y0 == -1 and checker.color != 2)) { // check if one step was made forward
            return false;
        }
        if (abs(move.y1 - move.y0) == 2 and !isEatMoveValid(move)) { // check if two steps were made to eat
            return false;
        }

    } else { // check queen checker move
        int distance = abs(move.y1 - move.y0);
        int vector_x = (move.x1 - move.x0) / distance;
        int vector_y = (move.y1 - move.y0) / distance;
        int obstaclesCount = 0;
        for (int i = 1; i < distance; ++i) {
            if (getCell(move.x0 + i * vector_x, move.y0 + i * vector_y).color != 3) {
                obstaclesCount++;
            }
        }
        if (obstaclesCount > 1) {
            return false;
        }
        if (obstaclesCount == 1 and !isEatMoveValid(move)) {
            return false;
        }
    }
    if (shouldPlayerEat(color) and !isEatMoveValid(move)) { // check if player should eat but didn't do it
        return false;
    }

    return true;
}


void Board::makeMove(int color, Move move) {
    if (isMoveValid(color, move)) {
        table[move.y1][move.x1].color = table[move.y0][move.x0].color;
        table[move.y1][move.x1].isQueen = table[move.y0][move.x0].isQueen;
        table[move.y0][move.x0].color = 3;
        table[move.y0][move.x0].isQueen = false;

        if (isEatMoveValid(move)) { // check if someone is eaten
            int distance = abs(move.y1 - move.y0);
            int vector_x = (move.x1 - move.x0) / distance;
            int vector_y = (move.y1 - move.y0) / distance;
            int i = 1;
            while (i < distance) {
                if (table[move.y0 + i * vector_y][move.x0 + i * vector_x].color != 3) {
                    table[move.y0 + i * vector_y][move.x0 + i * vector_x].color = 3;
                    table[move.y0 + i * vector_y][move.x0 + i * vector_x].isQueen = false;
                    break;
                }
                i++;
            }
        }

        if ((table[move.y1][move.x1].color == 1 and move.y1 == 7) or
            (table[move.y1][move.x1].color == 2 and move.y1 == 0)) {
            table[move.y1][move.x1].isQueen = true;
        }
    }
}

int Board::gameResult() {
    int whiteCount = 0;
    int blackCount = 0;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (getCell(x, y).color == 1) {
                whiteCount++;
            } else if (getCell(x, y).color == 2) {
                blackCount++;
            }
        }
    }
    if (whiteCount == 0) {
        return 2;
    } else if (blackCount == 0) {
        return 1;
    } else {
        return 3;
    }
}


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




