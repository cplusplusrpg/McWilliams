#ifndef __MONSTER_H_INCLUDED__
#define __MONSTER_H_INCLUDED__

class Monster
{
protected:
    int level;
    int current_health;
    int max_health;
    int damage;
    bool alive;
public:
    Monster();
    Monster(int health, int power);
    int get_level();
    int get_health();
    int get_damage();
    int get_exp_reward();
    int get_gold_reward();
    bool check_life();
    void hurt(int value);
    void check_health();
    void kill();
private:
    int exp_reward;
    int gold_reward;
};

#endif
