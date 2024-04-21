#include "HumanPlayer.h"
#include <iostream>

shape_type HumanPlayer::make_turn()
{
	/*
	char c = 'r';
	shape_type shape = shape_type::rock;
	bool entered_shape = false;
*/
//
// TODO 1 Start
//
//  Bitten Sie den Benutzer, eine g�ltige Eingabe anzugeben. Wenn die Eingabe ung�ltig ist, wiederholen Sie den Vorgang.
//  Tipp: "to_shape" kann n�tzlich sein.
char c;
shape_type shape;
std::cout <<"Your turn: ";
std::cin >> c;
bool entered_shape = to_shape(c,shape);
//
// TODO 1 End
//

	return shape;
}
