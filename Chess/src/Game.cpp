#include <SFML/Graphics.hpp>
#include <memory>
#include <algorithm>
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
	highlighting = false;
	turn = WHITE;
	Run();
}

Game::~Game()
{
	delete window;
}


void Game::Run()
{	
	pieces_list.reserve(32);
	
	CreatePieces();

	while (window->isOpen())
	{
		HandleEvents();
		Update();
		Draw();
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

		case sf::Event::MouseButtonPressed:

			if (event.mouseButton.button == sf::Mouse::Left)
			{
				HandleMouseClick();
			}

		default:
			break;
		}
	}
}


void Game::Update()
{
	
}


void Game::Draw()
{
	window->clear(BG_COLOUR);

	DrawBoard();

	for (auto const& piece : pieces_list)
	{
		window->draw(*piece);
	}

	for (sf::RectangleShape shape : tiles_to_highlight)
	{
		window->draw(shape);
	}

	for (auto const& piece : pieces_list)
	{
		if (piece->piece_type == "KING")
		{
			if (piece->InCheck(pieces_list))
			{
				sf::RectangleShape shape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
				shape.setFillColor(T_RED);

				shape.setPosition(sf::Vector2f(piece->position.column * TILE_SIZE + TILE_OFFSET, piece->position.row * TILE_SIZE + TILE_OFFSET));

				window->draw(shape);
			}
		}
	}

	window->display();
}


void Game::DrawBoard()
{
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			sf::RectangleShape shape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
			
			if ((row + column) % 2 == 0)
			{
				shape.setFillColor(WHITE);
			}

			else
			{
				shape.setFillColor(GREY);
			}

			shape.setPosition(sf::Vector2f(column * TILE_SIZE + TILE_OFFSET, row * TILE_SIZE + TILE_OFFSET));

			window->draw(shape);
		}
	}
}


void Game::HandleMouseClick()
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);

	if (!highlighting)
	{
		for (auto const& piece : pieces_list)
		{
			if (piece->colour == turn)
			{
				if (piece->getGlobalBounds().contains(sf::Vector2f(mouse_pos.x, mouse_pos.y)))
				{
					tiles_to_highlight.clear();

					for (ChessPos pos : piece->tiles_attacking)
					{
						sf::RectangleShape shape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
						shape.setFillColor(T_RED);

						shape.setPosition(sf::Vector2f(pos.column * TILE_SIZE + TILE_OFFSET, pos.row * TILE_SIZE + TILE_OFFSET));

						tiles_to_highlight.push_back(shape);
					}

					highlighting = true;
					piece_to_move = &(*piece);
				}
			}
		}
	}

	else
	{
		ChessPos clicked_pos(floorf((mouse_pos.y - TILE_OFFSET) / (float)TILE_SIZE), floorf((mouse_pos.x - TILE_OFFSET) / (float)TILE_SIZE));

		if (std::find(piece_to_move->tiles_attacking.begin(), piece_to_move->tiles_attacking.end(), clicked_pos) != piece_to_move->tiles_attacking.end())
		{
			for (int i = 0; i < pieces_list.size(); i++)
			{
				auto& piece = pieces_list[i];

				if (piece->position == clicked_pos)
				{
					pieces_list.erase(pieces_list.begin() + i);
				}
			}

			piece_to_move->MovePiece(clicked_pos, true);
			highlighting = false;
			tiles_to_highlight.clear();

			for (auto& piece : pieces_list)
			{
				piece->GetTilesAttacking(pieces_list);
			}
			
			if (turn == WHITE)
			{
				turn = BLACK;
			}

			else
			{
				turn = WHITE;
			}
		}

		else
		{
			for (auto const& piece : pieces_list)
			{
				if (piece->colour == turn)
				{
					if (piece->getGlobalBounds().contains(sf::Vector2f(mouse_pos.x, mouse_pos.y)))
					{
						tiles_to_highlight.clear();

						for (ChessPos pos : piece->tiles_attacking)
						{
							sf::RectangleShape shape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
							shape.setFillColor(T_RED);

							shape.setPosition(sf::Vector2f(pos.column * TILE_SIZE + TILE_OFFSET, pos.row * TILE_SIZE + TILE_OFFSET));

							tiles_to_highlight.push_back(shape);
						}

						highlighting = true;
						piece_to_move = &(*piece);
					}
				}
			}
		}
	}
}


void Game::CreatePieces()
{
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

	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 0), WHITE, white_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 1), WHITE, white_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 2), WHITE, white_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 3), WHITE, white_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 4), WHITE, white_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 5), WHITE, white_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 6), WHITE, white_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(6, 7), WHITE, white_pawn_texture, pieces_list));

	pieces_list.emplace_back(std::make_unique<Rook>(ChessPos(7, 0), WHITE, white_rook_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Knight>(ChessPos(7, 1), WHITE, white_knight_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Bishop>(ChessPos(7, 2), WHITE, white_bishop_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Queen>(ChessPos(7, 3), WHITE, white_queen_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Bishop>(ChessPos(7, 5), WHITE, white_bishop_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Knight>(ChessPos(7, 6), WHITE, white_knight_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Rook>(ChessPos(7, 7), WHITE, white_rook_texture, pieces_list));

	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 0), BLACK, black_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 1), BLACK, black_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 2), BLACK, black_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 3), BLACK, black_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 4), BLACK, black_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 5), BLACK, black_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 6), BLACK, black_pawn_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Pawn>(ChessPos(1, 7), BLACK, black_pawn_texture, pieces_list));

	pieces_list.emplace_back(std::make_unique<Rook>(ChessPos(0, 0), BLACK, black_rook_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Knight>(ChessPos(0, 1), BLACK, black_knight_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Bishop>(ChessPos(0, 2), BLACK, black_bishop_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Queen>(ChessPos(0, 3), BLACK, black_queen_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Bishop>(ChessPos(0, 5), BLACK, black_bishop_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Knight>(ChessPos(0, 6), BLACK, black_knight_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<Rook>(ChessPos(0, 7), BLACK, black_rook_texture, pieces_list));

	pieces_list.emplace_back(std::make_unique<King>(ChessPos(7, 4), WHITE, white_king_texture, pieces_list));
	pieces_list.emplace_back(std::make_unique<King>(ChessPos(0, 4), BLACK, black_king_texture, pieces_list));
}
