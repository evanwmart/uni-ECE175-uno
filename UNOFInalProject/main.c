//
//  main.c
//  UNOFInalProject
//
//  Created by Evan Martin & Brian Bedrosian on 4/21/22.

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
    int* numCards = &cardsLeft;
    card deck[108];
    readDeck(deck, "deck.txt");
    
    startSeq(loadPt, playersPt, gameVarPt);
    
    if (loadType == 1)
    {
        shuffle(deck, 108);
    }
    else
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
     
    card * playersH[numPlayers];
    card * playersT[numPlayers];
    
    for (int i = 0; i < numPlayers; i++)
    {
        playersH[i] = NULL;
        playersT[i] = NULL;
    }
    for(int i = 0; i < 7; i++)
    {
        for (int j = 0; j < numPlayers; j++)
        {
            drawCard(&playersH[j], &playersT[j], deck, numCards);
        }
    }
    
    drawCard(&playersH[0], &playersT[0], deck, numCards);       //draw another card and put it into discard pile
    playCard(&playersH[0], &playersT[0], 8, deck, numCards);
    
    bool win = false;       //track wether game should continue
    int pturn = 0;          //track whose turn it is
    int pdirection = 1;     //the increment for direction of play (turn
    
    while(!win)             //check for if game is over
    {
        bool canPlay = false;
        
        //determine which player's turn
        pturn = pturn % numPlayers;
        
        printf("\n\n\n\n");
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
        
        while (!canPlay)
        {
            int pos = -1;
            while( pos <= 0 || pos > cardCount(&playersH[pturn]) )
            {
                
                //Ask player to select card and store selected card's position in pos
                pos = promptPlayer(&playersH[pturn], deck, pturn);
                
                //check that desired position is within the player's hand range
                if (pos <= 0 || pos > cardCount(&playersH[pturn]))
                {
                    printf("Please enter a valid card number.\n");
                }
            }
            
            //store card played
            card cardPlayed = getCard(&playersH[pturn], pos);
            
            //check if the card chosen to play is valid to play
            if( cardCheck(cardPlayed, deck[107]) )
            {
                //if valid, play card
                playCard(&playersH[pturn], &playersT[pturn], pos, deck, numCards);
                canPlay = true;
            }
            //if invalid, do not play card
            else
            {
                printf("The %d%s cannot be placed on top of %d%s\n", cardPlayed.value, cardPlayed.color, deck[107].value, deck[107].color);
                canPlay = false;
            }
            
            if (canPlay)
            {
                switch (deck[107].value) {
                    case 10:    //skip card
                        pturn += (pdirection * 2);
                        break;
                        
                    case 11:    //reverse card
                        pdirection = pdirection * -1;
                        pturn += pdirection;
                        break;
                    
                    case 12:    //pickup 2 card
                        pturn += pdirection;
                        //pick up two for next player
                        break;
                        
                    case 13:    //wild card
                        pturn += pdirection;
                        //prompt to change color "colorChange()"
                        break;
                        
                    case 14:    //pickup 4 card
                        pturn += pdirection;
                        //pick up 4 for next player
                        //prompt to change color "colorChange()"
                        break;
                        
                    default:
                        pturn += pdirection;
                        break;
                }
            }
            
            //count player's hand if zero then win sequence, if one then say uno
        }
        
        
        
        
        
    }
    
    return 0;
}
