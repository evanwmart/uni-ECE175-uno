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
    struct card_s *t;   //next card
    struct card_s *h;   //prev card
} card;

void shuffle(card deck[], int size);

void readDeck(card deck[], char fileName[]);

void startSeq(int *loadType, int*players, int*gameVar);

void printHand(card head);

void printTopCard(card deck[]);

int cardCount(card head);

void drawCard(card head, card deck[], int *cardsLeft);

card playCard(card head, int cardPos, int *numDisgard);

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
