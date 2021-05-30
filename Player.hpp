#pragma once

#include <SFML/Graphics.hpp>

class Player
{
	sf::Sprite m_Sprite;
	sf::Texture m_TextureSheet;

	void initTexture();
	void initSprite();

public:
	Player();
	void update();
	void render(sf::RenderTarget& t_Target);
};

