#pragma once

#include <array>
#include <iostream>

#include "Cell.hpp"
#include "Turn.hpp"

template <size_t RowCount, size_t ColumnCount>
class Board
{
public:
	const size_t rowCount = RowCount;
	const size_t columnCount = ColumnCount;
	const size_t size = RowCount * ColumnCount;

	TurnManager turn;

private:
	std::array<std::array<Cell, ColumnCount>, RowCount> cells
	{
		std::array { Cell(none), Cell(none), Cell(none) },
		std::array { Cell(none), Cell(none), Cell(none) },
		std::array { Cell(none), Cell(none), Cell(none) }
	};

public:
	[[nodiscard]] std::array<std::array<Cell, ColumnCount>, RowCount> GetCells() const
	{
		return cells;
	}

	void SetCells(const Cell cell, const size_t row, const size_t column)
	{
		turn.SwitchTurn();
		this->cells[row][column] = cell;
	}

public:
	Board() = default;

public:
	void Print() const;
};

template <size_t RowCount, size_t ColumnCount>
void Board<RowCount, ColumnCount>::Print() const
{
	for (size_t i = 0; i < RowCount; i++)
	{
		for (size_t j = 0; j < ColumnCount; j++)
		{
			std::cout << cells[i][j].state.label << '\t';
		}
		std::cout << '\n';
	}
}
