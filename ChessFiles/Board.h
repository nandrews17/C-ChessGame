/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>


using namespace std;

class Square;

class Board {
public:

/**
 * Returns a new instance of a board by constructing a new one
 * @return reference to a new board instance
 */
static Board* getInstance();

/**
 * Resets instance of a board by deleting the old instance
 */
static void resetInstance();

/**
 * Returns a pointer to the square at the given rank and file
 * @param rank Row
 * @param file Column
 */
Square* getSquareAt(int rank, int file);

/**
 * Returns true if the horizontal move is allowed, false otherwise
 * @param from Starting square of a piece
 * @param to Ending square of a piece
 */
bool isClearRank(Square* from, Square* to);

/**
 * Returns true if the vertical move is allowed, false otherwise
 * @param from Starting square of a piece
 * @param to Ending square of a piece
 */
bool isClearFile(Square* from, Square* to);

/**
 * Returns true if the diagonal move is allowed, false otherwise
 * @param from Starting square of a piece
 * @param to Ending square of a piece
 */
bool isClearDiagonal(Square* from, Square* to);

/**
 * Displays the formatted squares of the board
 */
void display();

/**
 * Destructor for an existing board
 */
~Board();
private: 
    int _DIMENSION = 8;
    static Board* _instance;
    Square* _squares[9][9];

/**
 * Private constructor for a new board
 */
Board();
};

#endif //_BOARD_H