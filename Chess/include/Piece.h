#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "ChessPos.h"


class Piece : public sf::Sprite
{
public:
	sf::Texture texture;

	ChessPos position;
	sf::Color colour;
	std::vector<ChessPos> tiles_attacking;

public:
	Piece(ChessPos pos, sf::Color piece_colour, std::string image_path);
	void MovePiece(ChessPos position, bool absolute = false);
	virtual void GetTilesAttacking(const std::vector<Piece>& pieces_list) {}
	bool IsLocationValid(ChessPos location);
};