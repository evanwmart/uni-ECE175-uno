//
//  other.c
//  UNOFInalProject
//
//  Created by Evan Martin & Brian Bedrosian

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "other.h"

void generateDeck(card deck[])
{
    card *pt;
    int i = 0;
    for (int s = 0; s < 4; s++)
    {
        for(int n = 0; n < 15; n++)
        {
            pt = &deck[i];
            pt->value = n;
            switch (s) {
                case 0:
                    strcpy(pt->color, "♠");
                    break;
                    
                case 1:
                    strcpy(pt->color, "♥");
                    break;
                    
                case 2:
                    strcpy(pt->color, "♣");
                    break;
                    
                default:
                    strcpy(pt->color, "♦");
                    break;
            }
            i++;
        }
        for(int n = 1; n < 13; n++)
        {
            pt = &deck[i];
            pt->value = n;
            switch (s) {
                case 0:
                    strcpy(pt->color, "♠");
                    break;
                    
                case 1:
                    strcpy(pt->color, "♥");
                    break;
                    
                case 2:
                    strcpy(pt->color, "♣");
                    break;
                    
                default:
                    strcpy(pt->color, "♦");
                    break;
            }
            i++;
        }
    }
}

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
    
    while(!(*players < 11 && 1 < *players))
    {
    printf("We can accomodate 2-10 players.\nHow many players are participating? ");
    scanf("%d", players);
        if (*players < 2 || 10 < *players)
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
bool readDeck(card deck[], char fileName[])
{
    FILE*inp;
    inp = fopen(fileName, "r");
    int cardNum = 0;
    card *pt;
    
    if(inp == NULL)
    {
        printf("File \"%s\" not found.\n", fileName);
        return false;
    }
    else{
        while (!feof(inp) && cardNum < 108)
        {
            pt = deck;
            char dump;
            fscanf(inp, "%d ", &pt[cardNum].value);
            fscanf(inp, "%s%c", pt[cardNum].color, &dump);
            cardNum++;
        }
    }
    return true;
}

//function to print a players hand
//input: the initial "head" card in the respective player's linked list
void printHand(card* *head, int playerNum)
{
    card *instance = *head;
    if (instance != NULL)
    {
        int count = 0;
        if(instance->t == NULL)
        {
            count = 1;
        }
        while (instance->t != NULL)
        {
            count++;
            instance = instance->t;
        }
        card array[count+1];
        instance = *head;
        for (int i = 0; i <= count; i++)
        {
            array[i] = *instance;
            if(instance->t != NULL)
            {
                instance = instance->t;
            }
        }
        printf("Player");
        switch (playerNum) {
            case 0:
                printf(" one");
                break;
            case 1:
                printf(" two");
                break;
            case 2:
                printf(" three");
                break;
            case 3:
                printf(" four");
                break;
            case 4:
                printf(" five");
                break;
            case 5:
                printf(" six");
                break;
            case 6:
                printf(" seven");
                break;
            case 7:
                printf(" eight");
                break;
            case 8:
                printf(" nine");
                break;
            case 9:
                printf(" ten");
                break;
            default:
                printf("");
                break;
        }
        printf("'s hand:\n");
        //1
        for (int i = 0; i <= count; i++)
        {
            printf("⠴⠖⠒⠲⠶⠶⠶⠶⠄\t");
        }
        printf("\n");
        
        //2
        for (int i = 0; i <= count; i++)
        {
            switch (array[i].value) {
                case 13:
                    printf("⠯ W ⠽⠿⠿⠿⠿\t");
                    break;
                    
                case 14:
                    printf("⠯+4 ⠽⠿⠿⠿⠿\t");
                    break;
                    
                default:
                    printf("⠯ %s ⠽⠿⠿⠿⠿\t", array[i].color);
                    break;
            }
        }
        printf("\n");
        
        //3
        for (int i = 0; i <= count; i++)
        {
            printf("⠿⠷⠖⠚⠛⠛⠻⠿⠇\t");
        }
        printf("\n");

        //4
        for (int i = 0; i <= count; i++)
        {
            switch (array[i].value) {
                case 10:
                    printf("⠿⠇SKIP ⠸⠿\t");
                    break;
                    
                case 11:
                    printf("⠿⠇ REV ⠸⠿\t");
                    break;
                    
                case 12:
                    printf("⠿⠇ +2  ⠸⠿\t");
                    break;
                    
                case 13:
                    printf("⠿⠇WILD ⠸⠿\t");
                    break;
                    
                case 14:
                    printf("⠿⠇ +4  ⠸⠿\t");
                    break;
                    
                default:
                    printf("⠿⠇ %2d  ⠸⠿\t", array[i].value);
                    break;
            }
        }
        printf("\n");
        
        //5
        for (int i = 0; i <= count; i++)
        {
            printf("⠿⠿⠷⠶⠶⠖⠚⠻⠇\t");
        }
        printf("\n");
        
        //6
        for (int i = 0; i <= count; i++)
        {
            switch (array[i].value) {
                case 13:
                    printf("⠿⠿⠿⠿⠯ W ⠽\t");
                    break;
                    
                case 14:
                    printf("⠿⠿⠿⠿⠯ +4⠽\t");
                    break;
                    
                default:
                    printf("⠿⠿⠿⠿⠯ %s ⠽\t", array[i].color);
                    break;
            }
        }
        printf("\n");
        
        //7
        for (int i = 0; i <= count; i++)
        {
            printf("⠙⠛⠛⠛⠛⠓⠒⠚⠁\t");
        }
        printf("\n");
    }
}

//function to print the last played card (top of discard pile)
//input: the deck array
void printTopCard(card deck[])
{
    printf("Discard pile:\n");
    printf("⠴⠖⠒⠲⠶⠶⠶⠶⠄ \n");
    printf("⠯ %s ⠽⠿⠿⠿⠿\n", deck[107].color);
    printf("⠿⠷⠖⠚⠛⠛⠻⠿⠇ \n");
    switch (deck[107].value) {
        case 10:
            printf("⠿⠇SKIP ⠸⠿\n");
            break;
            
        case 11:
            printf("⠿⠇ REV ⠸⠿\n");
            break;
            
        case 12:
            printf("⠿⠇ +2  ⠸⠿\n");
            break;
            
        case 13:
            printf("⠿⠇WILD ⠸⠿\n");
            break;
            
        case 14:
            printf("⠿⠇ +4  ⠸⠿\n");
            break;
            
        default:
            printf("⠿⠇ %2d  ⠸⠿\n", deck[107].value);
            break;
    }
    printf("⠿⠿⠷⠶⠶⠖⠚⠻⠇ \n");
    printf("⠿⠿⠿⠿⠯ %s ⠽\n", deck[107].color);
    printf("⠙⠛⠛⠛⠛⠓⠒⠚⠁ \n");
}

int cardCount(card* *head)
{
    card *instance = *head;
    int count = 0;
    if (instance == NULL)
    {
        return count;
    }
    else
    {
        count = 1;
        while(instance->t != NULL)
        {
            count++;
            instance = instance->t;
        }
    }
    
    return count;
}

//function to draw a card from the deck to a player's hand & then shift the unplayed cards down 1 in the deck array
//input: the player's respective head card, the deck array, the amount of undrawn cards left in the deck
void drawCard(card* *head, card* *tail, card deck[], int *cardsLeft)
{
    //Copy the data
    card *temp;
    temp = (card *)malloc(sizeof(card));
    *temp = deck[0];
    
    if (*head == NULL) //If empty
    {
        *head = temp;
        *tail = temp;
        temp->t = NULL;
        temp->h = NULL;
    }
    else
    {
        (*tail)->t = temp;
        temp->h = *tail;
        *tail = temp;
        temp->t = NULL;
    }
    
    
    //Shift cards in deck
    card *pt;
    for (int i = 0; i < *cardsLeft - 1; i++)
    {
        pt = &deck[i];
        *pt = deck[i + 1];
    }
    
    //Decrease count of playable cards in deck
    *cardsLeft -= 1;
}

void playCard(card* *head, card* *tail, int cardPos, card deck[], int* cardsLeft) // moves the card from the players hand to the discard pile
{
    card *pt = *head;
    
    card *played;
    for (int i = 1; i < cardPos; i++)
    {
        pt = pt->t;
    }
    if (pt == *head)
    {
        played = pt;
        *head = pt->t;
        if (pt->t != NULL)
        {
        (pt->t)->h = pt->h;
        }
    }
    else if (pt == *tail)
    {
        played = pt;
        *tail = (*tail)->h;
        (*tail)->t = NULL;
    }
    else
    {
        played = pt;
        (pt->h)->t = pt->t;
        (pt->t)->h = pt->h;
    }
    free(pt);
    
    card *disc;
    for(int i = *cardsLeft + 1; i < 107; i++)
    {
        disc = &deck[i];
        *disc = deck[i+1];
    }
    
    disc = &deck[107];
    *disc = *played;
    disc->t = NULL;
    disc->h = NULL;
    
}

int promptPlayer(card* *head, card deck[], int playerNum){ //prompts the player which card they want to play in their hand and will return the integer of chosen card by the player
    
    printTopCard(deck);
    printHand(head, playerNum);
    
    int count = cardCount(head);
    printf("Press 1-%d to play any card from your hand, or press zero to draw a card from the deck:\n", count);
    scanf("%d", &count);
    
    return count;
}

bool cardCheck(card cardPlayed, card base){ //checks if the users selected card is a valid card to play
    
    if((cardPlayed.value == base.value) || strcmp(cardPlayed.color, base.color) == 0){
        return true;
    }
    else if (cardPlayed.value == 13){
        return true;
    }
    else if (cardPlayed.value == 14){
        return true;        // !! Challenge/rules on +4
    }
    else {
        return false;
    }
    
}

card getCard(card* *head, int pos){ //returns the card that the player last played
    card *temp = *head;
    for(int i = 1; i < pos; i++)
    {
        temp = temp->t;
    }
    return *temp;
}

void colorChange(card *lastCard){
    int i = -1;
    
    while(i < 1 || i > 4)
    {
        printf("Please select what color you wish to change to.\nSpades:1\tHearts:2\tClubs:3\tDiamonds:4\nWhat color are you choosing?: ");
        scanf("%d", &i);
        
        if (i < 1 || i > 4)
        {
            printf("That is not a valid selection.\n");
        }
    }
    
    switch (i) {
        case 1:
            strcpy(lastCard->color, "♠");
            break;
        
        case 2:
            strcpy(lastCard->color, "♥");
            break;
            
        case 3:
            strcpy(lastCard->color, "♣");
            break;
            
        default:
            strcpy(lastCard->color, "♦");
            break;
    }
}
