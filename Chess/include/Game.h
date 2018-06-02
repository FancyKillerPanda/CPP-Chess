#pragma once


#include <SFML/Graphics.hpp>
#include "Piece.h"


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
	void Draw(std::vector<Piece>& pieces_list);
};