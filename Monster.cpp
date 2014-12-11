#include <iostream>
#include "Monster.h"

using namespace std;

Monster::Monster() : level(1), max_health(25), current_health(25), damage(7), alive(true), exp_reward(10), gold_reward(5)
{
}

Monster::Monster(int health, int power) : level(1), current_health(health), max_health(health), damage(power), alive(true), exp_reward(0), gold_reward(5)
{
}

int Monster::get_level()
{
    return level;
}

int Monster::get_health()
{
    return current_health;
}

int Monster::get_damage()
{
    return damage;
}

int Monster::get_exp_reward()
{
    return exp_reward;
}

int Monster::get_gold_reward()
{
    return gold_reward;
}

void Monster::hurt(int value)
{
    current_health -= value;
    check_health();
}

void Monster::check_health()
{
    if(current_health <= 0)
    {
        current_health = 0;
        alive = false;
    }
    else if(current_health > max_health)
    {
        current_health = max_health;
    }
}

bool Monster::check_life()
{
    return alive;
}

void Monster::kill()
{
    alive = false;
}
