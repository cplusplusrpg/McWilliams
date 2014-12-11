#ifndef __FUNCTION_H_INCLUDED__
#define __FUNCTION_H_INCLUDED__

#include <ctime>
class Player;
class Monster;

int menu();

int battle_menu();

void turn(Player& Tim, Monster creature);

void display_battle(int Tim_health, int enemy_health);

void wait_time(clock_t sec);

#endif
