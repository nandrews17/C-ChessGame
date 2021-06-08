/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _ROOK_H
#define _ROOK_H

#include "RestrictedPiece.h"


class Rook: public RestrictedPiece {
public:

/**
 * Constructor for a Rook piece in chess
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
Rook(string color, Square* location);

/**
 * Returns the integer value of the rook
 */
int getValue();

/**
 * Checks a given square to see if the rook can move to it
 * @param location The location on a board to check
 */
bool canMoveTo(Square* location);

/**
 * Displays the individual Rook piece
 */
void display();

/**
 * Destructor for a Rook piece in chess
 */
~Rook();
};

#endif //_ROOK_H