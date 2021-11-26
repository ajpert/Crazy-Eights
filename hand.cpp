/***********************************************************************************
** Program: hand.cpp
** Author: Andy James
** Date: 4/28/2021
** Description: defines hand object and functions
** Input: none
** Output: none
************************************************************************************/
#include "hand.h"
#include <iostream>
#include <time.h>


using namespace std;

/****************************************************************************************
** Function: Hand()
** Description: default constuctor, sets cards array to 0 and n cards to 0
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Hand::Hand() {
    cards = NULL;
    n_cards = 0;
}
/****************************************************************************************
** Function: ~Hand()
** Description: destructor, deletes the cards array
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Hand::~Hand() {
    delete [] cards;
}
/****************************************************************************************
** Function: get_n_cards()
** Description: returns the amount of cards in the hand object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return in n_cards
*****************************************************************************************/
int Hand::get_n_cards() {
    return n_cards;
}
/****************************************************************************************
** Function: add_card(Card new_card)
** Description: adds a card object to the cards array
** Parameters: Card new_card
** Pre-Condition: pass in a card object
** Post-Condition: none
*****************************************************************************************/
void Hand::add_card(Card new_card) {
    if(n_cards == 0) {
        n_cards++;
        cards = new Card[n_cards];
        cards[0] = new_card;
    }
    else{
        Card* temp = new Card[n_cards + 1];
        for(int i = 0; i < n_cards; i++) {
            temp[i] = cards[i];
        }
        delete[] cards;
        n_cards++;
        cards = temp;
        cards[n_cards - 1] = new_card;
        //delete[] temp;
    }
   
}
/****************************************************************************************
** Function: remove_card(int index)
** Description: removes card from given index in the cards array
** Parameters: int index
** Pre-Condition: pass in a int for where the array should be popped
** Post-Condition: none
*****************************************************************************************/
void Hand::remove_card(int index) {
    Card* temp = new Card[n_cards - 1];
    int k = 0;
    for(int i = 0; i < n_cards; i++) {
        if(i == index) {
            continue;
        }
        temp[k] = cards[i];
        k++;
    }
        
    delete [] cards;
    n_cards--;
    cards = temp;
}
/****************************************************************************************
** Function: display_hand()
** Description: displays all cards in the cards array
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Hand::display_hand() {
    cout << "1: ";
    cards[0].print_card();
    for(int i = 1; i < n_cards; i++) {
        cout << ",";
        cout << i + 1 << ": ";
        cards[i].print_card();
    }
    cout << endl;
}

/****************************************************************************************
** Function: check_hand(Card card)
** Description: checks to see if any card in the hand is equal in any way to a given card
** Parameters: Card card
** Pre-Condition: pass in a card object
** Post-Condition: return true if equal in any way or card rank is 8, false for else
*****************************************************************************************/
bool Hand::check_hand(Card card) {
    for(int i = 0; i < n_cards; i++) {
        if(cards[i].get_rank() == 7) {
            return true;
        }
        if(cards[i].get_suit() == card.get_suit() || cards[i].get_rank() == card.get_rank()) { 
            return true;
        }
    }
    return false;
}
/****************************************************************************************
** Function: get_card(int index)
** Description: gets the card from given index in cards
** Parameters: int index
** Pre-Condition: pass in a int 
** Post-Condition: return the Card object from that index
*****************************************************************************************/
Card Hand::get_card(int index) {
    return cards[index];
}

Hand::Hand(const Hand& old_obj) {
    this->n_cards = old_obj.n_cards;
    this->cards = old_obj.cards;
}

Hand& Hand::operator=(const Hand& h) {
    if(this != &h){
        this->n_cards = h.n_cards;

        if(this->cards != NULL) {
            delete[] this->cards;
        }
        

        this->cards = new Card[this->n_cards];
        for(int i = 0; i < this->n_cards; i++) {
            this->cards[i] = h.cards[i];
        }
    }
    return *this;
}





    



