#include <SFML/Graphics.hpp>
#include "Base.h"
#include "Game.h"


Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chess!");
	Run();
}

Game::~Game()
{
	delete window;
}


void Game::Run()
{	
	while (window->isOpen())
	{
		HandleEvents();
		Update();
		Draw();
	}
}


void Game::HandleEvents()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();

			break;

		case sf::Event::KeyPressed:

			if (event.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}

			break;

		default:
			break;
		}
	}
}


void Game::Update()
{

}


void Game::Draw()
{
	window->clear(BG_COLOUR);

	window->display();
}
