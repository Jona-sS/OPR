#include "utils.h"

#include <stdexcept>

std::string to_string(game_outcome_type outcome)
{
	switch (outcome)
	{
	case game_outcome_type::tie:
		return "Tie";
	case game_outcome_type::win:
		return "Win";
	case game_outcome_type::lose:
		return "Lose";
	}
	throw std::invalid_argument("Wrong input.");
}

char to_char(shape_type shape)
{
	switch (shape)
	{
	case shape_type::rock:
		return 'r';
	case shape_type::paper:
		return 'p';
	case shape_type::scissor:
		return 's';
	}
	throw std::invalid_argument("Wrong input.");
}

std::string to_string(shape_type shape)
{
	switch (shape)
	{
	case shape_type::rock:
		return "Rock";
	case shape_type::paper:
		return "Paper";
	case shape_type::scissor:
		return "Scissor";
	}
	throw std::invalid_argument("Wrong input.");
}

bool to_shape(char c, shape_type& shape) 		//nach Eingabe verwenden!
{
	switch (c)
	{
	case 'r':
		shape = shape_type::rock;
		return true;
	case 'p':
		shape = shape_type::paper;
		return true;
	case 's':
		shape = shape_type::scissor;
		return true;
	default:
		return false;
	}
}

game_outcome_type compare(shape_type s1, shape_type s2)//Erst Mensch dann Rechner shape übegeben
{
	if (s1 == s2)
	{
		return game_outcome_type::tie;
	}

	if ((s1 == shape_type::rock && s2 == shape_type::scissor) ||
		(s1 == shape_type::scissor && s2 == shape_type::paper) ||
		(s1 == shape_type::paper && s2 == shape_type::rock))
	{
		return game_outcome_type::win;
	}

	return game_outcome_type::lose;
}
