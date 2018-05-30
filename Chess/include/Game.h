#pragma once


#include <SFML/Graphics.hpp>


class Game
{
public:
	sf::RenderWindow* window;

public:
	Game();
	~Game();

	void Run();
	void HandleEvents();
	void Update();
	void Draw();
};