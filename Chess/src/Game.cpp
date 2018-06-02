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
	sf::Texture black_pawn_texture;

	white_pawn_texture.loadFromFile("Images/White Pawn.png");
	black_pawn_texture.loadFromFile("Images/Black Pawn.png");

	pieces_list.push_back(Pawn(ChessPos(6, 0), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 1), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 2), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 3), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 4), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 5), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 6), WHITE, white_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(6, 7), WHITE, white_pawn_texture, pieces_list));

	pieces_list.push_back(Pawn(ChessPos(1, 0), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 1), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 2), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 3), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 4), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 5), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 6), BLACK, black_pawn_texture, pieces_list));
	pieces_list.push_back(Pawn(ChessPos(1, 7), BLACK, black_pawn_texture, pieces_list));

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
