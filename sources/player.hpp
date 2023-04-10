/// Created by Tomer Gozlan on 24/03/2023.

#ifndef CARDWAR_B_MAIN_PLAYER_HPP
#define CARDWAR_B_MAIN_PLAYER_HPP

#include <iostream>
#include <string.h>
#include <vector>
#include "deck.hpp"

using namespace std;

/// By placing these classes within the ariel namespace, the code ensures that they will have
/// unique names and that they will not conflict with other code that uses the same names.

namespace ariel {
    class Player {
    private:
        std::string name;
        Deck deck;
        Deck wonCard;
        int win_number;
        int draw_number;
        int lose_number;
    public:
        /// A constructor of the class.
        Player(std::string name);
        /// Method number 1 : Returns the number of cards the player currently has in their hand.
        int stacksize();
        /// Method number 2 : Returns the total number of cards that the player has taken so far.
        int cardesTaken();
        /// Method number 3 : Returns the name of the player.
        string getName() ;
        /// Method number 4 : Overloaded operator function for the equality operator ==.
        bool operator==(Player& other);
        /// Method number 5 : Set the field of Deck
        void setDeck(Deck newDeck);
        /// Method number 6 : get the field Deck
        Deck getDeck();
        /// Method number 7 : Win increment
        void winIncrement();
        /// Method number 8 : Draw increment
        void drawIncrement();
        /// Method number 9 : lose increment
        void loseIncrement();
        /// Method number 10 : get the field wonDeck
        Deck getWonCard();
        /// Method number 11 : set the field wonDeck
        void setWonCard(Deck newDeck);
        /// Method number 12 : get the field win_number
        int getWinsNum();
        /// Method number 13 : get the field draw_number
        int getDrawNum();
        /// Method number 14 : get the field lose_number
        int getLoseNum();
    };
}

#endif //CARDWAR_B_MAIN_PLAYER_HPP