#include "GameLogic/Board.hpp"
#include "GameLogic/Input.hpp"
#include "GameLogic/Winner.hpp"

int main()
{
	bool gameLoop = true;
	Board<3, 3> board;

	while (gameLoop)
	{
		std::cout << "Board" << '\n';
		board.Print();
		std::cout << std::endl;

		bool parsedInput;
		do
		{
			if (Winner::Board(board) == Player::X)
			{
				std::cout << "Winner-X!" << '\n';
				gameLoop = false;
				break;
			}
			if (Winner::Board(board) == Player::O)
			{
				std::cout << "Winner-O!" << '\n';
				gameLoop = false;
				break;
			}
			if(Winner::Board(board) == Player::Both)
			{
				std::cout << "Draw!" << '\n';
				gameLoop = false;
				break;
			}

			std::cout << "Input: ";
			parsedInput = Input::Parse(board);

			if (!parsedInput)
				std::cout << "[Invalid input]" << "\n\n";
			else
				std::cout << std::endl;
		} while (!parsedInput);
	}
}
