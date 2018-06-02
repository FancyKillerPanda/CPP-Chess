#include <SFML/Graphics.hpp>
#include "Base.h"
#include "Game.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"


Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chess!");
	Run();
}

Game::~Game()
{
	delete window;
}


void Game::Run()
{	
	std::vector<Piece> pieces_list;
	/*
	for (int i = 0; i < 8; i++)
	{
		//Pawn pawn(ChessPos(6, i), WHITE, "Images/White Pawn.png", pieces_list);
		//pieces_list.push_back(pawn);

		pieces_list.push_back(Pawn(ChessPos(6, i), WHITE, "Images/White Pawn.png", pieces_list));
	}
	
	for (int i = 0; i < 8; i++)
	{
		Pawn pawn(ChessPos(1, i), BLACK, "Images/Black Pawn.png", pieces_list);
		pieces_list.push_back(pawn);
	}
	*/

	sf::Texture white_pawn_texture;
	sf::Texture white_rook_texture;
	sf::Texture white_knight_texture;
	sf::Texture white_bishop_texture;
	sf::Texture white_queen_texture;
	sf::Texture white_king_texture;
	sf::Texture black_pawn_texture;
	sf::Texture black_rook_texture;
	sf::Texture black_knight_texture;
	sf::Texture black_bishop_texture;
	sf::Texture black_queen_texture;
	sf::Texture black_king_texture;

	white_pawn_texture.loadFromFile("Images/White Pawn.png");
	white_rook_texture.loadFromFile("Images/White Rook.png");
	white_knight_texture.loadFromFile("Images/White Knight.png");
	white_bishop_texture.loadFromFile("Images/White Bishop.png");
	white_queen_texture.loadFromFile("Images/White Queen.png");
	white_king_texture.loadFromFile("Images/White King.png");
	black_pawn_texture.loadFromFile("Images/Black Pawn.png");
	black_rook_texture.loadFromFile("Images/Black Rook.png");
	black_knight_texture.loadFromFile("Images/Black Knight.png");
	black_bishop_texture.loadFromFile("Images/Black Bishop.png");
	black_queen_texture.loadFromFile("Images/Black Queen.png");
	black_king_texture.loadFromFile("Images/Black King.png");

	pieces_list.push_back(Pawn(ChessPos(6, 0), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 1), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 2), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 3), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 4), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 5), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 6), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 7), WHITE, white_pawn_texture, pieces_list));

	pieces_list.push_back(Rook(ChessPos(7, 0), WHITE, white_rook_texture, pieces_list));
	pieces_list.push_back(Knight(ChessPos(7, 1), WHITE, white_knight_texture, pieces_list));
	pieces_list.push_back(Bishop(ChessPos(7, 2), WHITE, white_bishop_texture, pieces_list));
	pieces_list.push_back(Queen(ChessPos(7, 3), WHITE, white_queen_texture, pieces_list));
	pieces_list.push_back(King(ChessPos(7, 4), WHITE, white_king_texture, pieces_list));
	pieces_list.push_back(Bishop(ChessPos(7, 5), WHITE, white_bishop_texture, pieces_list));
	pieces_list.push_back(Knight(ChessPos(7, 6), WHITE, white_knight_texture, pieces_list));
	pieces_list.push_back(Rook(ChessPos(7, 7), WHITE, white_rook_texture, pieces_list));

	pieces_list.push_back(Pawn(ChessPos(1, 0), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 1), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 2), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 3), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 4), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 5), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 6), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 7), BLACK, black_pawn_texture, pieces_list));

	pieces_list.push_back(Rook(ChessPos(0, 0), BLACK, black_rook_texture, pieces_list));
	pieces_list.push_back(Knight(ChessPos(0, 1), BLACK, black_knight_texture, pieces_list));
	pieces_list.push_back(Bishop(ChessPos(0, 2), BLACK, black_bishop_texture, pieces_list));
	pieces_list.push_back(Queen(ChessPos(0, 3), BLACK, black_queen_texture, pieces_list));
	pieces_list.push_back(King(ChessPos(0, 4), BLACK, black_king_texture, pieces_list));
	pieces_list.push_back(Bishop(ChessPos(0, 5), BLACK, black_bishop_texture, pieces_list));
	pieces_list.push_back(Knight(ChessPos(0, 6), BLACK, black_knight_texture, pieces_list));
	pieces_list.push_back(Rook(ChessPos(0, 7), BLACK, black_rook_texture, pieces_list));

	while (window->isOpen())
	{
		HandleEvents();
		Update();
		Draw(pieces_list);
	}
}


void Game::HandleEvents()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();

			break;

		case sf::Event::KeyPressed:

			if (event.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}

			break;

		default:
			break;
		}
	}
}


void Game::Update()
{

}


void Game::Draw(std::vector<Piece>& pieces_list)
{
	window->clear(BG_COLOUR);

	for (Piece piece : pieces_list)
	{
		window->draw(piece);
	}

	window->display();
}
