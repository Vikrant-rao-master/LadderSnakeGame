#include "LadderSnakePos.h"

LadderSnakePos::LadderSnakePos()
{
	ladderSnakePos.insert(pair<int, int>(2, 23));
	ladderSnakePos.insert(pair<int, int>(8, 12));
	ladderSnakePos.insert(pair<int, int>(17, 93));
	ladderSnakePos.insert(pair<int, int>(29, 54));
	ladderSnakePos.insert(pair<int, int>(31, 12));
	ladderSnakePos.insert(pair<int, int>(32, 51));
	ladderSnakePos.insert(pair<int, int>(39, 80));
	ladderSnakePos.insert(pair<int, int>(41, 20));
	ladderSnakePos.insert(pair<int, int>(59, 37));
	ladderSnakePos.insert(pair<int, int>(62, 78));
	ladderSnakePos.insert(pair<int, int>(67, 50));
	ladderSnakePos.insert(pair<int, int>(70, 89));
	ladderSnakePos.insert(pair<int, int>(75, 96));
	ladderSnakePos.insert(pair<int, int>(83, 80));
	ladderSnakePos.insert(pair<int, int>(92, 76));
	ladderSnakePos.insert(pair<int, int>(99, 4));
}

int LadderSnakePos::getLadderSnakePos(int pos)
{
	if (ladderSnakePos.find(pos) != ladderSnakePos.end())
	{
		return ladderSnakePos[pos];
	}

	return 0;
}
