/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _KING_H
#define _KING_H

#include "RestrictedPiece.h"


class King: public RestrictedPiece {
public:

/**
 * Constructor for a King piece in chess
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
King(string color, Square* location);

/**
 * Returns the integer value of the king
 */
int getValue();

/**
 * Checks a given square to see if the king can move to it
 * @param location The location on a board to check
 */
bool canMoveTo(Square* location);

/**
 * Displays the individual King piece
 */
void display();

/**
 * Destructor for a King piece in chess
 */
~King();
};

#endif //_KING_H