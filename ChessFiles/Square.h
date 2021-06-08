/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _SQUARE_H
#define _SQUARE_H

#include <iostream>


class Piece;

class Square {
public:

/**
 * Constructor for a new square at the given rank and file
 * @param rank Row of a board
 * @param file Column of a board
 */
Square(int rank, int file);

/**
 * Returns the rank (row) of a square
 */
int getRank();

/**
 * Returns the file (Column) of a square
 */
int getFile();

/**
 * Returns true if the current square has a piece on it, false otherwise
 */
bool isOccupied();

/**
 * Returns a pointer to the piece on the current square if it exists
 */
Piece* getOccupant();

/**
 * Displays the formatted square and the piece on it if one exists
 */
virtual void display();

/**
 * Places a piece onto a square or takes one off
 * @param occupant The piece to set on the square
 */
void setOccupant(Piece* occupant);

/**
 * Destructor for a new square at the given rank and file
 */
~Square();
private: 
    int _rank;
    int _file;
    Piece* _occupant;
};

#endif //_SQUARE_H