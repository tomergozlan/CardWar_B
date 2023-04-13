/// Created by Tomer Gozlan on 24/03/2023.

#include <iostream>
#include "game.hpp"
#include <string>

using namespace std;
namespace ariel{

/// Safe constructor of the class game.
Game::Game(Player &player1, Player &player2) : player1(player1) , player2(player2)
 {
    Deck deck = Deck();
    Deck deck1 = player1.getDeck();
    Deck deck2 = player2.getDeck();

     for (int i = 0; i < 26; i++) {
         Card card1 = deck.getTopCard();
         Card card2 = deck.getTopCard();
         deck1.addCard(card1);
         deck2.addCard(card2);
     }
     player1.setDeck(deck1);
     player2.setDeck(deck2);

     this->gameOver= false;
     this->round_number=0;
     this->log = stack<string>();
 }

void ariel::Game::drawSplit(Deck& deck){
    if (deck.size() == 0 || deck.size() % 2 != 0) {
        throw runtime_error("ERROR ! the deck size is empty or the deck size is odd");
    }
    Deck won1 = player1.getWonCard();
    Deck won2 = player2.getWonCard();

    for (int i = 0; i < deck.size()/2; i++) {
        Card card1 = deck.getTopCard();
        Card card2 = deck.getTopCard();
        won1.addCard(card1);
        won2.addCard(card2);
    }
    player1.setDeck(won1);
    player2.setDeck(won2);
}

void ariel::Game::playTurn() {
    if (player1.getName() == player2.getName()) {
        throw std::invalid_argument("Error: Both players cannot have the same name.");
    }
    if (player1.getName().empty() || player2.getName().empty()) {
        throw std::invalid_argument("Error: Player names cannot be empty.");
    }
    if (&player1 == &player2) {
        throw std::invalid_argument("Error: Both players cannot be the same object.");
    }

    string stats = "";
    Deck deck1 = player1.getDeck();
    Deck deck2 = player2.getDeck();
    Card p1_card = deck1.getTopCard();
    Card p2_card = deck2.getTopCard();
    p1_card.printCard();
    p2_card.printCard();
    while ((p1_card.compare(p2_card)) == 0) {
        p1_card.setValueCard(ten);
        round_number++;
            stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " + p2_card.name() +". " + player2.getName() + " draw";
            cout<<"@@@@@@@@@@@@"<<endl;
            player1.drawIncrement();
            player2.drawIncrement();
            Deck tempDeck = Deck(queue<Card>());
            tempDeck.addCard(p1_card);
            tempDeck.addCard(p2_card);
                if (player1.stacksize() < 1 || player2.stacksize() < 1) {
                    drawSplit(tempDeck);
                    return;
                }
            Card p1_faceDown = deck1.getTopCard();
            Card p2_faceDown = deck2.getTopCard();
            player1.setDeck(deck1);
            player2.setDeck(deck2);
            tempDeck.addCard(p1_faceDown);
            tempDeck.addCard(p2_faceDown);
                if (player1.stacksize() < 1 || player2.stacksize() < 1) {
                    drawSplit(tempDeck);
                    return;
                }
            p1_card = deck1.getTopCard();
            p2_card = deck2.getTopCard();
            player1.setDeck(deck1);
            player2.setDeck(deck2);
                if (p1_card.compare(p2_card) == 1) {
                    Deck won1 = player1.getWonCard();
                    won1.addToWinner(tempDeck);
                    player1.setWonCard(won1);
                    player1.winIncrement();
                    player2.loseIncrement();
                    stats += player1.getName() + " played " + p1_card.name() + player2.getName() + " played " +p2_card.name() + ". " + player1.getName() + " wins";
                    log.push(stats);
                    return;
                }
                if (p1_card.compare(p2_card) == -1) {
                    Deck won2 = player2.getWonCard();
                    won2.addToWinner(tempDeck);
                    player2.setWonCard(won2);
                    player2.winIncrement();
                    player1.loseIncrement();
                    stats += player1.getName() + " played " + p1_card.name() + player2.getName() + " played " +p2_card.name() + ". " + player2.getName() + " wins";
                    log.push(stats);
                    return;
                }
        }

         if ((p1_card.compare(p2_card))==1) {
            round_number++;
            stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " + p2_card.name() + ". " + player1.getName() + " wins";
            log.push(stats);
            Deck deck1 = player1.getWonCard();
            deck1.addCard(p1_card);
            deck1.addCard(p2_card);
            player1.setWonCard(deck1);
            player1.winIncrement();
            player2.loseIncrement();
        }
        else{
                round_number++;
                stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " +p2_card.name() + ". " + player2.getName() + " wins";
                log.push(stats);
                Deck deck2 = player2.getWonCard();
                deck2.addCard(p1_card);
                deck2.addCard(p2_card);
                player2.setWonCard(deck2);
                player2.winIncrement();
                player1.loseIncrement();
        }
    }

///
void ariel::Game::printLastTurn() {
    if(!log.empty()){
        cout<<log.top()<<endl;
    }
}
///
void ariel::Game::playAll() {
    while (!gameOver) {
        playTurn();
        if (player1.stacksize() == 0 || player2.stacksize() == 0) {
            gameOver = true;
        }
    }
}
///
void ariel::Game::printWiner() {
    if (player1.getWonCard().size() > player2.getWonCard().size()) {
        cout << player1.getName() << " wins!" << endl;
    } else if (player2.getWonCard().size() > player1.getWonCard().size()) {
        cout << player2.getName() << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
///
void ariel::Game::printLog() {
    while (!log.empty()) {
        cout << log.top() << " ,";
        log.pop();
    }
    cout << endl;
}
int ariel::Game::getRoundNum() {
    return this->round_number;
}
///
void ariel::Game::printStats() {
    cout << player1.getName() << " [Win rate: " << (player1.getWinsNum()/this->round_number)*100<< "%" << ", Cards won: " << player1.getWonCard().size() << ", Draws: " << player1.getDrawNum() << ",  draw rate " << (player1.getDrawNum()/this->round_number)*100<< "%" << "]"<<endl;
    cout << player2.getName() << " [Win rate: " << (player2.getWinsNum()/this->round_number)*100<< "%" << ", Cards won: " << player2.getWonCard().size() << ", Draws: " << player2.getDrawNum() << ",  draw rate " << (player2.getDrawNum()/this->round_number)*100<< "%" << "]";
}
}

