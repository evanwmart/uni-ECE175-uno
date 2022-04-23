//
//  main.c
//  UNOFInalProject
//
//  Created by Evan Martin on 4/21/22.

#include <stdio.h>
#include <stdlib.h>
#include "other.h"
#include <assert.h>
#define SIZE 100

int main (void)
{
    /*
    int loadType = 0, players = 0, gameVar = 0;
    int* loadPt = &loadType;
    int* playersPt = &players;
    int* gameVarPt = &gameVar;
    starSeq(loadPt, playersPt, gameVarPt);
     */
    card deck[108];
    
    readDeck(deck);
    
    return 0;
}
