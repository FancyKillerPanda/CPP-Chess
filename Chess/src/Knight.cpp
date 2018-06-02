#include <SFML/Graphics.hpp>
#include "Knight.h"
#include "ChessPos.h"
#include "Base.h"


Knight::Knight(ChessPos pos, sf::Color piece_colour, const sf::Texture& texture, std::vector<Piece>& pieces_list) : Piece(pos, piece_colour, texture)
{
	GetTilesAttacking(pieces_list);
}


void Knight::GetTilesAttacking(std::vector<Piece>& pieces_list)
{
	tiles_attacking.clear();

	bool up_left_broken = false;
	bool up_right_broken = false;
	bool right_up_broken = false;
	bool right_down_broken = false;
	bool down_right_broken = false;
	bool down_left_broken = false;
	bool left_down_broken = false;
	bool left_up_broken = false;

	for (Piece piece : pieces_list)
	{
		if (piece.position == ChessPos(position.row - 2, position.column - 1))
		{
			if (piece.colour == colour)
				up_left_broken = true;
		}

		else if (piece.position == ChessPos(position.row - 2, position.column + 1))
		{
			if (piece.colour == colour)
				up_right_broken = true;
		}

		else if (piece.position == ChessPos(position.row - 1, position.column + 2))
		{
			if (piece.colour == colour)
				right_up_broken = true;
		}
		
		else if (piece.position == ChessPos(position.row + 1, position.column + 2))
		{
			if (piece.colour == colour)
				right_down_broken = true;
		}

		else if (piece.position == ChessPos(position.row + 2, position.column + 1))
		{
			if (piece.colour == colour)
				down_right_broken = true;
		}
		
		else if (piece.position == ChessPos(position.row + 2, position.column - 1))
		{
			if (piece.colour == colour)
				down_left_broken = true;
		}

		else if (piece.position == ChessPos(position.row - 1, position.column - 2))
		{
			if (piece.colour == colour)
				left_down_broken = true;
		}

		else if (piece.position == ChessPos(position.row + 1, position.column - 2))
		{
			if (piece.colour == colour)
				left_up_broken = true;
		}
	}

	ChessPos new_loc;

	if (!up_left_broken)
	{
		new_loc = ChessPos(position.row - 2, position.column - 1);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}

	if (!up_right_broken)
	{
		new_loc = ChessPos(position.row - 2, position.column + 1);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}

	if (!right_up_broken)
	{
		new_loc = ChessPos(position.row - 1, position.column + 2);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}

	if (!right_down_broken)
	{
		new_loc = ChessPos(position.row + 1, position.column + 2);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}

	if (!down_right_broken)
	{
		new_loc = ChessPos(position.row + 2, position.column + 1);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}

	if (!down_left_broken)
	{
		new_loc = ChessPos(position.row + 2, position.column - 1);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}

	if (!left_down_broken)
	{
		new_loc = ChessPos(position.row - 1, position.column - 2);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}

	if (!left_up_broken)
	{
		new_loc = ChessPos(position.row + 1, position.column - 2);

		if (IsLocationValid(new_loc))
		{
			tiles_attacking.push_back(new_loc);
		}
	}
}