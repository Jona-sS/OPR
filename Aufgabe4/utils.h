#ifndef UTILS_H
#define UTILS_H

#include <string>

enum class shape_type
{
	rock,
	paper,
	scissor
};

enum class game_outcome_type
{
	tie,
	win,
	lose
};

std::string to_string(game_outcome_type outcome);

char to_char(shape_type shape);

std::string to_string(shape_type shape);

bool to_shape(char c, shape_type& shape);

game_outcome_type compare(shape_type s1, shape_type s2);

#endif // __UTILS_H__
