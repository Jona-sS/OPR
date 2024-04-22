#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
///
/// Aufgabe das Spiel "Rock-Paper-Scissor" zu umsetzen:	https://en.wikipedia.org/wiki/Rock_paper_scissors
///														https://de.wikipedia.org/wiki/Schere,_Stein,_Papier

int main()
{
	Game game;
	HumanPlayer player;
	ComputerPlayer computer;
	while (game.make_turn(player,computer))
	{
	}

	return 0;
}
