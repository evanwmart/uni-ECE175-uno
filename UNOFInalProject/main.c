//
//  main.c
//  UNOFInalProject
//
//  Created by Evan Martin on 4/21/22.

#include <stdio.h>
#include <stdlib.h>
#include "other.h"
#include <assert.h>
#include <stdbool.h>
#define SIZE 100

int main (void)
{
    
    int loadType = 0, numPlayers = 0, gameVar = 0;
    int* loadPt = &loadType;
    int* playersPt = &numPlayers;
    int* gameVarPt = &gameVar;
    
    starSeq(loadPt, playersPt, gameVarPt);
     
    card *players;
    players = (card*)calloc(numPlayers, sizeof(card));
    for (int i = 0; i < numPlayers; i++)
    {
        players[i].h = NULL;
        players[i].t = NULL;
        players[i].position = i + 1;
    }
    
    for(int i = 0; i < 7; i++)
    {
        for (int j = 0; j < numPlayers; j++)
        {
            drawCard(players[i]);
        }
    }
    
    bool win = false;
    int turn = 0;
    int direction = 1;
    while(!win)
    {
        promptPlayer(discard, players[turn]);
        
     player selects card
        move card to played cards
        remove card from players hand
     
     check players hand amount
        if zero set win to true
     
     read card and determine next player and action
        
    }
     */
    
    return 0;
}
