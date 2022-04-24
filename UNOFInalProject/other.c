//
//  other.c
//  UNOFInalProject
//
//  Created by Evan Martin on 4/22/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "other.h"

void shuffle(card deck[], int size)
{
    card * pt;
    for (int i = 0; i < size * 10; i++)
    {
        int index1 = rand() % size;
        card temp = deck[index1];
        int index2 = rand() % size;
        pt = &deck[index1];
        *pt = deck[index2];
        pt = &deck[index2];
        *pt = temp;
    }
}

void starSeq(int *loadType, int*players, int*gameVar)
{

    printf("Let’s Play a Game of UNO\n");
    
    while(!(*players < 11 && 0 < *players))
    {
    printf("We can accomodate up to 1-10 players.\nHow many players are participating? ");
    scanf("%d", players);
        if (*players < 1 || 10 < *players)
        {
            printf("Sorry, please enter a valid number of players.\n");
        }
    }
    
    printf("What game variation would you like to play?\n");
    
    while(*gameVar < 1 || *gameVar > 3)
    {
    printf("Classic: 1\tProgressive: 2\tSeven-O: 3\nPlease enter a number to choose: ");
    scanf("%d", gameVar);
        if (*gameVar < 1 || *gameVar > 3)
        {
            printf("Sorry, that is not a valid game variation\n");
        }
    }
    
    switch (*gameVar) {
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
    
    while(*loadType != 1 && *loadType != 2)
    {
    printf("Press 1 to shuffle the UNO deck or 2 to load a deck from a file: ");
    scanf("%d", loadType);
        if(*loadType != 1 && *loadType != 2)
        {
            printf("Sorry, that in not a valid selection.\n");
        }
    }
}

void readDeck(card deck[])
{
    FILE*inp;
    inp = fopen("deck.txt", "r");
    char color[7];
    int value, cardNum = 0;
    while (fscanf(inp, "%d %s", &value, color) != EOF)
    {
        //fscanf(inp, "%d %s", &value, color);
        //fgets(color, 15, inp);
        //color[strlen(color) - 1] = '\0';
        card *pt;
        pt = &deck[cardNum];
        pt->value = value;
        strcpy(pt->color, color);
        cardNum++;
    }
}


