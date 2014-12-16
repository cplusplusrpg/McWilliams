#ifndef __FUNCTION_H_INCLUDED__
#define __FUNCTION_H_INCLUDED__

class Player;
class Monster;

int menu();

int battle_menu();

void turn(Player& Tim, Monster creature);

#endif
