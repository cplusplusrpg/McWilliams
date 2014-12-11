#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include "Monster.h"

class Player: public Monster
{
private:
    int exp;
    int max_exp;
    int gold;
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

#endif
