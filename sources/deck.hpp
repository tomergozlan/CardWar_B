/**
 * @file deck.hpp
 * @brief Header file for the Deck class, which represents a deck of cards.
 * This file contains the declaration of the Deck class and its member functions, which are defined in the Deck.cpp file.
 * @author Tomer Gozlan
 * @date 29/03/2023
 */
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
        Deck();
        Deck(std::queue<Card> cards);
        Card getTopCard();
        int size();
        void addCard(Card card);
        void addToWinner(Deck &winning_deck);
        void shuffle();
        void resetDeck();
        void printDeck();
    };
}
#endif //CARDWAR_B_MAIN_DECK_HPP