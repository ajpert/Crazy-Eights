/***********************************************************************************
** Program: hand.h
** Author: Andy James
** Date: 4/28/2021
** Description: header file for hand.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef HAND_H
#define HAND_H

#include "card.h"

class Hand {
    private:
        Card* cards;
        int n_cards;
    public:
        Hand();
        ~Hand();
        int get_n_cards();
        void add_card(Card);
        void remove_card(int);
        void display_hand();
        bool check_hand(Card);
        Card get_card(int);
        Hand(const Hand&);
        Hand& operator=(const Hand&);

};

#endif