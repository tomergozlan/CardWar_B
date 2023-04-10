/// Created by Tomer Gozlan on 24/03/2023.

#include <iostream>
#include "game.hpp"
#include <string>

using namespace std;
namespace ariel{

/// Safe constructor of the class game.
Game::Game(Player player1, Player player2) noexcept(false):player1(player1), player2(player2)
 {
    Deck mainDeck = Deck();
     this->deckSplit= false;
     splitDeck(mainDeck);
     this->gameOver= false;
     this->round_number=0;
 }

void Game::splitDeck(Deck& deck) {
    deck.shuffle();
    this->player1.getDeck().resetDeck();
    this->player2.getDeck().resetDeck();
    if (deck.size() != 52) {
        throw runtime_error("Invalid number of cards.");
    }
    for (int i = 0; i < 26; i++) {
        Card card1 = deck.getTopCard();
        Card card2 = deck.getTopCard();
        this->player1.getDeck().addCard(card1);
        this->player2.getDeck().addCard(card2);
    }
    this->deckSplit=true;
}

void Game::drawSplit(Deck& deck){
    if (deck.size() == 0 || deck.size() % 2 != 0) {
        throw runtime_error("ERROR ! the deck size is empty or the deck size is odd");
    }
    for (int i = 0; i < deck.size()/2; i++) {
        Card card1 = deck.getTopCard();
        Card card2 = deck.getTopCard();
        player1.getWonCard().addCard(card1);
        player2.getWonCard().addCard(card2);
    }
}
void Game::playTurn() {
    if (player1.getName() == player2.getName()) {
        throw std::invalid_argument("Error: Both players cannot have the same name.");
    }
    if (player1.getName().empty() || player2.getName().empty()) {
        throw std::invalid_argument("Error: Player names cannot be empty.");
    }
    if (player1 == player2) {
        throw std::invalid_argument("Error: Both players cannot be the same object.");
    }
    while (!gameOver) {
        string stats = "";

        Card p1_card = this->player1.getDeck().getTopCard();
        Card p2_card = this->player2.getDeck().getTopCard();

        while (p1_card.compare(p2_card)) {
            round_number++;
            stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " + p2_card.name() +
                    ". " + player2.getName() + " draw";
            log.push(stats);
            player1.drawIncrement();
            player2.drawIncrement();
            Deck tempDeck;
            tempDeck.addCard(p1_card);
            tempDeck.addCard(p2_card);
            if (player1.stacksize() < 1 || player2.stacksize() < 1) {
                drawSplit(tempDeck);
                this->gameOver = true;
                return;
            }
            Card p1_faceDown = player1.getDeck().getTopCard();
            Card p2_faceDown = player2.getDeck().getTopCard();
            tempDeck.addCard(p1_faceDown);
            tempDeck.addCard(p2_faceDown);
            if (player1.stacksize() < 1 || player2.stacksize() < 1) {
                drawSplit(tempDeck);
                this->gameOver = true;
                return;
            }
            p1_card = this->player1.getDeck().getTopCard();
            p2_card = this->player2.getDeck().getTopCard();
            if (p1_card.compare(p2_card) == 1) {
                player1.getWonCard().addToWinner(tempDeck);
                player1.winIncrement();
                player2.loseIncrement();
                return;
            }
            if (p1_card.compare(p2_card) == -1) {
                player2.getWonCard().addToWinner(tempDeck);
                player2.winIncrement();
                player1.loseIncrement();
                return;
            }
        }

        switch (p1_card.compare(p2_card)) {
            case 1 :
                round_number++;
                stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " +
                        p2_card.name() + ". " + player1.getName() + " wins";
                log.push(stats);
                player1.getWonCard().addCard(p1_card);
                player1.getWonCard().addCard(p2_card);
                player1.winIncrement();
                player2.loseIncrement();
                break;
            case -1 :
                round_number++;
                stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " +
                        p2_card.name() + ". " + player2.getName() + " wins";
                log.push(stats);
                player2.getWonCard().addCard(p1_card);
               player2.getWonCard().addCard(p2_card);
                player2.winIncrement();
                player1.loseIncrement();
                break;
        }
    }
}
///
void Game::printLastTurn() {
    if(!log.empty()){
        cout<<log.top()<<endl;
    }
}
///
void Game::playAll() {
    while (!gameOver) {
        playTurn();
        if (player1.stacksize() == 0 || player2.stacksize() == 0) {
            gameOver = true;
        }
    }
}
///
void Game::printWiner() {
    if (player1.getWonCard().size() > player2.getWonCard().size()) {
        cout << player1.getName() << " wins!" << endl;
    } else if (player2.getWonCard().size() > player1.getWonCard().size()) {
        cout << player2.getName() << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
///
void Game::printLog() {
    while (!log.empty()) {
        cout << log.top() << " ,";
        log.pop();
    }
    cout << endl;
}
int Game::getRoundNum() {
    return this->round_number;
}
///
void Game::printStats() {
    cout << player1.getName() << " [Win rate: " << (player1.getWinsNum()/this->round_number)*100<< "%" << ", Cards won: " << player1.getWonCard().size() << ", Draws: " << player1.getDrawNum() << ",  draw rate " << (player1.getDrawNum()/this->round_number)*100<< "%" << "]"<<endl;
    cout << player2.getName() << " [Win rate: " << (player2.getWinsNum()/this->round_number)*100<< "%" << ", Cards won: " << player2.getWonCard().size() << ", Draws: " << player2.getDrawNum() << ",  draw rate " << (player2.getDrawNum()/this->round_number)*100<< "%" << "]";
}
}

