#pragma once

#include "stdafx.hpp"

class Game
{
	sf::RenderWindow m_Window;

	void initWindow();

public:
	Game();

	void update();
	void render();
	const sf::RenderWindow& getWindow() const;
};
