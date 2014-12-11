#ifndef __FUNCTION_H_INCLUDED__
#define __FUNCTION_H_INCLUDED__

class Player;
class Monster;

int menu();

int battle_menu();

void turn(Player& Tim, Monster& creature);

void display_battle(int Tim_health, int enemy_health);

#endif
