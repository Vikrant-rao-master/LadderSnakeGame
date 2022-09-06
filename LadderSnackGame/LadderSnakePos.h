#pragma once
#include <map>

using namespace std;

class LadderSnakePos
{
private:
	map <int, int> ladderSnakePos;
public:
	LadderSnakePos();
	int getLadderSnakePos(int pos);
};

