#ifndef SHAPE_GENERATOR_H
#define SHAPE_GENERATOR_H

#include "utils.h"
#include <vector>
#include <random>

class ShapeGenerator
{
public:
	ShapeGenerator();
	shape_type generate();
private:
	// Zur.info: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	std::random_device m_rd;
	std::mt19937 m_gen;
	std::uniform_int_distribution<int> m_dist;
	std::vector<shape_type> const m_items;
};

#endif // SHAPE_GENERATOR_H
