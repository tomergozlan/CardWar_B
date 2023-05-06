/// Created by Tomer Gozlan on 04/04/2023.

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <queue>
#include <vector>
#include <ctime>
#include "card.hpp"
#include "deck.hpp"
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
namespace ariel {

/// swap function card objects by reference using for shuffle cards.
    void Deck::swap(Card &card1, Card &card2) {
        Card temp = card1;
        card1 = card2;
        card2 = temp;
    }

/// Creating a deck of cards consisting of 13 cards of each suit for a total of 52 (unmixed).
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

/// create deck from queue of card
    Deck::Deck(queue <Card> cards) {
        this->deck = cards;
    }

/// drawing a card from the top of the deck and returns its value.
    Card Deck::getTopCard() {
        Card card = this->deck.front();
        deck.pop();
        return card;
    }

/// Return the size of the rest of the deck.
    int Deck::size() {
        return (int) deck.size();
    }

/// add card to the end of the deck
    void Deck::addCard(Card card) {
        deck.push(card);
    }

/// A union between two queues simulates that one of the players won the war
    void Deck::addToWinner(Deck &winning_deck) {
        while (winning_deck.size() != 0) {
            deck.push(winning_deck.getTopCard());
        }
    }

/// shuffle the deck
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

/// Reset deck of player
    void Deck::resetDeck() {
        queue <Card> empty_queue;
        std::swap(empty_queue, deck);
    }

    void Deck::printDeck() {
        queue <Card> tempDeck = deck;
        bool isLastCard = false;
        while (!tempDeck.empty()) {
            Card currentCard = tempDeck.front();
            currentCard.printCard();
            if (tempDeck.size() == 1) {
                isLastCard = true;
            }
            tempDeck.pop();
            if (!isLastCard) {
                cout << ",";
            }
        }
        if (isLastCard) {
            cout << ".";

            cout << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
    }
}