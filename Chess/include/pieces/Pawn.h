#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "ChessPos.h"
#include <memory>


class Pawn : public Piece
{
public:
	Pawn(ChessPos pos, sf::Color piece_colour, const sf::Texture& texture, std::vector<std::unique_ptr<Piece>>& pieces_list);
	void GetTilesAttacking(std::vector<std::unique_ptr<Piece>>& pieces_list) override;
};