#include "Game.h"
#include <iostream>
#include "utils.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

bool Game::make_turn(HumanPlayer player,ComputerPlayer computer) //damit nicht in jedem Durchlauf neue Objekte erstellt werden
{
	game_outcome_type result = game_outcome_type::lose;

	std::cout << "-----------------------" << std::endl;
	std::cout << "Turn: " << m_turn_id++ << " wins: " << m_total_wins << std::endl;
	std::cout << "-----------------------" << std::endl;

	//
	// TODO 3 Start
	//
	// - Wiederholen, bis das Ergebnis ist nicht "tie" folgendes: 		// zum abbrechen 0 ausgeben
	//	 -- Mensch ist dran (nutzen Sie HumanPlayer Klasse) --> ErgebnisseM
	//   -- Rechner ist dran (nutzen Sie ComputerPlayer Klasse) --> ErgebnisseR
	//   -- Vergleichen die Beide ergebnisse (Tipp: "compare" kann helfen)
	//   -- Vergleichen Sie die beiden Ergebnisse (Tipp: "compare" kann helfen)
	//	     --> Falls Mensch gewinnt  -> result = game_outcome_type::win
	//       --> Falls Rechner gewinnt -> result = game_outcome_type::lose
	//       --> Sonst -> result = game_outcome_type::tie (nochmal Wiederholen)
	do
	{
		//HumanPlayer player;
		shape_type ErgebnisseM = player.make_turn();
		std::cout << "Human choose: " << to_string(ErgebnisseM) << std::endl;
		//ComputerPlayer computer;
		shape_type ErgebnisseR = computer.make_turn();
		std::cout << "Computer choose: " << to_string(ErgebnisseR) << std::endl;
		result = compare(ErgebnisseM, ErgebnisseR);
		// std::cout << (int)result;
	} while (result == game_outcome_type::tie);
	//
	// TODO 3 End
	//

	std::cout << "You " << to_string(result) << std::endl;

	if (result == game_outcome_type::win)
	{
		++m_total_wins;
	}

	std::cout << "\nTo continue enter: 'c'" << std::endl;
	char c;
	std::cin >> c;
	return c == 'c';
}
