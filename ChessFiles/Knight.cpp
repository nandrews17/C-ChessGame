/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Knight.h"
#include "Square.h"

/**
 * Knight implementation
 */


Knight::Knight(string color, Square* location): Piece(color, location) { }


int Knight::getValue() {
    return 0;
}


bool Knight::canMoveTo(Square* location) {
    bool canMove = false;
    if (location->getRank() == this->getLocation()->getRank() + 1  &&
            (location->getFile() == this->getLocation()->getFile() + 2 ||
             location->getFile() == this->getLocation()->getFile() - 2)) {
        canMove = true;
    }
    else if (location->getRank() == this->getLocation()->getRank() - 1  &&
            (location->getFile() == this->getLocation()->getFile() + 2 ||
             location->getFile() == this->getLocation()->getFile() - 2)) {
        canMove = true;
    }
    else if (location->getFile() == this->getLocation()->getFile() + 1  &&
            (location->getRank() == this->getLocation()->getRank() + 2 ||
             location->getRank() == this->getLocation()->getRank() - 2)) {
        canMove = true;
    }
    else if (location->getFile() == this->getLocation()->getFile() - 1  &&
            (location->getRank() == this->getLocation()->getRank() + 2 ||
             location->getRank() == this->getLocation()->getRank() - 2)) {
        canMove = true;
    }
    if (location->isOccupied() && location->getOccupant()->getColor() ==
            this->getColor()) {
        canMove = false;
    }
    return canMove;
}


void Knight::display() {
    if (getColor() == "white")
    {
        cout << "♘";
    }
    else
    {
        cout << "♞";
    }
}


Knight::~Knight() { }