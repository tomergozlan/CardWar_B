/**
 * @file deck.cpp
 * @brief Implementation of the Deck class.
 *
 * This file contains the implementation of the Deck class, which represents a deck of cards in a card game.
 * The Deck class is implemented using a queue data structure to store the cards in the deck.
 * The methods are implemented in a way that simulates a card game, where players draw cards from the deck, play them, and win or lose rounds.
 * The Deck class is an essential part of the card game and is used by other classes to implement the game's logic.
 *
 * @author Tomer Gozlan
 * @date 04/04/2023
 */

#include <string>
#include <iostream>
#include <queue>
#include <ctime>
#include "card.hpp"
#include "deck.hpp"
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
namespace ariel {

/**
@brief Constructor for the Deck class.
This constructor creates a standard 52-card deck, with each card having a unique combination of
value and suit. The deck is then shuffled using a random seed based on the current time, and stored
in a queue data structure.
@return A new Deck object.
*/
    Deck::Deck() {
        vector <Card> vector_deck;
        for (int suit = 0; suit <= 3; suit++) {
            for (int value = 2; value <= 14; value++) {
                vector_deck.push_back(ariel::Card(ariel::Value(value), ariel::Suit(suit)));
            }
        }
        /// shuffle the deck.
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::mt19937 g(static_cast<unsigned int>(seed));
        std::shuffle(vector_deck.begin(), vector_deck.end(), g);


        /// Make the deck using queue as data structure.
        for (std::vector<Card>::size_type i = 0; i < vector_deck.size(); i++) {
            deck.push(vector_deck[i]);
        }
    }

/**
@brief Constructs a Deck object from a queue of cards.
This constructor creates a new Deck object with the given queue of cards.
@param cards The queue of cards to be used in the deck.
*/
    Deck::Deck(queue <Card> cards) {
        this->deck = cards;
    }

/**
@brief Get the top card from the deck.
This method retrieves the top card from the deck, which is the card at the front of the queue.
It then removes that card from the queue by popping it.
@return The top card of the deck.
*/
    Card Deck::getTopCard() {
        Card card = this->deck.front();
        deck.pop();
        return card;
    }

/**
@brief Get the number of cards in the deck.
@return The number of cards in the deck.
*/
    int Deck::size() {
        return (int) deck.size();
    }

/**
@brief Adds a card to the bottom of the deck.
@param card The card to be added.
*/
    void Deck::addCard(Card card) {
        deck.push(card);
    }

/**
* @brief Adds all cards from the `winning_deck` to the bottom of the winner deck, simulating a win in battle.
* @param winning_deck The deck of cards to add to the bottom of this deck.
*/
    void Deck::addToWinner(Deck &winning_deck) {
        while (winning_deck.size() != 0) {
            deck.push(winning_deck.getTopCard());
        }
    }

/**
@brief Shuffles the deck of cards by converting it to a vector, shuffling the vector, and then converting it back to a queue.
@note This method modifies the deck of cards.
*/
    void Deck::shuffle() {
        vector <Card> queue_to_vector;
        while (!this->deck.empty()) {
            queue_to_vector.push_back(this->deck.front());
            deck.pop();
        }
        unsigned seed = static_cast<unsigned>(time(NULL));
        std::shuffle(queue_to_vector.begin(), queue_to_vector.end(), std::default_random_engine(seed));
        for (Card &card: queue_to_vector) {
            deck.push(card);
        }
    }

/**
@brief Reset the deck of the player.
This method resets the deck of the player by creating an empty queue and swapping it with the current deck.
*/
    void Deck::resetDeck() {
        queue <Card> empty_queue;
        std::swap(empty_queue, deck);
    }

/**
@brief Prints the cards in the deck.
This function prints the cards in the deck, with four cards per row separated by tabs.
*/
    void Deck::printDeck() {
        queue <Card> tempDeck = deck;
        int counter = 1;
        while (!tempDeck.empty()) {
            Card currentCard = tempDeck.front();
            currentCard.printCard();
            tempDeck.pop();
            if (!tempDeck.empty()) {
                cout << "\t" << "\t";
            }
            if (counter % 4 == 0) {
                cout << endl;
            }
            counter++;
        }
        cout << "." << endl;
        cout
                << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
                << endl;
    }
}