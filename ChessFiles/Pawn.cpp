/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Pawn.h"
#include "Square.h"

/**
 * Pawn implementation
 */


Pawn::Pawn(string color, Square* location): RestrictedPiece(color, location) { }


int Pawn::getValue() {
    return 0;
}


bool Pawn::canMoveTo(Square* location) {
    bool canMove = false;
    if (getColor() == "white") {
        if (location->getFile() == getLocation()->getFile() &&
           !location->isOccupied()) {
            if ((location->getRank() == getLocation()->getRank() + 1) ||
            (!hasMoved() && location->getRank() ==
                    getLocation()->getRank() + 2)) {
                canMove = true;
            }
        }
        if (location->getFile() - 1 == getLocation()->getFile() ||
            location->getFile() + 1 == getLocation()->getFile()) {
            if (location->getRank() == getLocation()->getRank() + 1 &&
            location->isOccupied()) {
                if (location->getOccupant()->getColor() == "black") {
                    canMove = true;
                }
            }
        }
    }
    else {
        if (location->getFile() == getLocation()->getFile() &&
           !location->isOccupied()) {
            if ((location->getRank() == getLocation()->getRank() - 1) ||
            (!hasMoved() && location->getRank() ==
                    getLocation()->getRank() - 2)) {
                canMove = true;
            }
        }
        if (location->getFile() - 1 == getLocation()->getFile() ||
            location->getFile() + 1 == getLocation()->getFile()) {
            if (location->getRank() == getLocation()->getRank() - 1 &&
            location->isOccupied()) {
                if (location->getOccupant()->getColor() == "white") {
                    canMove = true;
                }
            }
        }
    }
    return canMove;
}


void Pawn::display() {
    if (getColor() == "white")
    {
        cout << "♙" << ends;
    }
    else
    {
        cout << "♟" << ends;
    }
}


Pawn::~Pawn() { }