//
//  main.c
//  UNOFInalProject
//
//  Created by Evan Martin on 4/21/22.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "other.h"
#include <assert.h>
#include <stdbool.h>
#define SIZE 100

int main (void)
{
    
    /*
    int loadType = 0, numPlayers = 0, gameVar = 0, cardsLeft = 108;
    int* loadPt = &loadType;
    int* playersPt = &numPlayers;
    int* gameVarPt = &gameVar;
    int *numCards = &cardsLeft;
    card deck[108];
    
    startSeq(loadPt, playersPt, gameVarPt);
     
    card *player;
    player = (card*)calloc(numPlayers, sizeof(card));
    for (int i = 0; i < numPlayers; i++)
    {
        player[i].value = i+1;
        player[i].h = NULL;
        player[i].t = NULL;
    }
    
    for(int i = 0; i < 7; i++)
    {
        for (int j = 0; j < numPlayers; j++)
        {
            drawCard(player[i], deck, numCards);
        }
    }
    
    bool win = false;
    //int pturn = 0;
    //int pdirection = 1;
    while(!win)
    {
        //promptPlayer(discard, players[turn]);
        /*
     player selects card
        move card to played cards
        remove card from players hand
     
     check players hand amount
        if zero set win to true
     
     read card and determine next player and action
         */
        
    //}

    card deck[108];
    char fileName[50];
    printf("Enter file name:");
    fgets(fileName, 50, stdin);
    fileName[strlen(fileName) - 1] = '\0';
    if(readDeck(deck, fileName))
    {
        for(int i = 0; i < 108; i++)
        {
            printf("%d%s ", deck[i].value, deck[i].color);
        }
    }
    /*
     

     void readDeck(card deck[], char fileName[]);

     void startSeq(int *loadType, int*players, int*gameVar);

     void printHand(card head);

     void printTopCard(card deck[]);

     int cardCount(card head);

     void drawCard(card head, card deck[], int *cardsLeft);

     void playCard(card head, int cardPos, int *numDiscard, card deck[]);

     int promptPlayer(card head, card deck[]);

     bool cardCheck(card cardPlayed, card base);
     */
    return 0;
}
