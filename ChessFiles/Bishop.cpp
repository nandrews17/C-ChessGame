/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Bishop.h"
#include "Board.h"

/**
 * Bishop implementation
 */


Bishop::Bishop(string color, Square* location): Piece(color, location) { }


int Bishop::getValue() {
    return 0;
}


bool Bishop::canMoveTo(Square* location) {
    return Board::getInstance()->isClearDiagonal(this->getLocation(), location);
}


void Bishop::display() {
    if (getColor() == "white")
    {
        cout << "♗";
    }
    else
    {
        cout << "♝";
    }
}


Bishop::~Bishop() { }