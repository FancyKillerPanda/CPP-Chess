#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "ChessPos.h"


class Queen : public Piece
{
public:
	Queen(ChessPos pos, sf::Color piece_colour, std::string image_path, std::vector<Piece>& pieces_list);
	void GetTilesAttacking(std::vector<Piece>& pieces_list);
};