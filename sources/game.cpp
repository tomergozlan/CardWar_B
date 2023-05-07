/**
* @file game.cpp
* @brief Implementation of the Game class, which represents a card game between two players.
*
* This file contains the implementation of the Game class, which represents a simple card game
* between two players. The game consists of a series of rounds, where each round consists of
* the players playing one card each. The player with the higher card wins the round and takes both
* cards. The game continues until one player runs out of cards, at which point the player with
* the most cards wins.
*
* @author Tomer Gozlan
* @date 24/03/2023
*/

#include <iostream>
#include "game.hpp"

using namespace std;
namespace ariel {

/**
* @brief Constructor for the Game class.
* @param player1 A reference to the first player.
* @param player2 A reference to the second player.
* This constructor creates a new deck and divides it equally between the two players' decks.
* It also sets the initial values for the gameOver flag, round_number, and log.
*/
    Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2) {
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
        this->gameOver = false;
        this->round_number = 0;
        this->log = stack<string>();
    }

/**
* @brief A function that splits a given deck equally between the two players.
* @param deck A reference to the deck to split.
* @throw runtime_error This function throws a runtime error if the deck is empty or has an odd number of cards.
* Otherwise, it divides the deck in half and gives one half to each player.
*/
    void ariel::Game::drawSplit(Deck &deck) {
        if (deck.size() == 0 || deck.size() % 2 != 0) {
            throw runtime_error("ERROR ! the deck size is empty or the deck size is odd");
        }
        Deck won1 = player1.getWonCard();
        Deck won2 = player2.getWonCard();

        for (int i = 0; i < deck.size() / 2; i++) {
            Card card1 = deck.getTopCard();
            Card card2 = deck.getTopCard();
            won1.addCard(card1);
            won2.addCard(card2);
        }
        player1.setDeck(won1);
        player2.setDeck(won2);
    }

/**
* @brief Play a turn of the
*
* This function represents a turn of the game, where each player plays a card from the top of their deck
* and the cards are compared. If the cards have the same value, a war is initiated where additional cards
* are drawn and compared until a winner is determined. The winner of the turn takes all the cards played during
* the turn and adds them to their won cards pile. If one of the players runs out of cards during the turn, a draw
* split occurs and the cards are divided equally between the two players.
*
* @throws std::invalid_argument if both players have the same name, if one of the players has an empty name,
* or if both players are the same object
* @throws std::runtime_error if one of the players has an empty deck
*/
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
        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0) {
            throw std::runtime_error("Error: players Cant play without cards.");
        }

        string stats = "";
        Deck deck1 = player1.getDeck();
        Deck deck2 = player2.getDeck();
        Deck won1 = player1.getWonCard();
        Deck won2 = player2.getWonCard();
        Card p1_card = deck1.getTopCard();
        Card p2_card = deck2.getTopCard();
        Card p1_cardc = p1_card;
        Card p2_cardc = p2_card;
        while ((p1_card.compare(p2_card)) == 0) {
            p1_card.setValueCard(ten);
            round_number++;
            stats = player1.getName() + " played " + p1_cardc.name() + player2.getName() + " played " +
                    p2_cardc.name() + "draw";
            player1.drawIncrement();
            player2.drawIncrement();
            Deck tempDeck = Deck(queue<Card>());
            tempDeck.addCard(p1_card);
            tempDeck.addCard(p2_card);
            if (player1.stacksize() < 1 || player2.stacksize() < 1) {
                stats += ". Split";
                drawSplit(tempDeck);
                player1.setDeck(deck1);
                player2.setDeck(deck2);
                return;
            }
            Card p1_faceDown = deck1.getTopCard();
            Card p2_faceDown = deck2.getTopCard();
            player1.setDeck(deck1);
            player2.setDeck(deck2);
            tempDeck.addCard(p1_faceDown);
            tempDeck.addCard(p2_faceDown);
            if (player1.stacksize() < 1 || player2.stacksize() < 1) {
                stats += ". Split";
                drawSplit(tempDeck);
                player1.setDeck(deck1);
                player2.setDeck(deck2);
                return;
            }
            p1_card = deck1.getTopCard();
            p2_card = deck2.getTopCard();
            player1.setDeck(deck1);
            player2.setDeck(deck2);
            tempDeck.addCard(p1_card);
            tempDeck.addCard(p2_card);
            if (p1_card.compare(p2_card) == 1) {
                won1.addToWinner(tempDeck);
                player1.setWonCard(won1);
                player1.winIncrement();
                player2.loseIncrement();
                stats += ". " + player1.getName() + " played " + p1_card.name() + player2.getName() + " played " +
                         p2_card.name() + ". " + player1.getName() + " wins";
                log.push(stats);
                player1.setDeck(deck1);
                player2.setDeck(deck2);
                return;
            }
            if (p1_card.compare(p2_card) == -1) {
                won2.addToWinner(tempDeck);
                player2.setWonCard(won2);
                player2.winIncrement();
                player1.loseIncrement();
                stats += ". " + player1.getName() + " played " + p1_card.name() + player2.getName() + " played " +
                         p2_card.name() + ". " + player2.getName() + " wins";
                log.push(stats);
                player1.setDeck(deck1);
                player2.setDeck(deck2);
                return;
            }
        }

        if ((p1_card.compare(p2_card)) == 1) {
            round_number++;
            stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " + p2_card.name() +
                    ". " + player1.getName() + " wins";
            log.push(stats);
            Deck deck_won_1 = player1.getWonCard();
            deck_won_1.addCard(p1_card);
            deck_won_1.addCard(p2_card);
            player1.setWonCard(deck_won_1);
            player1.winIncrement();
            player2.loseIncrement();
            player1.setDeck(deck1);
            player2.setDeck(deck2);
        } else {
            round_number++;
            stats = player1.getName() + " played " + p1_card.name() + player2.getName() + " played " + p2_card.name() +
                    ". " + player2.getName() + " wins";
            log.push(stats);
            Deck deck_won_2 = player2.getWonCard();
            deck_won_2.addCard(p1_card);
            deck_won_2.addCard(p2_card);
            player2.setWonCard(deck_won_2);
            player2.winIncrement();
            player1.loseIncrement();
            player1.setDeck(deck1);
            player2.setDeck(deck2);
        }
    }

