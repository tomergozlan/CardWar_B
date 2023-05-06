//
// Created by Tomer Gozlan on 04/04/2023.
//

#ifndef CARDWAR_B_MAIN_DECK_HPP
#define CARDWAR_B_MAIN_DECK_HPP

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <queue>
#include <vector>
#include <ctime>
#include "card.hpp"


using namespace std;
namespace ariel {

    class Deck {
    private:
        queue <Card> deck;
    public:
        /// Method number 1 : swap function card objects by reference using for shuffle cards.
        void swap(Card &card1, Card &card2);
        /// Method number 2 : Creating a deck of cards consisting of 13 cards of each suit for a total of 52 (unmixed).
        Deck();
        /// Method number 3 : create deck from queue of cards
        Deck(std::queue<Card> cards);
        /// Method number 4 : drawing a card from the top of the deck and returns its value.
        Card getTopCard();
        /// Method number 5 : Return the size of the rest of the deck.
        int size();
        /// Method number 6 : add card to the end of the deck
        void addCard(Card card);
        /// Method number 7 : A union between two queues simulates that one of the players won the war
        void addToWinner(Deck &winning_deck);
        /// Method number 8 : shuffle the deck
        void shuffle();
        /// Method number 9 : Reset deck of player
        void resetDeck();
        /// Method number 10 : Print deck of player for check new demo
        void printDeck();
    };
}
#endif //CARDWAR_B_MAIN_DECK_HPP