/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _GAME_H
#define _GAME_H

#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"


class Game {
public:

/**
 * Constructor for an instance of a Game
 */
Game();

/**
 * Returns the next player
 * @return the next player
 */
Player* getNextPlayer();

/**
 * Returns the opponent of the given player(the only other player in the game)
 * @param player The player one wishes to get the opponent of
 * @return the opponent of the given player
 */
Player* getOpponentOf(Player* player);

/**
 * Returns a reference to the current board object
 */
Board* getBoard();

/**
 * Promoted a pawn to a queen piece
 * @param pawn the pawn to be promoted
 */
void promote(Piece* pawn);

/**
 * Destructor for an instance of a Game
 */
~Game();
private:
    set<Piece*>* _blackPieces;
    set<Piece*>* _whitePieces;
    Player* _whitePlayer;
    Player* _blackPlayer;
    Board* _board;
};

#endif //_GAME_H