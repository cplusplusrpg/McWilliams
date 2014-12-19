//The core program. This file will pull in all of the other header files and is the main organizer of the Timothy McWilliams project.

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Monster.h"
#include "Player.h"
#include "Item.h"
#include "Inventory.h"
#include "Menu.h"

#include "function.h"

using namespace std;

//The program still needs a lot of work and is quite basic for the time being.
int main()
{
    Player Tim;
    Monster Slime;//1 Player and 1 Monster are created.
    char choice;

    cout << "These are the Adventures of Timothy McWilliams. The greatest story ever told." << endl;
    cout << "The fate of Timothy McWilliams depends on you." << endl << endl;
    do
    {
        //choice = menu();//After asking the user what they would like to do,
        Menu *menu = make_menu(Tim, Slime);
        menu->print_menu();
        cin >> choice;
        menu->perform_selection(choice);
    } while(true);
}