/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Piece.h"
#include "Square.h"
#include "Player.h"
#include "King.h"

/**
 * Piece implementation
 */


Piece::Piece(string color, Square* location): _color(color), _location(nullptr)
{
    setLocation(location);
}


int Piece::getValue() {
    return 0;
}


string Piece::getColor() {
    return _color;
}


Square* Piece::getLocation() {
    return _location;
}


void Piece::setLocation(Square* location) {
    if (_location != nullptr) {
        _location->setOccupant(nullptr);
    }
    _location = location;
    if (location != nullptr) {
        location->setOccupant(this);
    }
}


bool Piece::isOnSquare() {
    return !(_location == nullptr);
}


bool Piece::canMoveTo(Square* location) {
    return false;
}


bool Piece::moveTo(Square* location, Player* byPlayer, Player* otherPlayer) {
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


void Piece::display() {
    cout << "!" << endl;
}


Piece::~Piece() {
    setLocation(nullptr);
}