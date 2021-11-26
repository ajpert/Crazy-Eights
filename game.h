/***********************************************************************************
** Program: game.h
** Author: Andy James
** Date: 4/28/2021
** Description: header file for game.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "deck.h"

using namespace std;
class Game {
    private:
        Deck cards;
        Player players[2];
        Card card;
    public:
        Game();
        Game(string);
        ~Game();
        Deck* get_deck();
        Player* get_player(int);
        void set_pile_card(Card);
        Card get_pile_card();
        void print_pile_card();
        void set_current_suit(int);
        int get_current_rank();
        int get_current_suit();
};

#endif

