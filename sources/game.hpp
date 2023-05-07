/**
* @file main_game.hpp
* @brief Declaration of the Game class.
*
* This file contains the declaration of the Game class, which represents the game logic for a card game.
* The Game class uses Player and Deck classes to implement the game rules and simulate turns.
* The class also provides methods for printing game stats and logging game actions.
*
* @author Tomer Gozlan
* @date 24/03/2023
*/

#ifndef CARDWAR_B_MAIN_GAME_HPP
#define CARDWAR_B_MAIN_GAME_HPP

#include <iostream>
#include "player.hpp"
#include "deck.hpp"
#include "card.hpp"
#include <stack>
#include <string>


namespace ariel {

    class Game {
    private:
        Player &player1;
        Player &player2;
        stack<string> log;
        bool gameOver;
        double round_number;
    public:
        Game(Player &player1,Player &player2);
        void drawSplit(Deck& deck);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        double getRoundNum();
    };
}

#endif ///CARDWAR_B_MAIN_GAME_HPP