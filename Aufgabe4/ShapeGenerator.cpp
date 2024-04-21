#include "ShapeGenerator.h"

ShapeGenerator::ShapeGenerator() : m_gen{ m_rd() },
m_dist{ 0, 2 },
m_items{ shape_type::rock, shape_type::paper, shape_type::scissor }
{
}

shape_type ShapeGenerator::generate()
{
	return m_items[m_dist(m_gen)];
}
