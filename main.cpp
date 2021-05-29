#include "stdafx.hpp"
#include "game.hpp"

int main()
{
	srand(time(static_cast<unsigned>(0)));
	
	Game game;
	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}
	return 0;
}