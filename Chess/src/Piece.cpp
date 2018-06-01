#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Base.h"


Piece::Piece(ChessPos pos, sf::Color piece_colour, std::string image_path)
{
	position = pos;
	colour = piece_colour;

	texture.loadFromFile(image_path);
	setTexture(texture);

	MovePiece(position, true);
}


void Piece::MovePiece(ChessPos new_pos, bool absolute)
{
	if (!absolute)
	{
		position += new_pos;
	}

	else
	{
		position = new_pos;
	}

	setPosition(sf::Vector2f(position.column * TILE_SIZE + TILE_OFFSET, position.row * TILE_SIZE + TILE_OFFSET));
}


bool Piece::IsLocationValid(ChessPos location)
{
	if (location.row > 7 || location.row < 0)
	{
		return false;
	}

	if (location.column > 7 || location.column < 0)
	{
		return false;
	}
	
	return true;
}