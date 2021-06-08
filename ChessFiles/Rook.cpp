/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Rook.h"
#include "Board.h"
#include "Square.h"

/**
 * Rook implementation
 */


Rook::Rook(string color, Square* location): RestrictedPiece(color, location) { }


int Rook::getValue() {
    return 0;
}


bool Rook::canMoveTo(Square* location) {
    bool canMove = false;
    if (location->getFile() == this->getLocation()->getFile()) {
        canMove = Board::getInstance()->isClearRank(this->getLocation(),
                location);
    }
    else if (location->getRank() == this->getLocation()->getRank()) {
        canMove = Board::getInstance()->isClearFile(this->getLocation(),
                location);
    }
    return canMove;
}


void Rook::display() {
    if (getColor() == "white")
    {
        cout << "♖";
    }
    else
    {
        cout << "♜";
    }
}


Rook::~Rook() { }