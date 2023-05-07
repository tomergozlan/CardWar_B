/**
* @file player.hpp
* @brief Contains the definition of the Player class.
*
* This file contains the declaration of the Player class and its member functions.
* The Player class represents a player in a card game, and has a name, a deck of cards, and
* statistics on the number of wins, draws, and losses.
*
* @author Tomer Gozlan
* @date 24/03/2023
*/

#ifndef CARDWAR_B_MAIN_PLAYER_HPP
#define CARDWAR_B_MAIN_PLAYER_HPP

#include <iostream>
#include <string.h>
#include <vector>
#include "deck.hpp"

using namespace std;
namespace ariel {

    class Player {

    private:

        std::string name;
        Deck deck;
        Deck wonCard;
        double win_number;
        double draw_number;
        double lose_number;

    public:
        Player(std::string name);

        int stacksize();

        int cardesTaken();

        string getName();

        bool operator==(Player &other);

        void setDeck(Deck &newDeck);

        Deck getDeck();

        void winIncrement();

        void drawIncrement();

        void loseIncrement();

        Deck getWonCard();

        void setWonCard(Deck newDeck);

        double getWinsNum();

        double getDrawNum();

        double getLoseNum();
    };
}
#endif //CARDWAR_B_MAIN_PLAYER_HPP