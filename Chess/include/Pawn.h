#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "ChessPos.h"


class Pawn : public Piece
{
public:
	Pawn(ChessPos pos, sf::Color piece_colour, std::string image_path, std::vector<Piece>& pieces_list);
	void GetTilesAttacking(std::vector<Piece>& pieces_list);
};