#ifndef GAME_H
#define GAME_H
#include <cstddef>
class Game
{
public:
	bool make_turn();
private:
	size_t m_turn_id = 1;
	size_t m_total_wins = 0;
};

#endif // GAME_H
