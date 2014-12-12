//The Player class. Derived from the Monster class. Apparently Timothy McWilliams was a Monster Child...
//All member functions are explained in the implementation file: Player.cpp

#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include "Monster.h"

class Player: public Monster
{
private:
    int exp;//The current amount of experience the Player has.
    int max_exp;//The amounr of experience the Player needs to level up.
    int gold;//The amount of money the Player currently has.
public:
    Player();
    void rest();
    void add_gold(int value);
    void add_exp(int value);
    void levelup();
    void status();
    int get_exp();
    int get_max_exp();
    int get_gold();
};

//Player will slowly be expanded as we work on more functionality for the game.

#endif
