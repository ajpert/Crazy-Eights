/***********************************************************************************
** Program: player.cpp
** Author: Andy James
** Date: 4/28/2021
** Description: defines player object and functions
** Input: none
** Output: none
************************************************************************************/
#include "player.h"
#include <iostream>

using namespace std;
/****************************************************************************************
** Function: Player()
** Description: default constuctor, sets player name to computer and can_play to true
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Player::Player() {
    name = "computer";
    can_play = true;
}

Player::~Player() {

}
/****************************************************************************************
** Function: Hand(string name)
** Description: para constuctor, sets player name to name and can play to true
** Parameters: string name
** Pre-Condition: pass in a string
** Post-Condition: none
*****************************************************************************************/
void Player::set_name(string name) {
    this->name = name;
    can_play = true;
}
/****************************************************************************************
** Function: get_name()
** Description: returns string name of player object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return string name
*****************************************************************************************/
string Player::get_name() {
    return name;
}
/****************************************************************************************
** Function: get_hand()
** Description: returns the player objects hand object
** Parameters: none
** Pre-Condition: none
** Post-Condition: return a hand object reference
*****************************************************************************************/
Hand* Player::get_hand() {
    return &hand;
}
/****************************************************************************************
** Function: get_can_play()
** Description: returns if the player can play, true if yes false if no
** Parameters: none
** Pre-Condition: none
** Post-Condition: return bool can_play
*****************************************************************************************/
bool Player::get_can_play() {
    return can_play;
}
/****************************************************************************************
** Function: Hand()
** Description: modifys bool can_play
** Parameters: bool b
** Pre-Condition: pass in a bool 
** Post-Condition: set can_play to b
*****************************************************************************************/
void Player::set_can_play(bool b) {
    can_play = b;
}