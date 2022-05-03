//
//  main.c
//  UNOFInalProject
//
//  Created by Evan Martin & Brian Bedrosian
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "other.h"
#include <assert.h>
#include <stdbool.h>
#define SIZE 100

int main (void)
{
    int numAI = -1;
    int loadType = 0, numPlayers = 0, gameVar = 0, cardsPlayed = 0, cardsLeft = 108;
    int* loadPt = &loadType;
    int* playersPt = &numPlayers;
    int* gameVarPt = &gameVar;
    int* numCards = &cardsLeft;
    int* numPlayed = &cardsPlayed;
    int *AIplayer = &numAI;
    card deck[108];
    readDeck(deck, "deck.txt");
    
    startSeq(loadPt, playersPt, gameVarPt, AIplayer);     //starting sequence to intialize game settings
    
    if (loadType == 1)          //user has chosen to generate and shuffle a deck
    {
        generateDeck(deck);
        shuffle(deck, cardsLeft);
    }
    else                        //user has chosen to load a deck from a file
    {
        char fileName[30];
        printf("Please enter the file name to load a deck: ");
        scanf("%s", fileName);
        if (!readDeck(deck, fileName))
        {
            printf("Please restart program.\n");
            return -1;
        }
        else
        {
            readDeck(deck, fileName);
        }
    }
    
    
    //create head and tail pointerss for however many players were selected
    card * playersH[numPlayers];
    card * playersT[numPlayers];
    
    //set head and tail pointers to NULL
    for (int i = 0; i < numPlayers; i++)
    {
        playersH[i] = NULL;
        playersT[i] = NULL;
    }
    
    //Start of every player with 7 cards in their hand
    for(int i = 0; i < 7; i++)
    {
        for (int j = 0; j < numPlayers; j++)
        {
            drawCard(&playersH[j], &playersT[j], deck, numCards);
        }
    }
    
    //draw and play one more card so the discard pile has a card on it
    drawCard(&playersH[0], &playersT[0], deck, numCards);
    playCard(&playersH[0], &playersT[0], 8, deck, numCards, numPlayed);
    
    //print gap and statement
    printf("\n\n\n\n\n\n\n\n");
    printf("The cards have been dealt.\n");
    
    
    bool win = false;       //track whether game should continue
    int pturn = 0;          //track whose turn it is
    int pdirection = 1;     //the increment for direction of play (turn
    
    //game loop
    while(!win)
    {
        //Determine which player's turn it is
        pturn = pturn % numPlayers;
        
        if((pturn == numAI) && *AIplayer != -1){
            int checkPlayed = *numPlayed;
            AITurn(&playersH[pturn], &playersT[pturn], deck, &pdirection, deck[107], numCards, numPlayed);
            int nextP;
            //determine turn dynamics and direction
            if (checkPlayed == *numPlayed){
                switch (deck[107].value) {
                    case 10:    //skip card
                        nextP = (pturn + pdirection) % numPlayers;
                        printf("Player %d was skipped!\n", nextP+1);
                        pturn += (pdirection * 2);  //change turn
                        break;
                        
                    case 11:    //reverse card
                        pdirection = pdirection * -1;
                        pturn += pdirection;        //change turn
                        break;
                    
                    case 12:    //pickup 2 card
                        //Pick up two for next player
                        nextP = (pturn + pdirection) % numPlayers;
                        drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                        drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                        pturn += pdirection;        //change turn
                        break;
                        
                    case 13:    //wild card
                        //Prompt to change color
                        colorChange(&deck[107]);
                        pturn += pdirection;        //change turn
                        break;
                        
                    case 14:    //pickup 4 card
                        //pick up 4 for next player
                        nextP = (pturn + pdirection) % numPlayers;
                        drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                        drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                        drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                        drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                        //prompt to change color "colorChange()"
                        colorChange(&deck[107]);
                        pturn += pdirection;    //change turn
                        break;
                        
                    default:
                        pturn += pdirection;    //change turn
                        break;
                        
                }
            }
        }
        else
        {
            if (cardsLeft == 0){
                resetDeck(deck, numCards, numPlayed);
                shuffle(deck, *numCards);
            }
            
            //Print which player's turn it is
            printf("Player");
            switch (pturn) {
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
            printf("'s turn!\n");
            
            
            
            bool canPlay = false;
            //Player prompt loop
            while (!canPlay)
            {
                int pos = -1;
                while( pos < 0 || pos > cardCount(&playersH[pturn]) )
                {
                    //Ask player to select card and store selected card's position in pos
                    pos = promptPlayer(&playersH[pturn], deck, pturn);
                    
                    //check that desired position is within the player's hand range
                    if (pos < 0 || pos > cardCount(&playersH[pturn]))
                    {
                        printf("Please enter a valid card number.\n");
                    }
                }
                
                //Check if player has chosen to draw a card
                if (pos == 0)
                {
                    drawCard(&playersH[pturn], &playersT[pturn], deck, numCards);
                }
                else
                {
                    //store card played
                    card cardPlayed = getCard(&playersH[pturn], pos);
                    
                    //check if the card chosen to play is valid to play
                    if( cardCheck(cardPlayed, deck[107]) )
                    {
                        //if valid, play card
                        playCard(&playersH[pturn], &playersT[pturn], pos, deck, numCards, numPlayed);
                        canPlay = true;
                    }
                    //if invalid, do not play card
                    else
                    {
                        printf("The %d%s cannot be placed on top of %d%s\n", cardPlayed.value, cardPlayed.color, deck[107].value, deck[107].color);
                        canPlay = false;
                    }
                    
                }
            
                //count player's hand, if zero then win sequence, if one then say "UNO"
                if (cardCount(&playersH[pturn]) == 0)
                {
                    win = winSeq(pturn);
                    canPlay = false;
                }
                else if (cardCount(&playersH[pturn]) == 1)
                {
                    printf("UNO!");
                }
                
                //If card was playable, check how the card affects the turn rotation
                if (canPlay)
                {
                    int nextP;
                    switch (deck[107].value) {
                        case 10:    //skip card
                            nextP = (pturn + pdirection) % numPlayers;
                            printf("Player %d was skipped!\n", nextP+1);
                            pturn += (pdirection * 2);  //change turn
                            break;
                            
                        case 11:    //reverse card
                            pdirection = pdirection * -1;
                            pturn += pdirection;        //change turn
                            break;
                        
                        case 12:    //pickup 2 card
                            //Pick up two for next player
                            nextP = (pturn + pdirection) % numPlayers;
                            drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                            drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                            pturn += pdirection;        //change turn
                            break;
                            
                        case 13:    //wild card
                            //Prompt to change color
                            colorChange(&deck[107]);
                            pturn += pdirection;        //change turn
                            break;
                            
                        case 14:    //pickup 4 card
                            //pick up 4 for next player
                            nextP = (pturn + pdirection) % numPlayers;
                            drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                            drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                            drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                            drawCard(&playersH[nextP], &playersT[nextP], deck, numCards);
                            //prompt to change color "colorChange()"
                            colorChange(&deck[107]);
                            pturn += pdirection;    //change turn
                            break;
                            
                        default:
                            pturn += pdirection;    //change turn
                            break;
                    }
                }
                else    //Card was not playable (Zero or invalid card was selected)
                {
                    if (pos == 0)   //If it was Zero
                    {
                        pturn += pdirection;
                    }
                }
                //exit canPlay loop if draw card was selected
                if(pos == 0)
                {
                    canPlay = true;
                }
        }//end of AI else
        }//end of !canPlay loop
    }//end of game loop
    return 0;
}//end of main
