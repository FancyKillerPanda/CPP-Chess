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
	std::string piece_type;

public:
	Piece(ChessPos pos, sf::Color piece_colour, const sf::Texture& texture, std::string piece_type);
	void MovePiece(ChessPos position, bool absolute = false);
	virtual void GetTilesAttacking(std::vector<std::unique_ptr<Piece>>& pieces_list) {}
	bool IsLocationValid(ChessPos location);
};

bool InCheck(ChessPos tile_location, sf::Color by_colour, std::vector<std::unique_ptr<Piece>>& pieces_list);
bool InCheck(Piece piece, std::vector<std::unique_ptr<Piece>>& pieces_list);
