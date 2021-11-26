/***********************************************************************************
** Program: game.cpp
** Author: Andy James
** Date: 4/28/2021
** Description: defines a game object and functions
** Input: none
** Output: none
************************************************************************************/
#include "game.h"
#include <iostream>

using namespace std;

/****************************************************************************************
** Function: Player()
** Description: default constuctor, deals cards to players and sets out a pile card
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Game::Game() {
    for(int i = 0; i < 2; i++) {
        for(int k = 0; k < 7; k++) {
            players[i].get_hand()->add_card(cards.deal_card());
            players[i].set_can_play(true);
        }
    }
    set_pile_card(cards.deal_card());
}
/****************************************************************************************
** Function: Player(string name)
** Description: para constructor, deals cards to players and sets out a pile card, and sets name
** Parameters: string name
** Pre-Condition: pass in a string
** Post-Condition: none
*****************************************************************************************/
Game::Game(string name) {
    cards.shuffle();
    players[0].set_name(name);
    for(int i = 0; i < 2; i++) {
        for(int k = 0; k < 7; k++) {
            players[i].get_hand()->add_card(cards.deal_card());
        }
    }
    set_pile_card(cards.deal_card());
}
Game::~Game() {

}
/****************************************************************************************
** Function: get_deck()
** Description: returns a reference to the Deck object in game
** Parameters: none
** Pre-Condition: none
** Post-Condition: return a deck objectt reference
*****************************************************************************************/
Deck* Game::get_deck() {
    return &cards;
}
/****************************************************************************************
** Function: get_player(int player)
** Description: returns a reference to the player object in game
** Parameters: int player
** Pre-Condition: pass in a int refering to index of player
** Post-Condition: return a player object reference
*****************************************************************************************/
Player* Game::get_player(int player) {
    return &players[player];
}
/****************************************************************************************
** Function: set_pile_card()
** Description: saves last played card (or changed if 8 was played)
** Parameters: Card card
** Pre-Condition: pass in a card object
** Post-Condition: set card to the passed in object
*****************************************************************************************/
void Game::set_pile_card(Card card) {
    this->card = card;
}
/****************************************************************************************
** Function: get_pile_card()
** Description: returns the last played card as a card object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return a card object
*****************************************************************************************/
Card Game::get_pile_card(){
    return card;
}
/****************************************************************************************
** Function: print_pile_card()
** Description: prints out the last played card and deck size
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::print_pile_card() {
    cout << "pile: ";
    card.print_card();
    cout << "|deck size: " << cards.get_n_cards() << endl;

}
/****************************************************************************************
** Function: set_current_suit(int suit)
** Description: changes suit of the last played card
** Parameters: int suit
** Pre-Condition: pass in an int
** Post-Condition: set the card objects suit to int suit
*****************************************************************************************/
void Game::set_current_suit(int suit) {
    card.set_suit(suit);
}
/****************************************************************************************
** Function: get_current_rank()
** Description: returns the current rank of the last card played
** Parameters: none
** Pre-Condition: none
** Post-Condition: return the rank as an in
*****************************************************************************************/
int Game::get_current_rank() {
    return card.get_rank();
}
/****************************************************************************************
** Function: get_current_suit()
** Description: returns the current suit of the last card played
** Parameters: none
** Pre-Condition: none
** Post-Condition: return the suit as an in
*****************************************************************************************/
int Game::get_current_suit() {
    return card.get_suit();
}
 