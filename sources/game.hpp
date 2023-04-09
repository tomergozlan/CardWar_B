/// Created by Tomer Gozlan on 3/24/23.

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
        Player player1;
        Player player2;
        stack<string> log;
        bool gameOver;
        bool deckSplit;
        int round_number;
    public:
        Game(Player player1,Player player2); /// A constructor of the class.
        void splitDeck(Player& player1,Player& player2); /// Split the deck of 2 players - 26 to each
        void drawSplit(Deck& deck);/// split the deck in case of draw;
        void playTurn();/// Simulates a single turn in the game.
        void printLastTurn();/// Print the last turn stats.
        void playAll();/// Playes the game untill the end.
        void printWiner();/// Prints the name of the winning player.
        void printLog();/// Prints all the turns played one line per turn (same format as game.printLastTurn()).
        void printStats();/// For each player prints basic statistics.
        int getRoundNum();
    };
}

#endif ///CARDWAR_B_MAIN_GAME_HPP
