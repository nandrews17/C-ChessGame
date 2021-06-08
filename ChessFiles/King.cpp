/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "King.h"
#include "Square.h"

/**
 * King implementation
 */


King::King(string color, Square* location): RestrictedPiece(color, location) { }


int King::getValue() {
    return 0;
}


bool King::canMoveTo(Square* location) {
    bool canMove = false;
    if (location->getFile() == this->getLocation()->getFile() + 1 ||
        location->getFile() == this->getLocation()->getFile() - 1 ||
        location->getFile() == this->getLocation()->getFile()) {
        if (location->getRank() == this->getLocation()->getRank() + 1 ||
            location->getRank() == this->getLocation()->getRank() - 1 ||
            location->getRank() == this->getLocation()->getRank()) {
            canMove = true;
        }
    }
    if (location->isOccupied() && location->getOccupant()->getColor() ==
            this->getColor() && location != this->getLocation()) {
        canMove = false;
    }
    return canMove;
}


void King::display() {
    if (getColor() == "white")
    {
        cout << "♔";
    }
    else
    {
        cout << "♚";
    }
}


King::~King() { }