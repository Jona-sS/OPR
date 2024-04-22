#ifndef GAME_H
#define GAME_H
#include <cstddef>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
class Game
{
public:
	bool make_turn(HumanPlayer player,ComputerPlayer computer);
private:
	size_t m_turn_id = 1;
	size_t m_total_wins = 0;
};

#endif // GAME_H
