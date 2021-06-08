/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _PAWN_H
#define _PAWN_H

#include "RestrictedPiece.h"
#include <iostream>


class Pawn: public RestrictedPiece {
public:

/**
 * Constructor for a Pawn piece in chess
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
Pawn(string color, Square* location);

/**
 * Returns the integer value of the pawn
 */
int getValue();

/**
 * Checks a given square to see if the pawn can move to it
 * @param location The location on a board to check
 */
bool canMoveTo(Square* location);

/**
 * Displays the individual pawn piece
 */
void display();

/**
 * Destructor for a Pawn piece in chess
 */
~Pawn();
};

#endif //_PAWN_H