/***********************************************************************************
** Program: deck.h
** Author: Andy James
** Date: 4/28/2021
** Description: header file for deck.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef DECK_H
#define DECK_H

#include "card.h"


class Deck {
  private:
    Card cards[52];
    int n_cards;  // Number of cards remaining in the deck.
  public:
    Deck();
    ~Deck();
    void set_n_cards(int);
    int get_n_cards();
    void shuffle();
    void print_deck();
    Card deal_card();
  // must have constructors, destructor, accessor methods, and mutator methods

};

#endif