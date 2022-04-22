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
    card deck1[SIZE];
    //card deck2[5];
    
    for (int i = 0; i < SIZE; i++)
    {
        deck1[i].value = i;
    }
    printf("Before shuffle: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", deck1[i].value);
    }
    
    shuffle(deck1, SIZE);
    
    printf("\nAfter shuffle: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", deck1[i].value);
    }
    
    return 0;
}
