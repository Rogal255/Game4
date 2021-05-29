#include "stdafx.hpp"
#include "Game.hpp"

void Game::initWindow()
{
	this->m_Window.create(sf::VideoMode(800, 600), "Game 4", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
	this->initWindow();
}

void Game::update()
{
}

void Game::render()
{
}

const sf::RenderWindow & Game::getWindow() const
{
	return this->m_Window;
}
