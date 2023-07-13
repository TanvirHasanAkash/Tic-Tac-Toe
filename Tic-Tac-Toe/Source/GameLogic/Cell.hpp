#pragma once

#include "State.hpp"

class Cell
{
public:
	State state = none;

	explicit Cell(const State state)
		: state(state)
	{ }
};
