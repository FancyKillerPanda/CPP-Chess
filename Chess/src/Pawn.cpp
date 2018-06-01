#include <SFML/Graphics.hpp>
#include "Pawn.h"
#include "ChessPos.h"
#include "Base.h"


Pawn::Pawn(ChessPos pos, sf::Color piece_colour, std::string image_path, std::vector<Piece>& pieces_list) : Piece(pos, piece_colour, image_path)
{
	pieces_list.push_back(*this);
	GetTilesAttacking(pieces_list);
}


void Pawn::GetTilesAttacking(std::vector<Piece>& pieces_list)
{
	tiles_attacking.clear();

	if (colour == WHITE)
	{
		bool broken = false;

		for (Piece piece : pieces_list)
		{
			if (piece.position == ChessPos(position.row - 1, position.column))
				broken = true;

			else if (piece.position == ChessPos(position.row - 1, position.column - 1))
			{
				if (piece.colour == BLACK)
				{
					if (IsLocationValid(ChessPos(position.row - 1, position.column - 1)))
						tiles_attacking.push_back(ChessPos(position.row - 1, position.column - 1));
				}
			}

			else if (piece.position == ChessPos(position.row - 1, position.column + 1))
			{
				if (piece.colour == BLACK)
				{
					if (IsLocationValid(ChessPos(position.row - 1, position.column + 1)))
						tiles_attacking.push_back(ChessPos(position.row - 1, position.column + 1));
				}
			}
		}

		if (!broken)
		{
			if (IsLocationValid(ChessPos(position.row - 1, position.column)))
				tiles_attacking.push_back(ChessPos(position.row - 1, position.column));

			if (position.row == 6)
			{				
				for (Piece piece : pieces_list)
				{
					if (piece.position == ChessPos(position.row - 2, position.column))
					{
						broken = true;
						break;
					}
				}

				if (!broken)
				{
					if (IsLocationValid(ChessPos(position.row - 2, position.column)))
						tiles_attacking.push_back(ChessPos(position.row - 2, position.column));
				}
			}
		}
	}

	else if (colour == BLACK)
	{
		bool broken = false;

		for (Piece piece : pieces_list)
		{
			if (piece.position == ChessPos(position.row + 1, position.column))
				broken = true;

			else if (piece.position == ChessPos(position.row + 1, position.column - 1))
			{
				if (piece.colour == WHITE)
				{
					if (IsLocationValid(ChessPos(position.row + 1, position.column - 1)))
						tiles_attacking.push_back(ChessPos(position.row + 1, position.column - 1));
				}
			}

			else if (piece.position == ChessPos(position.row + 1, position.column + 1))
			{
				if (piece.colour == WHITE)
				{
					if (IsLocationValid(ChessPos(position.row + 1, position.column - 1)))
						tiles_attacking.push_back(ChessPos(position.row + 1, position.column + 1));
				}
			}
		}

		if (!broken)
		{
			if (IsLocationValid(ChessPos(position.row + 1, position.column)))
				tiles_attacking.push_back(ChessPos(position.row + 1, position.column));

			if (position.row == 1)
			{
				for (Piece piece : pieces_list)
				{
					if (piece.position == ChessPos(position.row + 2, position.column))
					{
						broken = true;
						break;
					}
				}

				if (!broken)
				{
					if (IsLocationValid(ChessPos(position.row + 2, position.column)))
					{
						tiles_attacking.push_back(ChessPos(position.row + 2, position.column));
					}
				}
			}
		}
	}
}
