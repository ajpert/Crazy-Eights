/***********************************************************************************
** Program: card.h
** Author: Andy James
** Date: 4/28/2021
** Description: header file for card.cpp
** Input: none
** Output: none
************************************************************************************/
#ifndef CARD_H 
#define CARD_H 

using namespace std; 
class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public:

    Card();
    Card(int,int);
    ~Card();
    void set_rank(int);
    void set_suit(int);
    int get_rank();
    int get_suit();
    bool equals(const Card);
    void print_card();
  // must have constructors, destructor, accessor methods, and mutator methods

};

#endif