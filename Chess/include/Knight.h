#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "ChessPos.h"


class Knight : public Piece
{
public:
	Knight(ChessPos pos, sf::Color piece_colour, const sf::Texture& texture, std::vector<Piece>& pieces_list);
	void GetTilesAttacking(std::vector<Piece>& pieces_list);
};