/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"


class Bishop: public Piece {
public:

/**
 * Constructor for a Bishop piece in chess
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
Bishop(string color, Square* location);

/**
 * Returns the integer value of the bishop
 */
int getValue();

/**
 * Checks a given square to see if the bishop can move to it
 * @param location The location on a board to check 
 */
bool canMoveTo(Square* location);

/**
 * Displays the individual Bishop piece
 */
void display();

/**
 * Destructor for a Bishop piece in chess
 */
~Bishop();
};

#endif //_BISHOP_H