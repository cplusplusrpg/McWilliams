// Note: NOT A REAL PROGRAM...just ideas ^^
#include <iostream>
using namespace std;

// SIZE 30, NOT 29, BECAUSE OF THE HIDDEN 0; string literal has additional character - terminating zero 
const char DISPLAY1[11][30] = {
"                             ", 
"                      ____   ",
"                ______|  |   ",
"                |     |__|   ",
"                |            ",
"         _______|_______     ",
"         |             |     ",
"         |  []     []  |     ",
"         |             |     ",
"         |  |_______|  |     ",
"         |_____________|     "
};

const char TIMOTHY[11][30] = {
"           ---               ",
"          [. .]              ",
"          [   ]  |           ",
"     ----  ---   |           ",
"     |  |   |    |           ",
"     |  |---|----|           ",
"     ----   |                ",
"            |                ",
"         -------             ",
"         |     |             ",
"         |     |             "
};

const char DISPLAY2[11][30] = {
"                             ",
"                             ",
"             _______         ",
"            _|      |_       ",
"     _______|        |_      ",
"    | |     |          |     ",
"    |_|_____|_        _|     ",
"            |_      _|       ",
"            ||[]  []||       ",
"            -|      |-       ",
"           | |______| |      "
};

const char DISPLAY3[11][30] = {
"               ---           ",
"              [. .]          ",
"              [|-|]          ",
"               ---  |_|      ",
"                |    |       ",
"           -----|----|       ",
"                |            ",
"                |            ",
"             -------         ",
"             |     |         ",
"             |     |         "
};

int main()
{
  int Tim_health = 100, enemy_health = 100;
  // The Slime mob (adjust health and damage as needed)
  cout << endl;
  cout << "         Timothy                       Beginner's Slime    " << endl;
  cout << "         HP: " << Tim_health << "                            HP: " << enemy_health << "          " << endl;
  for (int i = 0; i < 11; i++)
  {
      for (int j = 0; j < 30; j++)
      {
          cout << TIMOTHY[i][j];
      }
      cout << " ";
      for (int k = 0; k < 30; k++)
      {
      	cout << DISPLAY1[i][k];
      }
      cout << endl;
  }
  cout << "-----------------------------------------------------------" << endl;

  // The Hostile Hobo mob (you can just adjust the damage and health of this dude)
  cout << endl;
  cout << "         Timothy                         Hostile Hobo    " << endl;
  cout << "         HP: " << Tim_health << "                           HP: " << enemy_health << "          " << endl;
  for (int i = 0; i < 11; i++)
  {
      for (int j = 0; j < 30; j++)
      {
      	cout << TIMOTHY[i][j];
      }
      cout << " ";
      for (int k = 0; k < 30; k++)
      {
      	cout << DISPLAY3[i][k];
      }
      cout << endl;
  }
  cout << "-----------------------------------------------------------" << endl;

  // The Barrel Mushroom mob
  cout << endl;
  cout << "         Timothy                        Barrel Mushroom    " << endl;
  cout << "         HP: " << Tim_health << "                            HP: " << enemy_health << "          " << endl;
  for (int i = 0; i < 11; i++)
  {
      for (int j = 0; j < 30; j++)
      {
      	cout << TIMOTHY[i][j];
      }
      cout << " ";
      for (int k = 0; k < 30; k++)
      {
      	cout << DISPLAY2[i][k];
      }
      cout << endl;
  }
  cout << "-----------------------------------------------------------" << endl;

  return 0;
}
