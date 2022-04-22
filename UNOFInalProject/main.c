//
//  main.c
//  UNOFInalProject
//
//  Created by Evan Martin on 4/21/22.

#include <stdio.h>
#include <stdlib.h>
#include "other.h"
#include <assert.h>



int main (void)
{
    card deck1[6];
    //card deck2[5];
    
    for (int i = 0; i < 6; i++)
    {
        deck1[i].value = i;
    }
    printf("Before shuffle: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", deck1[i].value);
    }
    
    shuffle(deck1, 6);
    
    printf("\nAfter shuffle: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", deck1[i].value);
    }
    
    return 0;
}

/*
typedef struct node_s {
char name[20];
int tears;
struct node_s *listp; // pointer to same node
} movie;
 
movie * insertNewMovie(movie *list, movie *newp) {
movie *temp;
// Check if list is empty
if (list == NULL)
return newp;
// Check if inserted at start of list
if (newp->tears > list->tears) {
newp->listp = list;
return newp;
}
// Otherwise, find location to insert
temp = list;
while ((temp->listp != NULL) &&
(temp->listp->tears > newp->tears)) {
temp = temp->listp;
}
// insert after temp
newp->listp = temp->listp;
temp->listp = newp;
return list;
}

*/
