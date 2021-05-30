#include "Game.hpp"

void Game::initWindow()
{
	this->m_Window.create(sf::VideoMode(800, 600), "Game 4", sf::Style::Close | sf::Style::Titlebar);
	// std::cout << "Texture max size: " << sf::Texture::getMaximumSize() << '\n';
}

void Game::initPlayer()
{
	this->m_Player = std::make_shared<Player>();
}

void Game::handleEvents()
{
	while (this->m_Window.pollEvent(this->m_Event))
	{
		switch (this->m_Event.type)
		{
		case sf::Event::Closed:
			this->m_Window.close();
			break;
		case sf::Event::KeyPressed:
			if (this->m_Event.key.code == sf::Keyboard::Escape)
			{
				this->m_Window.close();
			}
			break;
		}
	}
}

void Game::update()
{
	this->handleEvents();
	this->m_Player->update();
}

void Game::render()
{
	this->m_Window.clear();

	this->m_Window.display();
}


Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

void Game::run()
{
	while (this->m_Window.isOpen())
	{
		this->update();
		this->render();
	}
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->m_Window;
}
