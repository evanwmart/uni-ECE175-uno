//
//  notes.c
//  UNOFInalProject
//
//  Created by Evan Martin on 4/28/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person_s {
   char name[10];
   int age;
   struct person_s *prev, *next;  //pointing to the previous and next person
} person;

int main(void)
{
    person arr[10];
    int i;
    //initialize array
    
    person *headList1, *tailList1;
    person *headList2, *tailList2;
    headList1 = NULL;
    headList2 = NULL;
    
    
    
    return 0;
}

void addMember(person* *hl, person* *hr, person arr[], int i)
{
    //create node
    person *temp;
    temp = (person*)malloc(sizeof(person));
    
    strcpy(temp->name, arr[i].name);
    
    //Check if list is empty
    if (*hl == NULL)
    {
        
    }
    
}

//1: *hl = temp;
//2: *hr = temp;
//3: temp->previous = NULL;
//4: temp->next = NULL;


//5:
//6:
//7:
//8:

