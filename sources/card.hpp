/**
 * @file card.hpp
 * @brief Header file for the Card class, which represents a playing card in a deck of cards.
 * This file contains the declaration of the Card class and its member functions, which are defined in the Card.cpp file.
 * @author Tomer Gozlan
 * @date 29/03/2023
 */

#ifndef CARDWAR_B_MAIN_CARD_HPP
#define CARDWAR_B_MAIN_CARD_HPP

#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    enum Suit {
        diamonds, clubs, spades, hearts
    };
    enum Value {
        two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
    };

    class Card {
    private:
        Suit suit;
        Value value;
    public:
        Card(Value value, Suit suit);

        Suit getSuit();

        Value getValue();

        string getSuitName();

        string getValueName();

        int compare(Card other);

        string name();

        void printCard();

        void setValueCard(Value value1);

        void setSuitCard(Suit suit1);
    };
}
#endif //CARDWAR_B_MAIN_CARD_HPP