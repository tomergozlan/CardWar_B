/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;
using namespace std;

int main() {
//     //Create two players with their names
//   Player p1("Alice");
//   Player p2("Bob");
//
//   Game game(p1,p2);
//   for (int i=0;i<5;i++) {
//    game.playTurn();
//   }
//   game.printLastTurn(); // print the last turn stats. For example:
//                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
//                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
//   cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
//   cout << p2.cardesTaken() << endl; // prints the amount of cards this player has won.
//   game.playAll(); //playes the game untill the end
//   game.printWiner(); // prints the name of the winning player
//   game.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
//   game.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
//}

/**
 * @author Tomer Gozlan
 * @brief new main in order to check that all functions are working properly
 */


    cout << "-----------------------------------------" << endl;
    cout << "Check player class before the game begin:" << endl;
    cout << "-----------------------------------------" << endl;

    Player player1("Tomer");
    Player player2("Gozlan");
    Player player3("Tomer");

    cout << "**********************************************" << endl;
    cout << "Number of cards each player before start game:  " << endl
         << "**********************************************" << endl << player1.getName() << " : "
         << player1.stacksize() << endl << player2.getName() << " : " << player2.stacksize() << endl;
    cout << "****************************************************" << endl;
    cout << "Number of cards taken each player before start game:  " << endl
         << "****************************************************" << endl << player1.getName() << " : "
         << player1.cardesTaken() << endl << player2.getName() << " : " << player2.cardesTaken() << endl;
    cout << "Check if the player's (1,2) name are equal: " << player1.getName() << " == " << player2.getName() << "? "
         << (player1 == player2) << endl;
    cout << "Check if the player's (1,3) name are equal: " << player1.getName() << " == " << player3.getName() << "? "
         << (player1 == player3) << endl;
    cout << "***********************************************" << endl;
    cout << "Check the Deck's players before the game begin: " << endl
         << "***********************************************" << endl << player1.getName() << " : "
         << player1.getDeck().size() << endl << player2.getName() << " : " << player2.getDeck().size() << endl;
    cout << "***********************************************************" << endl;
    cout << "Check statistic info of each player before the game begin: " << endl
         << "***********************************************************" << endl << player1.getName() << " : "
         << "[Wins:" << player1.getWinsNum() << ",Lose:" << player1.getLoseNum() << ",Draw:" << player1.getDrawNum()
         << "]" << endl << player2.getName() << " : " << "[Wins:" << player2.getWinsNum() << ",Lose:"
         << player2.getLoseNum() << ",Draw:" << player2.getDrawNum() << "]" << endl;
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Check player class after play turn game:" << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
    Game game(player1, player2);
    game.playTurn();
    cout << "********************************************" << endl;
    cout << "Number of cards each player after play turn:  " << endl << "********************************************"
         << endl << player1.getName() << " : "
         << player1.stacksize() << endl << player2.getName() << " : " << player2.stacksize() << endl;
    cout << "**************************************************" << endl;
    cout << "Number of cards taken each player after play turn:  " << endl
         << "**************************************************" << endl << player1.getName() << " : "
         << player1.cardesTaken() << endl << player2.getName() << " : " << player2.cardesTaken() << endl;
    cout << "*****************************************" << endl;
    cout << "Check the Deck's players after play turn: " << endl << "*****************************************" << endl
         << player1.getName() << " : " << player1.getDeck().size() << endl << player2.getName() << " : "
         << player2.getDeck().size() << endl;
    cout << "****************************************************" << endl;
    cout << "Check statistic info of each player after play turn: " << endl
         << "****************************************************" << endl << player1.getName() << " : " << "[Wins:"
         << player1.getWinsNum() << ",Lose:" << player1.getLoseNum() << ",Draw:" << player1.getDrawNum() << "]" << endl
         << player2.getName() << " : " << "[Wins:" << player2.getWinsNum() << ",Lose:" << player2.getLoseNum()
         << ",Draw:" << player2.getDrawNum() << "]" << endl;
    cout << endl;
    cout << "------------------" << endl;
    cout << "Check Card class :" << endl;
    cout << "------------------" << endl;
    cout << endl;
    Card card1(ariel::ace, ariel::diamonds);
    Card card2(ariel::two, ariel::clubs);
    cout << "*******************************" << endl;
    cout << "Check the cards value and suit: " << endl << "*******************************" << endl << "Card1: ["
         << card1.getValueName() << "," << card1.getSuitName() << "]" << endl << "Card2 [" << card2.getValueName()
         << "," << card2.getSuitName() << "]" << endl;
    cout << "*******************************" << endl << "Check the print method work properly: " << endl
         << "*******************************" << endl;
    card1.printCard();
    cout << endl;
    card2.printCard();
    cout << endl;
    cout << "*************************" << endl;
    cout << "Check the compare method: " << endl << "*************************" << endl;
    if (card1.compare(card2) == -1) {
        card2.printCard();
        cout << "is greater then ";
        card1.printCard();
        cout << endl;
    } else if (card1.compare(card2) == 1) {
        card1.printCard();
        cout << "is greater then ";
        card2.printCard();
        cout << endl;
    } else
        cout << "are equal" << endl;
    card1.setValueCard(ariel::three);
    cout << "* Set the value of card1 to 3" << endl;

    if (card1.compare(card2) == -1) {
        card2.printCard();
        cout << "is greater then ";
        card1.printCard();
        cout << endl;
    } else if (card1.compare(card2) == 1) {
        card1.printCard();
        cout << "is greater then ";
        card2.printCard();
        cout << endl;
    } else
        cout << "are equal" << endl;

    card2.setValueCard(ariel::three);
    card2.setSuitCard(ariel::spades);

    cout << "* Set the value of card2 to 3 and suit to spades" << endl;
    if (card1.compare(card2) == -1) {
        card2.printCard();
        cout << "is greater then ";
        card1.printCard();
        cout << endl;
    } else if (card1.compare(card2) == 1) {
        card1.printCard();
        cout << "is greater then ";
        card2.printCard();
        cout << endl;
    } else {
        card1.printCard();
        cout << "is equal to ";
        card2.printCard();
        cout << endl;
    }
    cout << endl;
    cout << "------------------" << endl;
    cout << "Check Deck class :" << endl;
    cout << "------------------" << endl;
    cout << endl;
    cout << "***************" << endl;
    cout << "print the deck: " << endl << "***************" << endl;
    Deck deck;
    deck.printDeck();
    Deck deck2;
    cout << endl;
    cout << "*********************************" << endl;
    cout << "Shuffle and print again the deck: " << endl << "*********************************" << endl;;
    deck.shuffle();
    deck.printDeck();
    cout << endl;
    Card topCard = deck.getTopCard();
    cout << "****************" << endl << "The top card is: " << endl << "****************" << endl;
    topCard.printCard();
    cout << endl;
    cout << endl;

    Card newCard(ariel::five, ariel::hearts);
    deck.addCard(newCard);
    cout << "*****************************" << endl;
    cout << "The size of the deck is: " << deck.size() << std::endl;
    cout << "*****************************" << endl;

    cout << endl;
    deck.resetDeck();

    cout << "***********************************" << endl;
    cout << "The size of the deck after reset: " << deck.size() << std::endl << "***********************************"
         << endl;
    cout << endl;
    cout << "************************************************************" << endl;
    deck.addToWinner(deck2);
    cout << "Adding new deck after reset the old one,The new size is: " << deck.size() << endl
         << "************************************************************" << endl;
    cout << endl;
    cout << "************************************************************" << endl;
    cout << "Create a deck from the queue: " << endl;
    cout << "************************************************************" << endl;
    queue <Card> cardQueue;
    cardQueue.push(Card(ariel::ace, ariel::spades));
    cardQueue.push(Card(ariel::two, ariel::diamonds));
    cardQueue.push(Card(ariel::jack, ariel::hearts));
    cardQueue.push(Card(ariel::king, ariel::clubs));
    Deck deck3(cardQueue);
    deck3.printDeck();

    cout << endl;
    cout << "------------------" << endl;
    cout << "Check Game class :" << endl;
    cout << "------------------" << endl;
    cout << endl;

    cout << "********************" << endl;
    cout << "Print the last game: " << endl;
    cout << "********************" << endl;

    game.printLastTurn();
    cout << endl;

    cout << "*********************" << endl;
    cout << "Print the winner name: " << endl;
    cout << "*********************" << endl;
    game.printWiner();
    cout << endl;

    cout << "*****************" << endl;
    cout << "Print the stats: " << endl;
    cout << "*****************" << endl;

    game.printStats();
    cout << endl;
    cout << endl;

    cout << "*****************************" << endl;
    cout << "Print the number of rounds: " << game.getRoundNum() << endl;
    cout << "*****************************" << endl;

    cout << endl;
    cout << "---------------" << endl;
    cout << "Play all games: " << endl;
    cout << "---------------" << endl;
    cout << endl;
    game.playAll();
    cout << "********************" << endl;
    cout << "Print the last game: " << endl;
    cout << "********************" << endl;
    game.printLastTurn();
    cout << endl;
    cout << "********************" << endl;
    cout << "Print the log name: " << endl;
    cout << "********************" << endl;
    game.printLog();
    cout << endl;
    cout << "*****************" << endl;
    cout << "Print the stats: " << endl;
    cout << "*****************" << endl;
    game.printStats();
    cout << endl;
    cout << endl;
    cout << "****************************" << endl;
    cout << "Print the number of rounds: " << endl << "****************************" << endl << game.getRoundNum()
         << endl;
    cout << endl;
    cout << "**********************" << endl;
    cout << "Print the winner name: " << endl;
    cout << "**********************" << endl;
    game.printWiner();
    cout << endl;
}