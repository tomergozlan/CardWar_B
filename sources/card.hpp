/// Created by Tomer Gozlan on 29/03/2023.

#ifndef CARDWAR_B_MAIN_CARD_HPP
#define CARDWAR_B_MAIN_CARD_HPP

#include <iostream>
#include <string>

using namespace std;

namespace ariel {
enum Suit {diamonds ,clubs,spades, hearts};
enum Value {two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

    class Card {
    private:
        Suit suit;
        Value value;
    public:
        /// Method number 1 : The constructor for the Card class.
        Card(Value value,Suit suit);
        /// Method number 2 : The getter function that returns the suit field.
        Suit getSuit();
        /// Method number 3 : The getter function that returns the value field.
        Value getValue();
        /// Method number 4 : Return the string of enum that representation the card suit
        string getSuitName(Suit card_suit);
        /// Method number 5 : Return the string of enum representation the card value
        string getValueName(Value card_value);
        /// Method number 6 : Function that takes another Card object as a parameter and compares it to the current Card object
        int compare(Card& other);
        /// Method number 7 : Returns a string representation of the current Card.
        string name();
        /// Method number 8 : Prints a string representation of the current Card
        void printCard();

        void setValueCard(Value value1);
        void setSuitCard(Suit suit1);


    };
}
#endif //CARDWAR_B_MAIN_CARD_HPP
