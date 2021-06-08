/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <set>


using namespace std;

class Piece;

class King;

class Player {
public:

/**
 * Constructor for a player of a chess game
 * @param name The name of the player
 * @param king The King piece of the player
 * @param pieces The set of pieces to be owned by the player
 */
Player(string name, King* king, set<Piece*>* pieces);

/**
 * Returns the name of the current player
 */
string getName();

/**
 * Returns the King piece of the current player 
 */
King* getKing();

/**
 * Returns the set if pieces belonging to the current player
 */
set<Piece*>* getPieces();

/**
 * Returns true and transitions to the next players turn to move
 */
bool makeMove();

/**
 * Moves a piece of the current player to capture the given enemy player's piece
 * @param piece The enemy's piece to be captured
 */
void capture(Piece* piece);

/**
 * Returns the calculated score of the current player in a chess game
 * @return the calculated score of the current player in a chess game
 */
int calculateScore();

/**
 * Destructor for a player of a chess game
 */
~Player();
private:
    string _name;
    King* _king;
    set<Piece*>* _pieces;
};

#endif //_PLAYER_H