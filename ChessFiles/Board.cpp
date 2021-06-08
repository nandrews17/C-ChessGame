/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Square.h"
#include "Board.h"
#include "Piece.h"

/**
 * Board implementation
 */


Board* Board::_instance = nullptr;


Board* Board::getInstance() {
    if (_instance == nullptr) {
        _instance = new Board();
    }
    return _instance;
}


void Board::resetInstance() {
    delete _instance;
    _instance = nullptr;
}


Square* Board::getSquareAt(int rank, int file) {
    Square* square = nullptr;
    if (rank > 0 && rank < 9 && file > 0 && file < 9) {
        square = _squares[rank][file];
    }
    return square;
}


bool Board::isClearRank(Square* from, Square* to) {
    bool clear = true;
    if (to->getRank() > from->getRank()) {
        for (int r = from->getRank() + 1; r < to->getRank(); r++) {
            if (getSquareAt(r, from->getFile())->isOccupied()) {
                clear = false;
            }
        }
    }
    else {
        for (int r = from->getRank() - 1; r > to->getRank(); r--) {
            if (getSquareAt(r, from->getFile())->isOccupied()) {
                clear = false;
            }
        }
    }
    if (from->getFile() != to->getFile() || (to->isOccupied() &&
            to->getOccupant()->getColor() == from->getOccupant()->getColor())) {
        clear = false;
    }
    return clear;
}


bool Board::isClearFile(Square* from, Square* to) {
    bool clear = true;
    if (to->getFile() > from->getFile()) {
        for (int f = from->getFile() + 1; f < to->getFile(); f++) {
            if (getSquareAt(from->getRank(), f)->isOccupied()) {
                clear = false;
            }
        }
    }
    else {
        for (int f = from->getFile() - 1; f > to->getFile(); f--) {
            if (getSquareAt(from->getRank(), f)->isOccupied()) {
                clear = false;
            }
        }
    }
    if (from->getRank() != to->getRank() || (to->isOccupied() &&
            to->getOccupant()->getColor() == from->getOccupant()->getColor())) {
        clear = false;
    }
    return clear;
}


bool Board::isClearDiagonal(Square* from, Square* to) {
    bool clear = true;
    if (to->getRank() > from->getRank() && to->getFile() < from->getFile()) {
        for (int i = 1; i < to->getRank() - from->getRank() + 1; i++) {
            if (from->getFile() - i < 1 || from->getRank() + i > 8) {
                clear = false;
            }
            else {
                if (i < to->getRank() - from->getRank()) {
                    if (getSquareAt(from->getRank() + i, from->getFile() - i)->
                            isOccupied()) {
                        clear = false;
                    }
                }
                else {
                    if (getSquareAt(from->getRank() + i, from->getFile() - i)
                            != to) {
                        clear = false;
                    }
                }
            }
        }
    }
    else if (to->getRank() > from->getRank() && to->getFile() > from->getFile())
    {
        for (int i = 1; i < to->getRank() - from->getRank() + 1; i++) {
            if (from->getFile() + i > 8 || from->getRank() + i > 8) {
                clear = false;
            }
            else {
                if (i < to->getRank() - from->getRank()) {
                    if (getSquareAt(from->getRank() + i, from->getFile() + i)->
                            isOccupied()) {
                        clear = false;
                    }
                }
                else {
                    if (getSquareAt(from->getRank() + i, from->getFile() + i)
                            != to) {
                        clear = false;
                    }
                }
            }
        }
    }
    else if (to->getRank() < from->getRank() && to->getFile() < from->getFile())
    {
        for (int i = 1; i < from->getRank() - to->getRank() + 1; i++) {
            if (from->getFile() - i < 1 || from->getRank() - i < 1) {
                clear = false;
            }
            else {
                if (i < from->getRank() - to->getRank()) {
                    if (getSquareAt(from->getRank() - i, from->getFile() - i)->
                            isOccupied()) {
                        clear = false;
                    }
                }
                else {
                    if (getSquareAt(from->getRank() - i, from->getFile() - i)
                            != to) {
                        clear = false;
                    }
                }
            }
        }
    }
    else if (to->getRank() < from->getRank() && to->getFile() > from->getFile())
    {
        for (int i = 1; i < from->getRank() - to->getRank() + 1; i++) {
            if (from->getFile() + i > 8 || from->getRank() - i < 1) {
                clear = false;
            }
            else {
                if (i < from->getRank() - to->getRank()) {
                    if (getSquareAt(from->getRank() - i, from->getFile() + i)->
                            isOccupied()) {
                        clear = false;
                    }
                }
                else {
                    if (getSquareAt(from->getRank() - i, from->getFile() + i)
                            != to) {
                        clear = false;
                    }
                }
            }
        }
    }
    if (from->getFile() == to->getFile() || from->getRank() == to->getRank() ||
        (to->isOccupied() && to->getOccupant()->getColor() ==
                             from->getOccupant()->getColor())) {
        clear = false;
    }
    return clear;
}


void Board::display() {
    for (int i = 8; i > 0; i--) {
        cout << "+---+---+---+---+---+---+---+---+\n|";
        for (int j = 1; j < 9; j++) {
            getSquareAt(i, j)->display();
        }
        cout << endl;
        if (i == 1) {
            cout << "+---+---+---+---+---+---+---+---+" << endl;
        }
    }
}


Board::Board() {
    for (int i = 1; i < _DIMENSION + 1; i++) {
        for (int j = 1; j <_DIMENSION + 1; j++) {
            _squares[i][j] = new Square(i, j);
        }
    }
}


Board::~Board() {
    for (int i = 1; i < _DIMENSION + 1; i++) {
        for (int j = 1; j <_DIMENSION + 1; j++) {
            delete _squares[i][j];
        }
    }
}