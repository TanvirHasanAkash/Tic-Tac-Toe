#pragma once

enum class Player
{
	None = 0,
	X = 1,
	O = 2,
	Both = 3
};

class TurnManager
{
public:
	Player current = Player::X;

public:
	void SwitchTurn()
	{
		switch (current)
		{
		case Player::X:
			current = Player::O;
			break;
		case Player::O:
			current = Player::X;
			break;
		case Player::None:
		case Player::Both:
			break;
		}
	}
};
