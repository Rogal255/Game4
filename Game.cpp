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

void Game::update(sf::Time t_DeltaTime)
{
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
	sf::Clock frameKeeper;
	sf::Time timeSinceLastUpdate{ sf::Time::Zero };
	sf::Time timePerFrame{ sf::seconds(1.f / 60.f) };

	while (this->m_Window.isOpen())
	{
		this->handleEvents();
		timeSinceLastUpdate += frameKeeper.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			this->handleEvents();
			this->update(timePerFrame);
		}
		this->render();
	}
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->m_Window;
}
