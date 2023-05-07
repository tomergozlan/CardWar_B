/**
* @file player.cpp
* @brief Implementation of the Player class.
*
* This file contains the implementation of the Player class, which represents a player in a card game.
* The Player class is implemented using a Deck class to store the cards in the player's hand and the cards that the player has won.
* The methods are implemented in a way that simulates a card game, where players draw cards from the deck, play them, and win or lose rounds.
* The Player class is an essential part of the card game and is used by other classes to implement the game's logic.
*
* @author Tomer Gozlan
* @date 04/04/2023
*/

#include <iostream>
#include "player.hpp"
#include "deck.hpp"

using namespace std;
namespace ariel {

/**
@brief Constructor for the Player class.
@param name The name of the player.
@throws std::runtime_error if the name is empty.
*/
    Player::Player(std::string name) {
        if (name.empty()) {
            throw runtime_error("Invalid Player name");
        }
        this->name = name;
        this->deck = Deck(queue<Card>());
        this->wonCard = Deck(queue<Card>());
        this->win_number = 0;
        this->draw_number = 0;
        this->lose_number = 0;
    }

/**
@brief Overloaded equality operator.
@param other The other Player object to compare to.
@return True if both objects have the same name, false otherwise.
*/
    bool Player::operator==(Player &other) {
        return this->name == other.name;
    }

/**
@brief Returns the number of cards the player currently has in their hand.
@return The number of cards in the player's deck.
*/
    int Player::stacksize() {
        return this->deck.size();
    }

/**
@brief Returns the total number of cards that the player has taken so far.
@return The number of cards the player has won.
*/
    int Player::cardesTaken() {
        return this->wonCard.size();
    }

/**
@brief Sets the player's deck.
@param newDeck The new deck for the player.
*/
    void Player::setDeck(Deck &newDeck) {
        this->deck = newDeck;
    }

/**
@brief Returns the player's deck.
@return The player's deck.
*/
    Deck Player::getDeck() {
        return this->deck;
    }

/**
@brief Returns the player's name.
@return The player's name.
*/
    string Player::getName() {
        return this->name;
    }

/**
@brief Increments the player's win count.
*/
    void Player::winIncrement() {
        this->win_number++;
    }

/**

@brief Increments the player's draw count.
*/
    void Player::drawIncrement() {
        this->draw_number++;
    }

/**
@brief Getter of the player's won deck.
@return The player's won deck.
*/
    Deck Player::getWonCard() {
        return this->wonCard;
    }

/**
@brief Sets the player's won deck.
@param newDeck The new won deck for the player.
*/
    void Player::setWonCard(Deck newDeck) {
        this->wonCard = newDeck;
    }

/**
@brief Increments the player's lose count.
 */
    void Player::loseIncrement() {
        this->lose_number++;
    }

/**
@brief Returns the player's win count.
@return The player's win count.
*/
    double Player::getWinsNum() {
        return this->win_number;
    }

/**
@brief Returns the player's draw count.
@return The player's draw count.
*/
    double Player::getDrawNum() {
        return this->draw_number;
    }

/**
@brief Returns the player's lose count.
@return The player's lose count.
*/
    double Player::getLoseNum() {
        return this->lose_number;
    }
}