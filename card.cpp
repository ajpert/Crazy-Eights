/***********************************************************************************
** Program: card.cpp
** Author: Andy James
** Date: 4/28/2021
** Description: class that defines a card object with int rank and int suit
** Input: none
** Output: none
************************************************************************************/
#include "card.h"
#include <iostream>
using namespace std;

/****************************************************************************************
** Function: Card()
** Description: default constuctor, sets all int variables to 0
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Card::Card() {
    rank = 0;
    suit = 0;
}
/****************************************************************************************
** Function: Card(int,int)
** Description: parametrized constructor
** Parameters:  int rank, int suit
** Pre-Condition: pass in two int variables to initilize variables
** Post-Condition: none
*****************************************************************************************/
Card::Card(int rank, int suit) {
    this->rank = rank;
    this->suit = suit;
}
Card::~Card(){
    //cout << "yeeted card" << endl;
}
/****************************************************************************************
** Function: set_rank(int rank)
** Description: sets rank in the object to the passed in value
** Parameters: int rank
** Pre-Condition: pass in a new rank value
** Post-Condition: none
*****************************************************************************************/
void Card::set_rank(int rank) {
    this->rank = rank;
}
/****************************************************************************************
** Function: set_suit(int suit)
** Description: sets suit in the object to the passed in value
** Parameters: int suit
** Pre-Condition: pass in a new suit value
** Post-Condition: none
*****************************************************************************************/
void Card::set_suit(int suit) {
    this->suit = suit;
}
/****************************************************************************************
** Function: get_rank()
** Description: returns int rank
** Parameters: none
** Pre-Condition: none
** Post-Condition: return int rank
*****************************************************************************************/
int Card::get_rank() {
    return rank;
}
/****************************************************************************************
** Function: get_suit()
** Description: returns int suit
** Parameters: none
** Pre-Condition: none
** Post-Condition: return int suit
*****************************************************************************************/
int Card::get_suit() {
    return suit;
}
/****************************************************************************************
** Function: equals(const Card card)
** Description: returns true if the cards are equal in any way or the card is rank 8
** Parameters: const Card card
** Pre-Condition: pass in a const Card object
** Post-Condition: return true if cards have anything equal or the passed in card has rank 8
*****************************************************************************************/
bool Card::equals(const Card card) {
    return (rank == card.rank || suit == card.suit || rank == 7);
}
/****************************************************************************************
** Function: print_card()
** Description: prints out the card
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Card::print_card() {
    if(rank == 0) {
        cout << "ace";
    }
    else if(rank < 10) {
        cout << rank + 1;
    }
    else if(rank == 10) {
        cout << "jack";
    }
    else if(rank == 11) {
        cout << "queen";
    }
    else if(rank == 12) {
        cout << "king";
    }
    if(suit == 0) {
        cout << " clubs";
    }
    else if(suit == 1) {
        cout << " diamonds";
    }
    else if(suit == 2) {
        cout << " hearts";
    }
    else {
        cout << " spades";
    }
}
