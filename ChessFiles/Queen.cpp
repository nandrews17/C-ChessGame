/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Queen.h"
#include "Square.h"
#include "Board.h"

/**
 * Queen implementation
 */


Queen::Queen(string color, Square* location): Piece(color, location){ }


int Queen::getValue() {
    return 0;
}


bool Queen::canMoveTo(Square* location) {
    bool canMove = false;
    if (this->getLocation()->getFile() == location->getFile()) {
        canMove = Board::getInstance()->isClearRank(this->getLocation(),
                location);
    }
    else if (this->getLocation()->getRank() == location->getRank()) {
        canMove = Board::getInstance()->isClearFile(this->getLocation(),
                location);
    }
    else {
        canMove = Board::getInstance()->isClearDiagonal(this->getLocation(),
                location);
    }
    return canMove;
}


void Queen::display() {
    if (getColor() == "white")
    {
        cout << "♕";
    }
    else
    {
        cout << "♛";
    }
}


Queen::~Queen() { }