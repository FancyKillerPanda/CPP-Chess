#pragma once


#include <SFML/Graphics.hpp>
#include "Piece.h"
#include <memory>


class Game
{
public:
	sf::RenderWindow* window;
	bool mouse_already_clicked;
	std::vector<sf::RectangleShape> tiles_to_highlight;

public:
	Game();
	~Game();

	void Run();
	void HandleEvents(std::vector<std::unique_ptr<Piece>>& pieces_list);
	void Update();
	void Draw(std::vector<std::unique_ptr<Piece>>& pieces_list);
	void DrawBoard();
	void HandleMouseClick(std::vector<std::unique_ptr<Piece>>& pieces_list);
};