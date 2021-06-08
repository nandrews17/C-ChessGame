/**
 * Project Chess
 * @author Nathan Andrews
 * @mastermind Brian R. Snider 
 */


#include "Player.h"
#include "Piece.h"
#include "King.h"

/**
 * Player implementation
 */


Player::Player(string name, King* king, set<Piece*>* pieces): _name(name),
                                                _king(king), _pieces(pieces) { }


string Player::getName() {
    return _name;
}


King* Player::getKing() {
    return _king;
}


set<Piece*>* Player::getPieces() {
    return _pieces;
}


bool Player::makeMove() {
    return false;
}


void Player::capture(Piece* piece) {

}


int Player::calculateScore() {
    return 0;
}


Player::~Player() { }