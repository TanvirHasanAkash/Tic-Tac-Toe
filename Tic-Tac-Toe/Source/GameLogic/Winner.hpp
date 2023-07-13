#pragma once

#include "Board.hpp"
#include "State.hpp"
#include "Turn.hpp"

class Winner
{
public:
	static bool CheckHorizontal(const Board<3, 3>& board, const size_t row, const State state)
	{
		return board.GetCells()[row][0].state == state &&
			board.GetCells()[row][1].state == state &&
			board.GetCells()[row][2].state == state;
	}

	static bool CheckVertical(const Board<3, 3>& board, const size_t column, const State state)
	{
		return board.GetCells()[0][column].state == state &&
			board.GetCells()[1][column].state == state &&
			board.GetCells()[2][column].state == state;
	}

	static bool CheckDiagonalLeft(const Board<3, 3>& board, const size_t column, const State state)
	{
		return board.GetCells()[0][2].state == state &&
			board.GetCells()[1][1].state == state &&
			board.GetCells()[2][0].state == state;
	}

	static bool CheckDiagonalRight(const Board<3, 3>& board, const size_t column, const State state)
	{
		return board.GetCells()[0][0].state == state &&
			board.GetCells()[1][1].state == state &&
			board.GetCells()[2][2].state == state;
	}

public:
	static bool CheckPlayer(const Board<3, 3>& board, const State state)
	{
		return CheckHorizontal(board, 0, state) ||
			CheckHorizontal(board, 1, state) ||
			CheckHorizontal(board, 2, state) ||
			CheckVertical(board, 0, state) ||
			CheckVertical(board, 1, state) ||
			CheckVertical(board, 2, state) ||
			CheckDiagonalLeft(board, 0, state) ||
			CheckDiagonalRight(board, 0, state);
	}

	static bool CheckX(const Board<3, 3>& board)
	{
		return CheckPlayer(board, playerX);
	}

	static bool CheckO(const Board<3, 3>& board)
	{
		return CheckPlayer(board, playerO);
	}

public:
	static bool CheckDraw(const Board<3, 3>& board)
	{
		for (size_t row = 0; row < board.rowCount; row++)
		{
			for (size_t column = 0; column < board.columnCount; column++)
			{
				if (board.GetCells()[row][column].state == none)
					return false;
			}
		}

		return true;
	}

public:
	static Player Board(const Board<3, 3>& board)
	{
		if (CheckX(board))
			return Player::X;

		if (CheckO(board))
			return Player::O;

		if (CheckDraw(board))
			return Player::Both;

		return Player::None;
	}
};
