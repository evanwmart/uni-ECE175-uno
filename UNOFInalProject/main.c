//
//  main.c
//  UNOFInalProject
//
//  Created by Evan Martin on 4/21/22.

#include <stdio.h>
#include <stdlib.h>


//linked list
typedef struct card_s {
            char color[7];
            int value;
            char action[15];
            struct card_s *t;   //next node
            struct card_s *h;   //prev node
            int index;
} card;

void addCard(void);

int main (void)
{
    //dynamically allocate deck
    card *deck;
    deck = (card*)malloc(10*sizeof(card));
    
    for (int i = 0; i < 10; i++)
    {
        deck[i].value = i;
        printf("%d %d %d\n", deck[i].value, (int)sizeof(deck[i]), (int)sizeof(card) );
        deck++;
    }

    
    printf("%d\n", (int)(sizeof(*deck)) );
    
    //add
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
