#include "LadderSnake.h"
#include <iostream>
#define MaxLadderSnakeSteps 100

using namespace std;

int LadderSnake::winPosCount = 0;

LadderSnake::LadderSnake(int players)
{
	this->players = players;

	for (int i = 0; i < players; i++)
	{
		playersPos.push_back(0);
		curPlayers.push(i);
		winners.insert(pair<int, uint32_t> (i + 1, -1));
	}
}

int LadderSnake::play()
{
	int player, playerPos, input;
	
	player = curPlayers.front();
	curPlayers.pop();

	cout << "Player " << player + 1 << " chance: Please roll dice." << endl;

	cout << "Press 1 to continue or 0 to quit : ";
	cin >> input;
	
	if (!input)
		return input;

	playerPos = playersPos[player];

	int diceNum = dice.rollDice();
	int ladderSnakePosition = ladderSnakePos.getLadderSnakePos(playerPos + diceNum);
	
	cout << "Got dice number : " << diceNum << endl;
	
	if (!ladderSnakePosition)
	{
		if (playersPos[player] + diceNum > MaxLadderSnakeSteps)
		{
			cout << "Sorry you can't move, You need " << MaxLadderSnakeSteps - playersPos[player] << " to win!" << endl;
			cout << "Prev pos : " << playerPos << ", Cur pos : " << playersPos[player] << endl;
		}
		else
		{
			playersPos[player] += diceNum;
			cout << "Prev pos : " << playerPos << ", Cur pos : " << playersPos[player] << endl;
		}
	}
	else if (ladderSnakePosition > playerPos + diceNum)
	{
		playersPos[player] = ladderSnakePosition;
		cout << "Great you got ladder" << endl;
		cout << "Prev pos : " << playerPos << ", Cur pos : " << playersPos[player] << endl;
	}
	else if (ladderSnakePosition < playerPos + diceNum)
	{
		playersPos[player] = ladderSnakePosition;
		cout << "Ohh snake bites you" << endl;
		cout << "Prev pos : " << playerPos << ", Cur pos : " << playersPos[player] << endl;
	}

	cout << endl;

	if (playersPos[player] == MaxLadderSnakeSteps)
	{
		if (!winPosCount)
		{
			cout << "Congrats Player " << player + 1 << " you Won the match!" << endl;
		}

		cout << endl;
		winners[player] = ++winPosCount;
	}
	else
	{
		curPlayers.push(player);
	}

	if (players == winPosCount + 1)
	{
		cout << "\nLadder Snake game result!!!" << endl;
		
		for (int i = 0; i < winners.size(); i++)
		{
			if (winners[i] != -1)
			{
				cout << "Player " << i + 1 << " got " << winners[i] << " position." << endl;
			}
			else
			{
				cout << "Player " << i + 1 << " got " << players << " position." << endl;
			}
		}

		return 0;
	}

	return input;
}


