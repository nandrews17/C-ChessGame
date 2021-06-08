// nandrews17@georgefox.edu
// Assignment 10
// 2019-04-24


/**
 * @file: chess.cpp
 * @author: nandrews17@georgefox.edu
 */
#include "Game.h"
#include "Square.h"


string getInput(Player* player, string str, bool drawOffered, bool inCheck);


/**
 * This function does nothing more than create a chess game and then has the
 * two players play at their own will.
 */
int main(int argc, char* argv[]) {
    Game game;
    string str;
    int turns = 0;
    Square* to;
    Square* from;
    Player* player;
    Square* enPassant;
    Pawn* temporaryPawn;
    Pawn* enPassantPawn;
    bool inCheck;
    bool playerMadeValidMove;
    bool drawOffered = false;
    Square* left = nullptr;
    Square* right = nullptr;

    player = game.getNextPlayer();
    while (turns != -1) {
        playerMadeValidMove = false;
        inCheck = false;
        for (Piece* p : *game.getOpponentOf(player)->getPieces()) {
            if (p->getLocation() != nullptr &&
                p->canMoveTo(player->getKing()->getLocation())) {
                inCheck = true;
            }
        }
        str = getInput(player, str, drawOffered, inCheck);

        // player input validation loop that ends when a valid move occurs
        while (playerMadeValidMove == false) {
            // these first if, else if, else combo determines if input is for checkmate, a draw, or a potential move
            if ((int)str[0] == 61) {
                playerMadeValidMove = true;
                turns = -1;
                cout << "- " << player->getName() <<
                    " player has agreed to a draw -" << endl;
            }
            else if ((int)str[0] == 35) {
                playerMadeValidMove = true;
                turns = -1;
                cout << "- " << player->getName() <<
                    " player checkmate -" << endl;
            }
            else {
                from = game.getBoard()->getSquareAt((int)str[1] - 48,
                                               (int)tolower(str[0]) - 96);
                to = game.getBoard()->getSquareAt((int)str[4] - 48,
                                                 (int)tolower(str[3]) - 96);

                // this if, else combo validates the difference in "draw" input
                if (str.length() == 6 && (int)str[5] != 61) {
                    str = getInput(player, str, drawOffered, inCheck);
                }
                else {
                    if (str.length() == 6 && (int)str[5] == 61) {
                        drawOffered = true;
                    }
                    else {
                        drawOffered = false;
                    }
                    if (from->isOccupied() == true) {
                        // en passant pre-validation occurs in this loop
                        temporaryPawn = nullptr;
                        Pawn* pawn = dynamic_cast<Pawn*>
                                    (from->getOccupant());
                        if (pawn != 0 && !pawn->hasMoved()) {
                                temporaryPawn = pawn;
                        }
                        // en passant is successfully achieved by this loop
                        if (pawn != 0 && (from == left || from == right)) {
                            if (enPassant != nullptr && to == enPassant) {
                                enPassantPawn->setLocation(nullptr);
                                pawn->setLocation(enPassant);
                                playerMadeValidMove = true;
                            }
                        }
                        else if (from->getOccupant()->
                            moveTo(to, player, game.getOpponentOf(player)) ==
                                true) {
                            playerMadeValidMove = true;
                            // below, in this if statement, is the rest of en passant pre-validation
                            enPassant = nullptr;
                            enPassantPawn = nullptr;
                            left = game.getBoard()->getSquareAt
                                (to->getRank(), to->getFile() - 1);
                            right = game.getBoard()->getSquareAt
                                (to->getRank(), to->getFile() + 1);
                            // this just tests if the moved pawn has any enemy pawns that might en passant it
                            if (temporaryPawn != nullptr &&
                                ((left != nullptr && left->isOccupied() &&
                                  dynamic_cast<Pawn*>(left->getOccupant()) != 0)
                                  || (right != nullptr && right->isOccupied() &&
                                  dynamic_cast<Pawn*>(right->getOccupant())
                                   != 0))) {
                                if (to->getRank() + 2 == from->getRank()) {
                                    enPassantPawn = temporaryPawn;
                                    enPassant = game.getBoard()->getSquareAt
                                            (to->getRank() + 1, to->getFile());
                                }
                                else if (to->getRank() - 2 == from->getRank()) {
                                    enPassantPawn = temporaryPawn;
                                    enPassant = game.getBoard()->getSquareAt
                                            (to->getRank() - 1, to->getFile());
                                }
                            }
                        }
                        else {
                            str = getInput(player, str, drawOffered, inCheck);
                        }
                    }

                    else {
                        str = getInput(player, str, drawOffered, inCheck);
                    }
                }
            }
        }

        // for loop checks for any needed pawn promotions each turn
        for (int i = 1; i < 9; i++) {
            if (game.getBoard()->getSquareAt(8, i)->isOccupied() &&
                game.getBoard()->getSquareAt(8, i)->getOccupant()->getColor()
                == "white" && dynamic_cast<Pawn*>(game.getBoard()->
                    getSquareAt(8, i)->getOccupant()) != 0) {
                game.promote(game.getBoard()->getSquareAt(8, i)->getOccupant());
            }
            if (game.getBoard()->getSquareAt(1, i)->isOccupied() &&
                game.getBoard()->getSquareAt(1, i)->getOccupant()->getColor()
                == "black" && dynamic_cast<Pawn*>(game.getBoard()->
                    getSquareAt(1, i)->getOccupant()) != 0) {
                game.promote(game.getBoard()->getSquareAt(1, i)->getOccupant());
            }
        }
        // if else combo checks for player concession or a valid move each turn
        if ((int)str[0] != 61 && (int)str[0] != 35 && from == to &&
                from->getOccupant() == player->getKing()) {
            turns = -1;
            cout << "- " << player->getName() <<
                    " player has conceded -" << endl;
        }
        else if ((int)str[0] != 61 && (int)str[0] != 35) {
            game.getBoard()->display();
            player = game.getOpponentOf(player);
            turns++;
        }
    }
}


/**
 * Validates a user's input until it is within the validity of a chess match
 * such as "a4 a5".
 * @param The player whose turn it is
 * @param The string to store the user input
 * @return The string of user input
 */
string getInput(Player* player, string str, bool drawOffered, bool inCheck) {
    bool notValid = true;
    while (notValid) {
        if (drawOffered) {
            cout << "- draw offered -" << endl;
        }
        if (inCheck) {
            cout << "- " << player->getName() << " player in check -" << endl;
        }
        cout << "Enter your move " << player->getName() << ": " << ends;
        getline(cin, str);
        notValid = (str.length() > 6 || str[2] != ' ' || !isdigit(str[1]) ||
          !isalpha(str[0]) || !isdigit(str[4]) || !isalpha(str[3]) ||
          (int)tolower(str[0]) > 104 || (int)tolower(str[3]) > 104 ||
          (int)tolower(str[0]) < 97 || (int)tolower(str[3]) < 97 ||
          (int)str[1] > 56 || (int)str[4] > 56 || (int)str[1] < 49 ||
                              str.length() < 5 || (int)str[4] < 49);
        if (drawOffered && str.length() == 1 && (int)str[0] == 61) {
            notValid = false;
        }
        if (inCheck == true && str.length() == 1 && (int)str[0] == 35) {
            notValid = false;
        }
    }
    return str;
}