//
// Created by Philipp on 24.09.2020.
//

#ifndef CHECKERS_GRAPHICS_H
#define CHECKERS_GRAPHICS_H

#include <map>
#include "Game.h"


class Graphics {
private:
    std::string CharacterStr[8][5] = {
            {
                    "     $$     ",
                    "    $  $    ",
                    "   $    $   ",
                    "  $$$$$$$$  ",
                    "  $      $  "
            },
            {
                    "   $$$      ",
                    "   $  $     ",
                    "   $$$$     ",
                    "   $   $    ",
                    "   $$$$     "
            },
            {
                    "    $$$     ",
                    "   $   $    ",
                    "   $        ",
                    "   $   $    ",
                    "    $$$     "
            },
            {
                    "   $$$$$    ",
                    "   $    $$  ",
                    "   $     $  ",
                    "   $     $  ",
                    "   $$$$$$   "
            },
            {
                    "  $$$$$$    ",
                    "  $         ",
                    "  $$$$$     ",
                    "  $         ",
                    "  $$$$$$    "
            },
            {
                    "  $$$$$$    ",
                    "  $         ",
                    "  $$$$$$    ",
                    "  $         ",
                    "  $         "
            },
            {
                    "   $$$$$    ",
                    "  $         ",
                    "  $  $$$    ",
                    "  $    $$   ",
                    "   $$$$$    "
            },
            {
                    "  $      $  ",
                    "  $      $  ",
                    "  $$$$$$$$  ",
                    "  $      $  ",
                    "  $      $  "
            }

    };
    std::string NumbersStr[8][5] = {
            {
                    "     $$     ",
                    "    $ $     ",
                    "   $  $     ",
                    "      $     ",
                    "      $     "
            },
            {
                    "    $$$     ",
                    "   $   $    ",
                    "     $$     ",
                    "    $       ",
                    "   $$$$$    "
            },
            {
                    "    $$$     ",
                    "   $   $    ",
                    "      $     ",
                    "   $   $    ",
                    "    $$$     "
            },
            {
                    "      $$    ",
                    "     $ $    ",
                    "    $  $    ",
                    "   $$$$$$   ",
                    "       $    "
            },
            {
                    "     $$$    ",
                    "    $       ",
                    "     $$$    ",
                    "        $   ",
                    "     $$$    "
            },
            {
                    "     $$$    ",
                    "    $       ",
                    "    $$$$    ",
                    "    $   $   ",
                    "     $$$    "
            },
            {
                    "   $$$$$$   ",
                    "       $    ",
                    "      $     ",
                    "     $      ",
                    "     $      "
            },
            {
                    "    $$$     ",
                    "   $   $    ",
                    "    $$$     ",
                    "   $   $    ",
                    "    $$$     "
            }};
    std::string CellStr[6][5] = {
            {
                    "   ######   ",
                    " ##      ## ",
                    " #        # ",
                    " ##      ## ",
                    "   ######   "
            },
            {
                    "   ######   ",
                    " #   ~~   # ",
                    " # ~~~~~~ # ",
                    " #   ~~   # ",
                    "   ######   "
            },
            {
                    "   ######   ",
                    " ########## ",
                    " ########## ",
                    " ########## ",
                    "   ######   "
            },
            {
                    "   ######   ",
                    " #  &&&&  # ",
                    " # &&&&&& # ",
                    " #  &&&&  # ",
                    "   ######   "
            },
            {
                    "            ",
                    "            ",
                    "            ",
                    "            ",
                    "            "
            },
            {
                    "............",
                    "............",
                    "............",
                    "............",
                    "............"
            }
    };
public:
    void display(Board board);
};


#endif //CHECKERS_GRAPHICS_H
