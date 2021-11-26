/***********************************************************************************
** Program: pog.cpp
** Author: Andy James
** Date: 4/28/2021
** Description: program for playing crazy eights against computer
** Input: none
** Output: none
************************************************************************************/
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
int input_check(int);
bool is_num(string num);
void run(string);
void crazy_eight(Game&);
bool hand_has_card(Hand&,Card&);
void run_player(Game&);
void run_computer(Game&);
void get_card(Game&);
bool game_over(Game&);

/****************************************************************************************
** Function: int main()
** Description: gets name from user and repeats game until user ends
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
int main() {
    cout << "\033[2J\033[1;1H"; //clear screen
    string name = "";
    cout << "what is your name: ";
    getline(cin,name);
    string cont = "y";
    while(cont == "y") { //continues until user wants
        run(name);
        cout << "would you like to go again? y for yes else for no: ";
        getline(cin,cont); 
    }

}
/****************************************************************************************
** Function: void run(string name)
** Description: runs the player and computer run functions for crazy eights
** Parameters: string name
** Pre-Condition: pass in a string name for the users name
** Post-Condition: none
*****************************************************************************************/
void run(string name) {
    Game game(name); 
    if(game.get_pile_card().get_rank() == 7) { // if first card delt is an 8
        crazy_eight(game);
    }
    while(true) { //runs until someone wins 
    run_player(game); //runs player
    if(game_over(game)) {
        break;
    }
    cout << "-------------------------------" << endl; //for better formating
    run_computer(game); // runs computer
    if(game_over(game)) {
        break;
    }
    }
}
/****************************************************************************************
** Function: game_over(Game&game)
** Description: checks to see if the game is over or not
** Parameters: Game&game
** Pre-Condition: pass in a game object reference
** Post-Condition: return true if the game is over, false if else
*****************************************************************************************/
bool game_over(Game&game) {
    Hand* hand1 = game.get_player(0)->get_hand();
    Hand* hand2 = game.get_player(1)->get_hand();
    int count = 0;
    for(int i = 0; i < 2; i++) { //if a player is out of cards
        if(game.get_player(i)->get_hand()->get_n_cards() == 0) {
            cout << game.get_player(i)->get_name() << " won" << endl;
            return true;
        }
    }
    for(int i = 0; i < 2; i++) {//if all players cant play
        if(game.get_player(i)->get_can_play() == false) {
            count++;
        }
    }
    if(count == 2) { //determining which has less cards
        if(hand1->get_n_cards() > hand2->get_n_cards()) {
            cout << game.get_player(1)->get_name() << " won" << endl;
            cout << "bonk" << endl;
        }
        else if(hand2->get_n_cards() > hand1->get_n_cards()){
            cout << game.get_player(0)->get_name() << " won" << endl;
        }
        else {
            cout << "tie" << endl;
        }
        return true;
    }
    return false;
}
/****************************************************************************************
** Function: int input_check(int boundary)
** Description: gets a user to enter a number between 1 and in boundary
** Parameters: int boundary
** Pre-Condition: pass in an int for upper boundary
** Post-Condition: return an int of what the user enterd
*****************************************************************************************/
int input_check(int boundary) {
    string input;
    while(true) {
        getline(cin,input);
        if(input.size() != 0 && is_num(input) && (stoi(input) > 0 && stoi(input) <= boundary)) {
            return stoi(input);
        }
        else {
            cout << "enter a number between 1 and " << boundary << ": ";
        }
    }
}
/****************************************************************************************
** Function: is_num(string num)
** Description: checks if the entered string is an int
** Parameters: string num
** Pre-Condition: pass in a string num
** Post-Condition: return true if it is a num, false if else
*****************************************************************************************/
bool is_num(string num) {
    for(int i = 0; i < num.length(); i++) {
        if(isdigit(num[i]) != true) {
            return false;
        }
    }
    return true;

}
/****************************************************************************************
** Function: crazy_eight(Game&game)
** Description: sets suit to users choice if an 8 was played
** Parameters: Game&game
** Pre-Condition: pass in a Game object refernece
** Post-Condition: none
*****************************************************************************************/
void crazy_eight(Game&game) {
    int suit;
    cout << "an 8 was played" << endl;
    cout << "pick 1 for clubs, 2 for diamonds, 3 for hearts, and 4 for spades: ";
    suit = input_check(4);
    game.set_current_suit(suit - 1);
}
/****************************************************************************************
** Function: run_player(Game&game)
** Description: runs the player version of crazy eights with input
** Parameters: Game&game
** Pre-Condition: pass in a Game object refernece
** Post-Condition: none
*****************************************************************************************/
void run_player(Game&game) {
    //setting variables for ease of reading
    Player* player = game.get_player(0);
    Hand* hand = player->get_hand();
    Deck* deck = game.get_deck();
    while(deck->get_n_cards() != 0 && hand->check_hand(game.get_pile_card()) != true) { //if hand has no playable cards
        cout << "dealt card from deck" << endl;
        player->get_hand()->add_card(deck->deal_card());
    }
    if(hand->check_hand(game.get_pile_card())) { // if there is a move
    game.print_pile_card();
    hand->display_hand();
    get_card(game);
    }
    else { // if there is no moves
        cout << "you have no possible moves" << endl;
        player->set_can_play(false);
    }
    
}
/****************************************************************************************
** Function: run_computer(Game&game)
** Description: runs the computer version of crazy eights without input
** Parameters: Game&game
** Pre-Condition: pass in a Game object refernece
** Post-Condition: none
*****************************************************************************************/
void run_computer(Game&game) {
    Player* player2 = game.get_player(1);
    Hand* hand2 = player2->get_hand();
    Deck* deck = game.get_deck();
    //if there are no cards the computer can play
    while(deck->get_n_cards() != 0 && hand2->check_hand(game.get_pile_card()) != true) {
        cout << "computer dealt card from deck" << endl;
        player2->get_hand()->add_card(deck->deal_card());
    }
    //checks if the computer can play
    if(hand2->check_hand(game.get_pile_card())) {
        for(int i = 0; i < hand2->get_n_cards(); i++) {
            if(hand2->get_card(i).equals(game.get_pile_card())) { // if it comes across a playable card
                game.set_pile_card(hand2->get_card(i));
                hand2->remove_card(i);
                cout << "computer played ";
                game.get_pile_card().print_card();
                if(game.get_pile_card().get_rank() == 7 && hand2->get_n_cards() != 0) { // if the card is an 8
                    game.set_current_suit(hand2->get_card(0).get_suit());
                    cout << " and changed to ";
                    game.get_pile_card().print_card();
                }
                
                cout << endl << "computer has " << player2->get_hand()->get_n_cards() << " cards" << endl;
                break;
            }     
        }
    }
    else {
        cout << "computer has no possible moves" << endl;
        player2->set_can_play(false);
    }
}
/****************************************************************************************
** Function: get_card(Game&game)
** Description: gets card that user wants to remove and removes it from hand
** Parameters: Game&game
** Pre-Condition: pass in a Game object refernece
** Post-Condition: none
*****************************************************************************************/
void get_card(Game&game) {
    int index = 0;
    bool b = false;
    Hand* hand = game.get_player(0)->get_hand();
    while(b == false) {
        cout << "which card do you want to play: ";
        index = input_check(hand->get_n_cards()) - 1;
        if(hand->get_card(index).equals(game.get_pile_card())) { // if the card given is equal in any way to the last played card
            game.set_pile_card(hand->get_card(index));
            if(game.get_pile_card().get_rank() == 7) {
                crazy_eight(game);
            }
            hand->remove_card(index);
            //hand->display_hand();
            b = true;
        }
        else {
            cout << "card does not equal suit or rank" << endl;
        }
    }
}



