#include "Player.hpp"

void Player::initTexture()
{
}

void Player::initSprite()
{
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& t_Target)
{
	t_Target.draw(m_Sprite);
}
