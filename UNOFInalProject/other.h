//
//  other.h
//  UNOFInalProject
//
//  Created by Evan Martin on 4/22/22.
//

#ifndef other_h
#define other_h

#include <stdio.h>

typedef struct card_s {
    char color;
    int value;
    char action[15];
    struct card_s *t;   //next node
    struct card_s *h;   //prev node
    int position;
} card;

void shuffle(card deck[], int size);

void readDeck(card deck[], char fileName[]);

void startSeq(int *loadType, int*players, int*gameVar);

void printHand(card head);

void printTopCard(card deck[]);

int cardCount(card head);

void drawCard(card head, card deck[], int *cardsLeft); //moves 1 card from the top of the deck into a player's hand (linked list)
// the ^ input is the player's head card

#endif /* other_h */

/*
 ⠴⠖⠒⠲⠶⠶⠶⠶⠄
 ⠯ ♠ ⠽⠿⠿⠿⠿
 ⠿⠷⠖⠚⠛⠛⠻⠿⠇
 ⠿⠇ SKIP⠸⠿
 ⠿⠿⠷⠶⠶⠖⠚⠻⠇
 ⠿⠿⠿⠿⠯ ♠ ⠽
 ⠙⠛⠛⠛⠛⠓⠒⠚⠁
 */
