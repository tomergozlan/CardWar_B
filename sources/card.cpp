/// Created by Tomer Gozlan on 29/03/2023

#include "card.hpp"

using namespace std;
namespace ariel{

    /// Method number 1 : The constructor for the Card class.
    Card::Card(ariel::Value value, ariel::Suit suit) {}

/// The getter function that returns the suit field.
Suit Card::getSuit() {
    return this->suit;
}

/// The getter function that returns the value field.
Value Card::getValue() {
    return this->value;
}
/// Return the string of enum that representation the card suit
string Card::getSuitName (Suit card_suit) {
    switch(card_suit) {
        case clubs: return "Clubs";
        case diamonds: return "Diamonds";
        case hearts: return "Hearts";
        case spades: return "Spades";
        default: throw std::out_of_range("Suit value out of range");
    }
}
/// Return the string of enum representation the card value
string Card::getValueName (Value card_value) {
    switch(card_value) {
        case two: return "2";
        case three: return "3";
        case four: return "4";
        case five: return "5";
        case six:  return "6";
        case seven: return "7";
        case eight: return "8";
        case nine: return "9";
        case ten: return "10" ;
        case jack: return "Jack" ;
        case queen: return "Queen" ;
        case king: return "King" ;
        case ace: return "Ace";
        default: throw std::out_of_range("Value is invalid");
    }
}
/// Function that takes another Card object as a parameter and compares it to the current Card object
int Card::compare(Card &other){
    if(this->value == 2 && other.value == 14) return 1;
    if(this->value == 14 && other.value == 2) return -1;
    if(this->value < other.value) return -1;
    else if (this->value > other.value) return 1;
    else return 0 ;
}
/// Returns a string representation of the current Card.
string Card::name() {
    return this->getValueName(value) + " of " + this->getSuitName(suit);
}
/// Prints a string representation of the current Card
void Card::printCard(){
    std::cout<<this->name();
}
}