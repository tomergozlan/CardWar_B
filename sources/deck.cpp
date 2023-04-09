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

using namespace std;
using namespace ariel;

/// swap function card objects by reference using for shuffle cards.
    void Deck::swap(Card &card1, Card &card2) {
        Card temp = card1;
        card1 = card2;
        card2 = temp;
    }
    /// Creating a deck of cards consisting of 13 cards of each suit for a total of 52 (unmixed).
    Deck::Deck() {
        vector<Card> vector_deck;
        for (Suit suit : {diamonds , hearts , spades , clubs}) {
            for (int value = 1; value <= 13; value++) {
                vector_deck.push_back(Card(value,suit));
            }
        }
        /// shuffle the deck.
        for (int i = vector_deck.size()-1; i > 0; i--) {
            int j = rand() % (i + 1);
                swap(vector_deck[i], vector_deck[j]);
            }
        /// Make the deck using queue as data structure.
        for (int i = 0; i < vector_deck.size(); i++) {
            deck.push(vector_deck[i]);
          }
        }
        /// create deck from queue of card
        Deck::Deck(queue<Card> cards){
        this->deck = cards;
    }
    /// drawing a card from the top of the deck and returns its value.
    Card Deck::getTopCard() {
        Card card = deck.front();
        deck.pop();
        return card;
    }
    /// Return the size of the rest of the deck.
     int Deck::size() {
        return (int) deck.size();
    }
    /// add card to the end of the deck
    void Deck::addCard(Card card){
        deck.push(card);
    }
    /// A union between two queues simulates that one of the players won the war
    void Deck::addToWinner(Deck& deck,Deck& winning_deck){
        while (winning_deck.size() != 0) {
            deck.addCard(winning_deck.getTopCard());
        }
    }
    /// shuffle the deck
    void Deck::shuffle () {
        vector<Card> queue_to_vector;
        while (!this->deck.empty()) {
            queue_to_vector.push_back(this->deck.front());
            deck.pop();
        }
        shuffle(queue_to_vector.begin(), queue_to_vector.end(), default_random_engine(time(NULL)));
        for (Card& card : queue_to_vector) {
            deck.push(card);
        }
    }
/// Reset deck of player
void Deck::resetDeck(){
     queue<Card> emptyDeck;
    this->deck=emptyDeck;
    }