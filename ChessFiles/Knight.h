/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"


class Knight: public Piece {
public:

/**
 * Constructor for a Knight piece in chess
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
Knight(string color, Square* location);

/**
 * Returns the integer value of the knight
 */
int getValue();

/**
 * Checks a given square to see if the knight can move to it
 * @param location The location on a board to check
 */
bool canMoveTo(Square* location);

/**
 * Displays the individual Knight piece
 */
void display();

/**
 * Destructor for a Knight piece in chess
 */
~Knight();
};

#endif //_KNIGHT_H