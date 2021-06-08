/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _RESTRICTEDPIECE_H
#define _RESTRICTEDPIECE_H

#include "Piece.h"


class RestrictedPiece: public Piece {
public:

/**
 * Constructor for the general restricted piece
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
RestrictedPiece(string color, Square* location);

/**
 * Picks a piece off its current square and moves it onto another given location
 * @param location The new square location on a board to move to
 * @param byPlayer The player whose piece will be moved
 */
virtual bool moveTo(Square* location, Player* byPlayer, Player* otherPlayer);

/**
 * Returns true if the piece has been previously moved, false otherwise
 */
virtual bool hasMoved();

/**
 * Destructor for the general restricted piece
 */
virtual ~RestrictedPiece();
private:
    bool _moved = false;
};

#endif //_RESTRICTEDPIECE_H