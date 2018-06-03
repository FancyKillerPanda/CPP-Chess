#include <SFML/Graphics.hpp>
#include "Bishop.h"
#include "ChessPos.h"
#include "Base.h"


Bishop::Bishop(ChessPos pos, sf::Color piece_colour, const sf::Texture& texture, std::vector<std::unique_ptr<Piece>>& pieces_list) : Piece(pos, piece_colour, texture)
{
	tiles_attacking.reserve(13);
	GetTilesAttacking(pieces_list);
}


void Bishop::GetTilesAttacking(std::vector<std::unique_ptr<Piece>>& pieces_list)
{
	tiles_attacking.clear();

	for (int i = 1; i <= 7; i++)
	{
		ChessPos new_loc(position.row + i, position.column + i);
		bool broken = false;

		for (auto const& piece : pieces_list)
		{
			if (piece->position == new_loc)
			{
				if (piece->colour != colour)
				{
					tiles_attacking.push_back(new_loc);
				}

				broken = true;
				break;
			}
		}

		if (!broken)
		{
			if (IsLocationValid(new_loc))
				tiles_attacking.push_back(new_loc);
		}

		else
		{
			break;
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		ChessPos new_loc(position.row - i, position.column - i);
		bool broken = false;

		for (auto const& piece : pieces_list)
		{
			if (piece->position == new_loc)
			{
				if (piece->colour != colour)
				{
					tiles_attacking.push_back(new_loc);
				}

				broken = true;
				break;
			}
		}

		if (!broken)
		{
			if (IsLocationValid(new_loc))
				tiles_attacking.push_back(new_loc);
		}

		else
		{
			break;
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		ChessPos new_loc(position.row - i, position.column + i);
		bool broken = false;

		for (auto const& piece : pieces_list)
		{
			if (piece->position == new_loc)
			{
				if (piece->colour != colour)
				{
					tiles_attacking.push_back(new_loc);
				}

				broken = true;
				break;
			}
		}

		if (!broken)
		{
			if (IsLocationValid(new_loc))
				tiles_attacking.push_back(new_loc);
		}

		else
		{
			break;
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		ChessPos new_loc(position.row + i, position.column - i);
		bool broken = false;

		for (auto const& piece : pieces_list)
		{
			if (piece->position == new_loc)
			{
				if (piece->colour != colour)
				{
					tiles_attacking.push_back(new_loc);
				}

				broken = true;
				break;
			}
		}

		if (!broken)
		{
			if (IsLocationValid(new_loc))
				tiles_attacking.push_back(new_loc);
		}

		else
		{
			break;
		}
	}
}