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

//function to shuffle an array
//input: the array and the index number of which empty slots start
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

//function for the startup sequence
//input: 3 int pointers
void startSeq(int *loadType, int*players, int*gameVar)
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

//function to load in a deck from file
//input: deck array and file name
void readDeck(card deck[], char fileName[])
{
    FILE*inp;
    inp = fopen(fileName, "r");
    char color;
    int value, cardNum = 0;
    while (fscanf(inp, "%d %c\n", &value, &color) != EOF)
    {
        card *pt;
        pt = &deck[cardNum];
        pt->value = value;
        pt->color = color;
        cardNum++;
    }
}

//function to print a players hand
//input: the initial "head" card in the respective player's linked list
void printHand(card head)
{
    card instance = head;
    int count = 0;
    while (instance.t != NULL)
    {
        count++;
        instance = *instance.t;
    }
    card array[count+1];
    instance = *head.t;
    for (int i = 0; i < count; i++)
    {
        array[i] = instance;
        if(instance.t != NULL)
        {
            instance = *instance.t;
        }
    }
    
    printf("Player ");
    
    switch (head.value) {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        case 10:
            printf("ten");
            break;
        default:
            printf("");
            break;
    }
    
    printf("'s hand:\n");
    
    //1
    for (int i = 0; i < count; i++)
    {
        printf("⠴⠖⠒⠲⠶⠶⠶⠶⠄\t");
    }
    printf("\n");
    
    //2
    for (int i = 0; i < count; i++)
    {
        printf("⠯ %c ⠽⠿⠿⠿⠿\t", array[i].color);
    }
    printf("\n");
    
    //3
    for (int i = 0; i < count; i++)
    {
        printf("⠿⠷⠖⠚⠛⠛⠻⠿⠇\t");
    }
    printf("\n");

    //4
    for (int i = 0; i < count; i++)
    {
        printf("⠿⠇-----⠸⠿\t");
    }
    printf("\n");
    
    //5
    for (int i = 0; i < count; i++)
    {
        printf("⠿⠿⠷⠶⠶⠖⠚⠻⠇\t");
    }
    printf("\n");
    
    //6
    for (int i = 0; i < count; i++)
    {
        printf("⠿⠿⠿⠿⠯ %c ⠽\t", array[i].color);
    }
    printf("\n");
    
    //7
    for (int i = 0; i < count; i++)
    {
        printf("⠙⠛⠛⠛⠛⠓⠒⠚⠁\t");
    }
    printf("\n");
}

//function to print the last played card (top of discard pile)
//input: the deck array
void printTopCard(card deck[])
{
    printf("Discard pile:\n");
    printf("⠴⠖⠒⠲⠶⠶⠶⠶⠄ \n");
    printf("⠯ %c ⠽⠿⠿⠿⠿\n", deck[107].color);
    printf("⠿⠷⠖⠚⠛⠛⠻⠿⠇ \n");
    printf("⠿⠇-%2d--⠸⠿\n", deck[107].value);
    printf("⠿⠿⠷⠶⠶⠖⠚⠻⠇ \n");
    printf("⠿⠿⠿⠿⠯ %c ⠽\n", deck[107].color);
    printf("⠙⠛⠛⠛⠛⠓⠒⠚⠁ \n");
}

int cardCount(card head)
{
    card instance = head;
    int count = 0;
    while(instance.t != NULL)
    {
        if (instance.t != NULL)
        {
            instance = *instance.t;
            count++;
        }
    }
    return count;
}

//function to draw a card from the deck to a player's hand & then shift the unplayed cards down 1 in the deck array
//input: the player's respective head card, the deck array, the amount of undrawn cards left in the deck
void drawCard(card head, card deck[], int *cardsLeft)
{
    
    card instance = head;
    while(instance.t != NULL)
    {
        instance = *instance.t;
    }
    
    card drawnCard = deck[0];
    
    instance.t = &drawnCard;
    drawnCard.h = &instance;
    drawnCard.t = NULL;
    
    card *pt;
    for (int i = 0; i < *cardsLeft; i++)
    {
        pt = &deck[i];
        *pt = deck[i+1];
    }
}



card playCard(card head, int cardPos, int *numDisgard){
    
    
    
    
    
  
    
    
    
    return ;
}


int promptPlayer(card head){
    
    
    
    
    
    
    return ;
}

