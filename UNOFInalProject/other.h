//
//  other.h
//  UNOFInalProject
//
//  Created by Evan Martin on 4/22/22.
//

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

void shuffle(card deck[], int size);

bool readDeck(card deck[], char fileName[]);

void startSeq(int *loadType, int*players, int*gameVar);

void printHand(card head);

void printTopCard(card deck[]);

int cardCount(card head);

void drawCard(card head, card deck[], int *cardsLeft);

void playCard(card head, int cardPos, int *cardsLeft, card deck[]);

int promptPlayer(card head, card deck[]); // printTopCard(), printHand(), cardCount() --- returns desired crd position to play

bool cardCheck(card cardPlayed, card base); //if(cardPlayed.value!=base.value)

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
