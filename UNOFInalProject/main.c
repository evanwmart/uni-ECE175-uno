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
    int loadType = 0, players = 0, gameVar = 0;
    printf("Let’s Play a Game of UNO\n");
    
    while(!(players < 11 && 0 < players))
    {
    printf("We can accomodate up to 1-10 players.\nHow many players are participating? ");
    scanf("%d", &players);
        if (players < 1 || 10 < players)
        {
            printf("Sorry, please enter a valid number of players.\n");
        }
    }
    
    printf("What game variation would you like to play?\n");
    
    while(gameVar < 1 || gameVar > 3)
    {
    printf("Classic: 1\tProgressive: 2\tSeven-O: 3\nPlease enter a number to choose: ");
    scanf("%d", &gameVar);
        if (gameVar < 1 || gameVar > 3)
        {
            printf("Sorry, that is not a valid game variation\n");
        }
    }
    
    switch (gameVar) {
        case 2:
            printf("Progressive game mode was selected\n");
            break;
            
        case 3:
            printf("Seven-O game mode was selected\n");
            break;
            
        default:
            printf("Classic game mode was selected\n");
            break;
    }
    
    while(loadType != 1 && loadType != 2)
    {
    printf("Press 1 to shuffle the UNO deck or 2 to load a deck from a file: ");
    scanf("%d", &loadType);
        if(loadType != 1 && loadType != 2)
        {
            printf("Sorry, that in not a valid selection.\n");
        }
    }
    
    return 0;
}
