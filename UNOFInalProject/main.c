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
        
     player selects card
        move card to played cards
        remove card from players hand
     
     check players hand amount
        if zero set win to true
     
     read card and determine next player and action
    }
     */
    card deck[10];
    deck[0].value = 0;
    strcpy(deck[0].color, "D");
    
    for(int i = 1; i < 10; i++)
    {
        deck[i].value = i;
    }
    for(int i = 1; i < 10; i++)
    {
        printf("%d - ", deck[i].value);
    }
    printf("\n");
    
    card head, one, two, three;
    head.h = NULL;
    head.t = &one;
    head.value = 0;
    strcpy(head.color, "X");
    one.h = &head;
    one.t = &two;
    one.value = 1;
    strcpy(one.color, "A");
    two.h = &one;
    two.t = &three;
    two.value = 2;
    strcpy(two.color, "B");
    three.h = &two;
    three.t = NULL;
    three.value = 3;
    strcpy(three.color, "C");
    
    printf("Before Draw:\n");
    printHand(head);
    
    int cL = 10;
    int *cpt = &cL;
    
    drawCard(head, deck, cpt);
    
    printf("After Draw:\n");
    printHand(head);
    for(int i = 1; i < 10; i++)
    {
        printf("%d - ", deck[i].value);
    }
    printf("\n");
    
    /*

     int cardCount(card head);

     void drawCard(card head, card deck[], int *cardsLeft);

     void playCard(card head, int cardPos, int *numDiscard, card deck[]);

     int promptPlayer(card head, card deck[]);

     bool cardCheck(card cardPlayed, card base);
     */
    
    return 0;
}
