/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _PIECE_H
#define _PIECE_H

#include <string>
#include <cstring>
#include <iostream>


using namespace std;

class Square;

class Player;

class Piece {
public:

/**
 * Constructor for an general piece object
 * @param color The color (team) of the piece
 * @param location The initial location to place the piece on a board
 */
Piece(string color, Square* location);

/**
 * Getter that will return the value of a piece
 */
virtual int getValue();

/**
 * Returns the color (team) of a piece
 */
string getColor();

/**
 * Returns the location on a board of a piece
 */
Square* getLocation();

/**
 * Places a piece onto the given square
 * @param location The square on a board that a piece will be set to
 */
void setLocation(Square* location);

/**
 * Returns true if a piece is on a square (not taken), false otherwise
 */
bool isOnSquare();

/**
 * Checks a given square to see if the piece can move to it
 * @param location The location on a board to check
 */
virtual bool canMoveTo(Square* location);

/**
 * Picks a piece off its current square and moves it onto another given location
 * @param location The new square location on a board to move to
 * @param byPlayer The player whose piece will be moved
 */
virtual bool moveTo(Square* location, Player* byPlayer, Player* otherPlayer);

/**
 * Displays the current piece
 */
virtual void display();

/**
 * Destructor for an general piece object
 */
virtual ~Piece();
private:
    string _color;
    Square* _location;
};

#endif //_PIECE_H