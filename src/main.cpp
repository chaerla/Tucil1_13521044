#include <iostream>
#include "../include/utils.h"

using namespace std;

int main()
{
    cout << endl;
    cout << endl;
    cout << "  .oooo.         .o         .oooooo..o   .oooooo.   ooooo        oooooo     oooo oooooooooooo ooooooooo.\n"
            ".dPooY88b      .d88        d8P'    `Y8  d8P'  `Y8b  `888'         `888.     .8'  `888'     `8 `888   `Y88.\n"
            "      ]8P'   .d'888        Y88bo.      888      888  888           `888.   .8'    888          888   .d88'\n"
            "    .d8P'  .d'  888         `\"Y8888o.  888      888  888            `888. .8'     888oooo8     888ooo88P'\n"
            "  .dP'     88ooo888oo           `\"Y88b 888      888  888             `888.8'      888    \"     888`88b. \n"
            ".oP     .o      888        oo     .d8P `88b    d88'  888       o      `888'       888       o  888  `88b.  \n"
            "8888888888     o888o       88888888P'   `Y8bood8P'  o888ooooood8       `8'       o888ooooood8 o888o  o888o\n"
         << endl;
    cout << "                                        Welcome to 24 Card Game Solver!                                 \n"
            "           24 Card Game is a game where the players are given 4 random cards and they have to           \n"
            "                have to make math expression with those numbers so that it evaluates to 24.             \n"
            "                                     Legal operators : +, -, *, /, () \n";
    menu();
    return 0;
}

