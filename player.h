/***********************************************************************************
** Program: player.h
** Author: Andy James
** Date: 4/28/2021
** Description: header file for player.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include <string>

class Player{
    private:
        Hand hand;
        string name;
        bool can_play;
    public:
        Player();
        ~Player();
        void set_name(string);
        string get_name();
        Hand* get_hand();
        bool get_can_play();
        void set_can_play(bool);
};

#endif