/**
* @brief Prints the last turn that was played in the game.
* This method retrieves the most recent turn that was played in the game from the log of turns and prints it to the console. If the log is empty, nothing will be printed.
*/
    void ariel::Game::printLastTurn() {
        if (!log.empty()) {
            cout << log.top() << endl;
        }
    }

/**
* @brief Plays the game until one of the players runs out of cards.
* This function repeatedly calls the playTurn() function until either
* player1 or player2 has no cards left in their deck.
*/
    void ariel::Game::playAll() {
        while (this->player1.stacksize() != 0 && this->player2.stacksize() != 0) {
            playTurn();
        }
    }

/**
* @brief Determines the winner of the game and prints a message to the console.
* If player 1 has more cards in their won card stack than player 2, then player 1 wins.
* If player 2 has more cards in their won card stack than player 1, then player 2 wins.
* If both players have the same number of cards in their won card stacks, then it is a tie.
*/
    void ariel::Game::printWiner() {
        if (player1.getWonCard().size() > player2.getWonCard().size()) {
            cout << player1.getName() << " wins!" << endl;
        } else if (player2.getWonCard().size() > player1.getWonCard().size()) {
            cout << player2.getName() << " wins!" << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
    }

/**
 * @brief Prints the log of the game.
 * This function prints all the items in the stack log.
 */
    void ariel::Game::printLog() {
        while (!log.empty()) {
            cout << log.top() << " ,";
            log.pop();
        }
        cout << endl;
    }

    /**
* @brief Returns the current round number of the game.
* @return The current round number of the game.
*/

    double ariel::Game::getRoundNum() {
        return this->round_number;
    }

/**
* @brief Prints statistics about the game, including player names, win rates, number of cards won, and draw rates.
* @details The function prints the following statistics for each player: name, win rate, number of cards won, number of draws,
* and draw rate. The win rate and draw rate are calculated as percentages based on the number of rounds played.
*/
    void ariel::Game::printStats() {

        cout << player1.getName() << " [Win rate: " << (player1.getWinsNum() / getRoundNum()) * 100 << "%"
             << ", Cards won: " << player1.getWonCard().size() << ", Draws: " << player1.getDrawNum() << ",  draw rate "
             << (player1.getDrawNum() / this->round_number) * 100 << "%" << "]" << endl;
        cout << player2.getName() << " [Win rate: " << (player2.getWinsNum() / getRoundNum()) * 100 << "%"
             << ", Cards won: " << player2.getWonCard().size() << ", Draws: " << player2.getDrawNum() << ",  draw rate "
             << (player2.getDrawNum() / this->round_number) * 100 << "%" << "]";
    }
}