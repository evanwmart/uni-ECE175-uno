//
//  other.h
//  UNOFInalProject
//
//  Created by Evan Martin & Brian Bedrosian

#ifndef other_h
#define other_h
#include <stdbool.h>

#include <stdio.h>

typedef struct card_s {
    char color[7];
    int value;
    char action[15];
    struct card_s *t;   //next card
    struct card_s *h;   //prev card
} card;

//input: the static deck array
//populate the deck array with cards (alternative to loading from file)
void generateDeck(card deck[]);

//function to shuffle an array
//input: the array and the number of undrawn cards left in the deck
void shuffle(card deck[], int size);

//function for the startup sequence
//input: 4 int pointers
void startSeq(int *loadType, int*players, int*gameVar, int *AIP);

//function to load in a deck from file
//input: deck array and file name
bool readDeck(card deck[], char fileName[]);

//function to print a row of 5 cards in a player's hand
//inputs: the index numbers for card #1 and #5 in the row, an array of a player's hand
void printRow(int first, int last, card array[]);

//function to print a players hand
//input: the player's head pointer and the player's number
void printHand(card* *head, int playerNum);

//function to print the last played card (top of discard pile)
//input: the deck array
void printTopCard(card deck[]);

//count the amount of cards in a player's hand
//input: the head pointer of a player's hand
int cardCount(card* *head);

//function to draw a card from the deck to a player's hand & then shift the unplayed cards down 1 in the deck array
//input: the player's respective head pointer, tail pointer, the deck array, the amount of undrawn cards left in the deck
void drawCard(card* *head, card* *tail, card deck[], int *cardsLeft);

// moves the card from the players hand to the discard pile and shifts the discarded cards down in the array
//inputs: the player's head and tail pointers, the index of desired card to play, the deck array, the amount of undrawn cards left, the amount of cards in the discard pile
void playCard(card* *head, card* *tail, int cardPos, card deck[], int* cardsLeft, int *numPlayed);

//prompts the player which card they want to play in their hand and will return the index of chosen card by the player
//inputs: the player's head and tail pointers, the deck array, the player's number
int promptPlayer(card* *head, card deck[], int playerNum);

//check if a selected card is valid to play on the discard pile
//inputs: desired card to play, the top of the discard pile
bool cardCheck(card cardPlayed, card base);

//returns a card in a given player's hand
//inputs: the player's head node, the index position of the desired card
card getCard(card* *head, int pos);

//function to prompt user to change color when a wild card iss played
//input: the top card of the discard pile
void colorChange(card *lastCard);

//run win sequence and prompt user whether they wish to play another game
//input: the winning player's number
bool winSeq(int pturn);

//when the deck has ran out of cards the discard pile will be shifted to the front of the deck array and be shuffled
//inputs: the deck array, number of cards left, number of in discard pile
void resetDeck(card deck[],int *numCards,int *numPlayed);

//asks user if they want to play with an AI, then asks user what player they want the AI to play as
//input: the amount of desired players
int promptAI(int numPlayers);

//run the AI player's turn sequence and implement strategy
//inputs: the AI's head and tail pointers, the deck array, the play direction, the top of the discard pile, the amount of cards left in the deck, the amount of cards in the discard pile
void AITurn(card* *head, card* *tail, card deck[], int *direction, card discard, int *cardsLeft, int *numPlayed);

//function to check if hand has a wild card
bool checkWild(card* *head, int *pos);

//function to check if hand has a card matching the top discard's color
bool checkColor(card* *head, int *pos, char color[]);

//function to check if hand has a card matching the top discard's value
bool checkValue(card* *head, int *pos, int value);

//function to check if hand has a draw four
bool checkFour(card* *head, int *pos);

#endif /* other_h */

/*
 ⠴⠖⠒⠲⠶⠶⠶⠶⠄
 ⠯ ♠ ⠽⠿⠿⠿⠿
 ⠿⠷⠖⠚⠛⠛⠻⠿⠇
 ⠿⠇-----⠸⠿
 ⠿⠿⠷⠶⠶⠖⠚⠻⠇
 ⠿⠿⠿⠿⠯ ♠ ⠽
 ⠙⠛⠛⠛⠛⠓⠒⠚⠁
 */
