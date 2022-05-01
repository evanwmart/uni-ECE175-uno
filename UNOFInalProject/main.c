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
    readDeck(deck, "deck.txt");
    
    startSeq(loadPt, playersPt, gameVarPt);
     
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
    
    drawCard(&playersH[0], &playersT[0], deck, numCards);
    playCard(&playersH[0], &playersT[0], 8, deck);  // !MAKE SURE THE DISCARD PILE HAS THE PLAYED CARD!!
    
    bool win = false;       //track wether game should continue
    int pturn = 0;          //track whose turn it is
    int pdirection = 1;     //the increment for direction of play (turn
    while(!win)             //check for if game is over
    {
        bool canPlay = false;
        while (!canPlay)
        {
            int c = -1;
            while( c <= 0 || c > cardCount(&playersH[pturn]) )
            {
                
                //Ask player to select card and stor selected card integer
                c = promptPlayer(&playersH[pturn], deck, pturn);
                //check that prompt player is within the players hand
                if (c <= 0 || c > cardCount(&playersH[pturn]))
                {
                    printf("Please eneter a valid card number.\n");
                }
            }
        
            card cardPlayed = getCard(&playersH[pturn], c);
        
            if( cardCheck(cardPlayed, deck[107]) )
            {
                playCard(&playersH[pturn], &playersT[pturn], c, deck);
                canPlay = true;
            }
            else
            {
                printf("The %d%s cannot be placed on top of %d%s\n", cardPlayed.value, cardPlayed.color, deck[107].value, deck[107].color);
            }
            
            
        }
        
        
    }
    
    return 0;
}
