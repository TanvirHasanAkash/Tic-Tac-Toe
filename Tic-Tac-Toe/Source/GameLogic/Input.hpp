#pragma once

#include <iostream>

#include "Board.hpp"
#include "Turn.hpp"

class Input
{
public:
	static bool Parse(Board<3, 3> &board)
	{
		std::string input;
		std::cin >> input;

		State state(none);

		switch (board.turn.current)
		{
		case Player::X:
			state = playerX;
			break;
		case Player::O:
			state = playerO;
			break;
		case Player::None:
		case Player::Both:
			break;
		}

		const size_t row = tolower(input[0]) - 97;
		const size_t column = input[1] - 49;

		if (row < board.rowCount && column < board.columnCount && board.GetCells()[row][column].state == none)
		{
			board.SetCells(Cell(state), row, column);
			return true;
		}

		return false;
	}
};
