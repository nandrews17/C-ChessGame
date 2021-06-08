/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _QUEEN_H
#define _QUEEN_H

#include "Piece.h"


class Queen: public Piece {
public:

/**
 * Constructor for a Queen piece in chess
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
Queen(string color, Square* location);

/**
 * Returns the integer value of the queen
 */
int getValue();

/**
 * Checks a given square to see if the queen can move to it
 * @param location The location on a board to check
 */
bool canMoveTo(Square* location);

/**
 * Displays the individual Queen piece
 */
void display();

/**
 * Destructor for a Queen piece in chess
 */
~Queen();
};

#endif //_QUEEN_H