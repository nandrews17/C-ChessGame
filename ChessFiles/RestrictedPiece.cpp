/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "RestrictedPiece.h"
#include "Square.h"
#include "Player.h"
#include "King.h"

/**
 * RestrictedPiece implementation
 */


RestrictedPiece::RestrictedPiece(string color, Square* location):
Piece(color, location) { }


bool RestrictedPiece::moveTo(Square* location, Player* byPlayer,
                                               Player* otherPlayer) {
    bool canMove = false;
    bool inCheck = false;
    Square* pastLocation = this->getLocation();
    Piece* pastOccupant = nullptr;
    if (canMoveTo(location) && byPlayer->getName() == this->getColor()) {
        canMove = true;
        if (location->isOccupied()) {
            pastOccupant = location->getOccupant();
            location->getOccupant()->setLocation(nullptr);
        }
        setLocation(location);
        if (!hasMoved()) {
            _moved = true;
        }
    }
    for (Piece* p : *otherPlayer->getPieces()) {
        if (p->getLocation() != nullptr &&
            p->canMoveTo(byPlayer->getKing()->getLocation())) {
            inCheck = true;
            canMove = false;
            cout << "- " << byPlayer->getName() << " player still in check -"
                    << endl;
        }
    }
    if (inCheck == true) {
        setLocation(pastLocation);
        if (pastOccupant != nullptr) {
            pastOccupant->setLocation(location);
        }
    }
    return canMove;
}


bool RestrictedPiece::hasMoved() {
    return _moved;
}


RestrictedPiece::~RestrictedPiece() { }