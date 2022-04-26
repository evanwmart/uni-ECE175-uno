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
        
    }
     
    
    return 0;
}
