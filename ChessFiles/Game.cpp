/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Game.h"
#include "Square.h"
#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

/**
 * Game implementation
 */


Game::Game(): _board(Board::getInstance()) {
    _blackPieces = new set<Piece*>();
    _whitePieces = new set<Piece*>();
    for (int i = 1; i < 9; i++) {
        Pawn* wPawn = new Pawn("white", _board->getSquareAt(2, i));
        Pawn* bPawn = new Pawn("black", _board->getSquareAt(7, i));
        _blackPieces->emplace(bPawn);
        _whitePieces->emplace(wPawn);
    }
    Rook* wRook1 = new Rook("white", _board->getSquareAt(1, 1));
    Rook* wRook2 = new Rook("white", _board->getSquareAt(1, 8));
    Rook* bRook1 = new Rook("black", _board->getSquareAt(8, 1));
    Rook* bRook2 = new Rook("black", _board->getSquareAt(8, 8));
    _blackPieces->emplace(bRook1);
    _blackPieces->emplace(bRook2);
    _whitePieces->emplace(wRook1);
    _whitePieces->emplace(wRook2);
    
    Knight* wKnight1 = new Knight("white", _board->getSquareAt(1, 2));
    Knight* wKnight2 = new Knight("white", _board->getSquareAt(1, 7));
    Knight* bKnight1 = new Knight("black", _board->getSquareAt(8, 2));
    Knight* bKnight2 = new Knight("black", _board->getSquareAt(8, 7));
    _blackPieces->emplace(bKnight1);
    _blackPieces->emplace(bKnight2);
    _whitePieces->emplace(wKnight1);
    _whitePieces->emplace(wKnight2);
    
    Bishop* wBishop1 = new Bishop("white", _board->getSquareAt(1, 3));
    Bishop* wBishop2 = new Bishop("white", _board->getSquareAt(1, 6));
    Bishop* bBishop1 = new Bishop("black", _board->getSquareAt(8, 3));
    Bishop* bBishop2 = new Bishop("black", _board->getSquareAt(8, 6));
    _blackPieces->emplace(bBishop1);
    _blackPieces->emplace(bBishop2);
    _whitePieces->emplace(wBishop1);
    _whitePieces->emplace(wBishop2);
    
    King* wKing = new King("white", _board->getSquareAt(1, 5));
    Queen* wQueen = new Queen("white", _board->getSquareAt(1, 4));
    King* bKing = new King("black", _board->getSquareAt(8, 5));
    Queen* bQueen = new Queen("black", _board->getSquareAt(8, 4));
    _blackPieces->emplace(bKing);
    _blackPieces->emplace(bQueen);
    _whitePieces->emplace(wKing);
    _whitePieces->emplace(wQueen);
    
    _whitePlayer = new Player("white", wKing, _whitePieces);
    _blackPlayer = new Player("black", bKing, _blackPieces);
    _board->display();
}


Player* Game::getNextPlayer() {
    return _whitePlayer;
}


Player* Game::getOpponentOf(Player* player) {
    Player* p;
    if (player->getName() == "white") {
        p = _blackPlayer;
    }
    else {
        p = _whitePlayer;
    }
    return p;
}


Board* Game::getBoard() {
    return _board;
}


void Game::promote(Piece* pawn) {
    Square* square = pawn->getLocation();
    string color = pawn->getColor();
    pawn->setLocation(nullptr);
    Queen* queen = new Queen(color, square);
    if (color == "white") {
        _whitePieces->emplace(queen);
    }
    else {
        _blackPieces->emplace(queen);
    }
}


Game::~Game() {
    for (auto p : *_blackPieces)
    {
        delete p;
    }
    for (auto p : *_whitePieces)
    {
        delete p;
    }
    delete _blackPieces;
    delete _whitePieces;
    delete _blackPlayer;
    delete _whitePlayer;
    _board->resetInstance();
}