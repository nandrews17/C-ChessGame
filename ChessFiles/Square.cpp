/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Square.h"
#include "Piece.h"

/**
 * Square implementation
 */


Square::Square(int rank, int file) {
    _rank = rank;
    _file = file;
}


int Square::getRank() {
    return _rank;
}


int Square::getFile() {
    return _file;
}


bool Square::isOccupied() {
    return !(_occupant == nullptr);
}


Piece* Square::getOccupant() {
    return _occupant;
}


void Square::display() {
    if (isOccupied()) {
        cout << " ";
        getOccupant()->display();
    }
    else {
        cout << "  ";
    }
    cout << " |";
}


void Square::setOccupant(Piece* newOccupant) {
    _occupant = newOccupant;
}


Square::~Square() {
    if (_occupant != nullptr) {
        _occupant->setLocation(nullptr);
    }
}