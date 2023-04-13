/// Created by Tomer Gozlan on 24/03/2023.

#include <iostream>
#include "player.hpp"
#include "deck.hpp"

using namespace std;
namespace ariel{

/// Constructor of the class player.
    Player::Player(std::string name) {
        if (name.empty()) {
            throw runtime_error("Invalid Player name");
        }
        this->name = name;
        this->deck = Deck(queue<Card>());
        this->wonCard = Deck(queue<Card>());
        this->win_number = 0;
        this->draw_number = 0;
        this->lose_number=0;
    }

/// Overloaded operator function for the equality operator ==.
    bool Player::operator==(Player &other) {
        return this->name == other.name;
    }

/// A method that returns the number of cards the player currently has in their hand.
    int Player::stacksize() {
        return this->deck.size();
    }

/// A method that returns the total number of cards that the player has taken so far.
    int Player::cardesTaken() {
        return this->wonCard.size();
    }

///Set the field of Deck
    void Player::setDeck(Deck& newDeck) {
        this->deck = newDeck;
    }

/// getter the field of Deck
    Deck Player::getDeck() {
        return this->deck;
    }

/// getter the field of Deck
    string Player::getName() {
        return this->name;
    }

/// Win increment
    void Player::winIncrement() {
        this->win_number++;
    }

/// Draw increment
    void Player::drawIncrement() {
        this->draw_number++;
    }

///get the field wonDeck
    Deck Player::getWonCard() {
        return this->wonCard;
    }

///set the field wonDeck
    void Player::setWonCard(Deck newDeck) {
        this->wonCard = newDeck;
    }

    void Player::loseIncrement() {
        this->lose_number++;
    }

    double Player::getWinsNum() {
        return this->win_number;
    }

    double Player::getDrawNum() {
        return this->draw_number;
    }

    double Player::getLoseNum() {
        return this->lose_number;
    }
}