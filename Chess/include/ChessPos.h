#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>

class ChessPos
{
public:
	int row;
	int column;

public:
	ChessPos();
	ChessPos(int row, int column);
	sf::Vector2f ConvertToVec2f();

	ChessPos operator+(const ChessPos& other);
	void operator+=(const ChessPos& other);
};

std::ostream& operator<<(std::ostream& stream, const ChessPos& other)
{
	stream << "ChessPos(" << other.row << ", " << other.column << ")";
	return stream;
}