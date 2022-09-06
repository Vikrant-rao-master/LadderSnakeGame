#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "Dice.h"
#include "LadderSnakePos.h"
using namespace std;

class LadderSnake
{
private:
	int players;
	vector <int> playersPos;
	map <int, uint32_t> winners;
	queue <int> curPlayers;
	Dice dice;
	LadderSnakePos ladderSnakePos;
	static int winPosCount;
public:
	LadderSnake(int players);
	int play();
};
