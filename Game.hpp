#pragma once

#include "Player.hpp"
#include "ResourceHolder.hpp"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow m_Window;
	sf::Event m_Event;
	std::shared_ptr<Player> m_Player;
	ResourceHolder<sf::Texture, GameTextures> m_Textures;
	sf::Sprite m_Sprite;

	void initWindow();
	void initPlayer();

	void handleEvents();
	void update();
	void render();

public:
	Game();
	void run();
	const sf::RenderWindow& getWindow() const;
};
