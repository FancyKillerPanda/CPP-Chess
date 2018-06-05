#include <SFML/Graphics.hpp>
#include "King.h"
#include "ChessPos.h"
#include "Base.h"


King::King(ChessPos pos, sf::Color piece_colour, const sf::Texture& texture, std::vector<std::unique_ptr<Piece>>& pieces_list) : Piece(pos, piece_colour, texture, "KING")
{
	tiles_attacking.reserve(8);
	GetTilesAttacking(pieces_list);
}


void King::GetTilesAttacking(std::vector<std::unique_ptr<Piece>>& pieces_list)
{
	tiles_attacking.clear();

	ChessPos new_loc_u = ChessPos(position.row - 1, position.column);
	ChessPos new_loc_ur = ChessPos(position.row - 1, position.column + 1);
	ChessPos new_loc_r = ChessPos(position.row, position.column + 1);
	ChessPos new_loc_dr = ChessPos(position.row + 1, position.column + 1);
	ChessPos new_loc_d = ChessPos(position.row + 1, position.column);
	ChessPos new_loc_dl = ChessPos(position.row + 1, position.column - 1);
	ChessPos new_loc_l = ChessPos(position.row, position.column - 1);
	ChessPos new_loc_ul = ChessPos(position.row - 1, position.column - 1);

	bool broken_u = false;
	bool broken_ur = false;
	bool broken_r = false;
	bool broken_dr = false;
	bool broken_d = false;
	bool broken_dl = false;
	bool broken_l = false;
	bool broken_ul = false;

	for (auto const& piece : pieces_list)
	{
		if (piece->colour != colour)
		{
			continue;
		}

		if (piece->position == new_loc_u)
		{
			broken_u = true;
		}

		else if (piece->position == new_loc_ur)
		{
			broken_ur = true;
		}

		else if (piece->position == new_loc_r)
		{
			broken_r = true;
		}

		else if (piece->position == new_loc_dr)
		{
			broken_dr = true;
		}

		else if (piece->position == new_loc_d)
		{
			broken_d = true;
		}

		else if (piece->position == new_loc_dl)
		{
			broken_dl = true;
		}

		else if (piece->position == new_loc_l)
		{
			broken_l = true;
		}

		else if (piece->position == new_loc_ul)
		{
			broken_ul = true;
		}
	}

	for (auto const& piece : pieces_list)
	{
		if (piece->colour == colour || piece->piece_type == "PAWN")
			continue;

		for (ChessPos pos : piece->tiles_attacking)
		{
			if (pos == new_loc_u)
			{
				broken_u = true;
			}

			else if (pos == new_loc_ur)
			{
				broken_ur = true;
			}

			else if (pos == new_loc_r)
			{
				broken_r = true;
			}

			else if (pos == new_loc_dr)
			{
				broken_dr = true;
			}

			else if (pos == new_loc_d)
			{
				broken_d = true;
			}

			else if (pos == new_loc_dl)
			{
				broken_dl = true;
			}

			else if (pos == new_loc_l)
			{
				broken_l = true;
			}

			else if (pos == new_loc_ul)
			{
				broken_ul = true;
			}
		}
	}

	for (auto const& piece : pieces_list)
	{
		if (piece->piece_type == "PAWN")
		{
			if (piece->colour != colour)
			{
				ChessPos possible_move_left;
				ChessPos possible_move_right;

				if (piece->colour == WHITE)
				{
					possible_move_left = ChessPos(piece->position.row - 1, piece->position.column - 1);
					possible_move_right = ChessPos(piece->position.row - 1, piece->position.column + 1);
				}

				else
				{
					possible_move_left = ChessPos(piece->position.row + 1, piece->position.column - 1);
					possible_move_right = ChessPos(piece->position.row + 1, piece->position.column + 1);
				}

				if (new_loc_u == possible_move_left || new_loc_u == possible_move_right)
				{
					broken_u = true;
				}

				if (new_loc_ur == possible_move_left || new_loc_ur == possible_move_right)
				{
					broken_ur = true;
				}

				if (new_loc_r == possible_move_left || new_loc_r == possible_move_right)
				{
					broken_r = true;
				}

				if (new_loc_dr == possible_move_left || new_loc_dr == possible_move_right)
				{
					broken_dr = true;
				}

				if (new_loc_d == possible_move_left || new_loc_d == possible_move_right)
				{
					broken_d = true;
				}

				if (new_loc_dl == possible_move_left || new_loc_dl == possible_move_right)
				{
					broken_dl = true;
				}

				if (new_loc_l == possible_move_left || new_loc_l == possible_move_right)
				{
					broken_l = true;
				}

				if (new_loc_ul == possible_move_left || new_loc_ul == possible_move_right)
				{
					broken_ul = true;
				}
			}
		}
	}

	if (!broken_u)
	{
		if (IsLocationValid(new_loc_u))
			tiles_attacking.push_back(new_loc_u);
	}

	if (!broken_ur)
	{
		if (IsLocationValid(new_loc_ur))
			tiles_attacking.push_back(new_loc_ur);
	}

	if (!broken_r)
	{
		if (IsLocationValid(new_loc_r))
			tiles_attacking.push_back(new_loc_r);
	}

	if (!broken_dr)
	{
		if (IsLocationValid(new_loc_dr))
			tiles_attacking.push_back(new_loc_dr);
	}

	if (!broken_d)
	{
		if (IsLocationValid(new_loc_d))
			tiles_attacking.push_back(new_loc_d);
	}

	if (!broken_dl)
	{
		if (IsLocationValid(new_loc_dl))
			tiles_attacking.push_back(new_loc_dl);
	}

	if (!broken_l)
	{
		if (IsLocationValid(new_loc_l))
			tiles_attacking.push_back(new_loc_l);
	}

	if (!broken_ul)
	{
		if (IsLocationValid(new_loc_ul))
			tiles_attacking.push_back(new_loc_ul);
	}
}


bool King::InCheck(std::vector<std::unique_ptr<Piece>>& pieces_list)
{
	for (auto const& piece : pieces_list)
	{
		if (piece->colour == colour)
		{
			continue;
		}

		for (ChessPos pos : piece->tiles_attacking)
		{
			if (pos == position)
			{
				return true;
			}
		}
	}

	return false;
}
