/**
 * @file card.cpp
 * @brief Implementation of the Card class.
 *
 * This file contains the implementation of the Card class, which represents a playing card
 * with a value and a suit. The class provides methods to get the value and suit of the card,
 * as well as their string representations. It also includes methods for comparing cards and
 * printing them to the console.
 *
 * @author Tomer Gozlan
 * @date 29/03/2023
 */

#include "card.hpp"

using namespace std;
namespace ariel {

    /**
  @brief Constructor for the Card class,This constructor initializes a new Card object with the given value and suit.
  @param value The value of the card.
  @param suit The suit of the card.
  */
    Card::Card(ariel::Value value, ariel::Suit suit) {
        this->value = value;
        this->suit = suit;
    }

/**
@brief Getter function that returns the suit of the card.
@return The suit of the card as an object of the Suit enum.
*/
    Suit Card::getSuit() {
        return this->suit;
    }

/**
@brief This method is a getter function that returns the value field of the card.
@return Value The value of the card.
*/
    Value Card::getValue() {
        return this->value;
    }

/**
@brief Returns the string representation of the card's suit.
@return The string representation of the card's suit.
*/
    string Card::getSuitName() {
        switch (this->suit) {
            case clubs:
                return "Clubs";
            case diamonds:
                return "Diamonds";
            case hearts:
                return "Hearts";
            case spades:
                return "Spades";
        }
    }

/**
@brief Return the string representation of the enum that represents the card's value
@return string The string representation of the enum that represents the card's value
@throw std::out_of_range If the value is invalid
*/
    string Card::getValueName() {
        switch (this->value) {
            case two:
                return "2";
            case three:
                return "3";
            case four:
                return "4";
            case five:
                return "5";
            case six:
                return "6";
            case seven:
                return "7";
            case eight:
                return "8";
            case nine:
                return "9";
            case ten:
                return "10";
            case jack:
                return "Jack";
            case queen:
                return "Queen";
            case king:
                return "King";
            case ace:
                return "Ace";
            default:
                throw std::out_of_range("Value is invalid");
        }
    }

/**
@brief Compare the value of the current card with another card.
@param other The other card to compare to.
@return int Returns 1 if the current card value is 2 and the other card value is 14, "\n" -1 if the current card value is 14 and the other card value is 2,
"\n" -1 if the current card value is smaller than the other card value, "\n" 1 if the current card value is greater than the other card value  "\n"  and 0 if both card values are equal.
*/
    int Card::compare(Card other) {
        if (this->value == 2 && other.value == 14) return 1;
        if (this->value == 14 && other.value == 2) return -1;
        if (this->value < other.value) return -1;
        if (this->value > other.value) return 1;
        else return 0;
    }

/**
@brief Returns a string representation of the card's value and suit.
@return A string in the format "[value] of [suit]".
*/
    string Card::name() {
        return this->getValueName() + " of " + this->getSuitName() + " ";
    }

/**
@brief Prints a string representation of the current Card object to the standard output stream.
*/
    void Card::printCard() {
        std::cout << this->name();
    }

/**
 * @brief Set the value of the card
 * @param value1 the new value of the card
 */
    void Card::setValueCard(Value value1) {
        this->value = value1;
    }

/**
 * @brief Set the suit of the card
 * @param suit1 the new suit of the card
 */
    void Card::setSuitCard(Suit suit1) {
        this->suit = suit1;
    }
}