/***********************************************************************************
** Program: deck.cpp
** Author: Andy James
** Date: 4/28/2021
** Description: defines deck object and functions
** Input: none
** Output: none
************************************************************************************/
#include "deck.h"
#include <iostream>

using namespace std;
/****************************************************************************************
** Function: Deck()
** Description: default constuctor, fills array of cards with 52 cards in order
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Deck::Deck() {
    int count = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            cards[count].set_rank(j);
            cards[count].set_suit(i);
            count++;
        }
    }
    n_cards = 52;
}
Deck::~Deck() {

}
/****************************************************************************************
** Function: get_n_cards()
** Description: returns the number of cards in the deck
** Parameters: none
** Pre-Condition: none
** Post-Condition: return an int of how many cards are left in the deck
*****************************************************************************************/
int Deck::get_n_cards() {
    return n_cards;
}
/****************************************************************************************
** Function: set_n_cards(int n_cards)
** Description: sets n_cards to the passed in value
** Parameters: int n_cards
** Pre-Condition: pass in the new n_cards value
** Post-Condition: none
*****************************************************************************************/
void Deck::set_n_cards(int n_cards) {
    this->n_cards = n_cards; 
}
/****************************************************************************************
** Function: shuffle
** Description: randomizes cards in the deck array
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Deck::shuffle() {
    srand(time(NULL));
    int random = rand()% 52;
    for(int i = 0; i < n_cards; i++) {
      
        //swap(cards[i],cards[random]);
        Card temp;
        temp = cards[i];
        cards[i] = cards[random];
        cards[random] = temp;
        random = rand()% 52;



    }

}
/****************************************************************************************
** Function: print_deck()
** Description: prints out the entire deck
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Deck::print_deck() {
    for(int i = 0; i < n_cards; i++) {
        cards[i].print_card();
    }
}
/****************************************************************************************
** Function: deal_card()
** Description: removes card from deck
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Card Deck::deal_card() {
    n_cards--;
    return cards[52 - n_cards - 1];
}
