#include "ChessPos.h"
#include <iostream>


ChessPos::ChessPos()
{
	row = 0;
	column = 0;
}


ChessPos::ChessPos(int row, int column)
{
	this->row = row;
	this->column = column;
}

sf::Vector2f ChessPos::ConvertToVec2f()
{
	return sf::Vector2f(column, row);
}

ChessPos ChessPos::operator+(const ChessPos& other)
{
	return ChessPos(row + other.row, column + other.column);
}

void ChessPos::operator+=(const ChessPos& other)
{
	row = row + other.row;
	column = column + other.column;
}

bool ChessPos::operator==(const ChessPos& other)
{
	return row == other.row && column == other.column;
}

bool ChessPos::operator!=(const ChessPos& other)
{
	return row != other.row && column != other.column;
}

std::ostream& ChessPos::operator<<(std::ostream& stream)
{
	stream << "ChessPos(" << row << ", " << column << ")";
	return stream;
}
