#include "Dice.h"
#include <cstdlib>

int Dice::rollDice()
{
	return 1 + (rand() % 6);
}
