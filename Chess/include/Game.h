#pragma once


#include <SFML/Graphics.hpp>
#include "Piece.h"
#include <memory>


class Game
{
public:
	sf::RenderWindow* window;
	bool highlighting;
	std::vector<sf::RectangleShape> tiles_to_highlight;
	sf::Color turn;
	Piece* piece_to_move;
	std::vector<std::unique_ptr<Piece>> pieces_list;

public:
	Game();
	~Game();

	void Run();
	void HandleEvents();
	void Update();
	void Draw();
	void DrawBoard();
	void HandleMouseClick();
	void CreatePieces();

public:
	sf::Texture white_pawn_texture;
	sf::Texture white_rook_texture;
	sf::Texture white_knight_texture;
	sf::Texture white_bishop_texture;
	sf::Texture white_queen_texture;
	sf::Texture white_king_texture;
	sf::Texture black_pawn_texture;
	sf::Texture black_rook_texture;
	sf::Texture black_knight_texture;
	sf::Texture black_bishop_texture;
	sf::Texture black_queen_texture;
	sf::Texture black_king_texture;
};