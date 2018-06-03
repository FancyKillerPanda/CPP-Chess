#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "ChessPos.h"
#include <memory>


class Piece : public sf::Sprite
{
public:
	sf::Texture texture;

	ChessPos position;
	sf::Color colour;
	std::vector<ChessPos> tiles_attacking;

public:
	Piece(ChessPos pos, sf::Color piece_colour, const sf::Texture& texture);
	void MovePiece(ChessPos position, bool absolute = false);
	virtual void GetTilesAttacking(const std::vector<std::unique_ptr<Piece>>& pieces_list) {}
	bool IsLocationValid(ChessPos location);
};