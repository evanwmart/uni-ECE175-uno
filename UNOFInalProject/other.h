//
//  other.h
//  UNOFInalProject
//
//  Created by Evan Martin on 4/22/22.
//

#ifndef other_h
#define other_h

#include <stdio.h>

typedef struct card_s {
    char color[7];
    int value;
    char action[15];
    struct card_s *t;   //next node
    struct card_s *h;   //prev node
    int position;
} card;

void shuffle(card deck[], int size);

void readDeck(card deck[]);

void starSeq(int *loadType, int*players, int*gameVar);



#endif /* other_h */

/*

⠴⠖⠒⠲⠶⠶⠶⠦
⠯ ♤ ⠽⠿⠿⠿
⠿⠷⠶⠾⠿⠿⠿⠿
⠯REVERSE⠇
⠿⠿⠿⠿⠟⠛⠻⠿
⠿⠿⠿⠯ ♤ ⠽
⠙⠛⠛⠛⠓⠒⠚⠋
 
⠴⠖⠒⠲⠶⠶⠶⠦
⠯ ♠ ⠽⠿⠿⠿
⠿⠷⠶⠾⠿⠿⠿⠿
⠯ SKIP  ⠇
⠿⠿⠿⠿⠟⠛⠻⠿
⠿⠿⠿⠯ ♠ ⠽
⠙⠛⠛⠛⠓⠒⠚⠋
 
⠴⠖⠒⠲⠶⠶⠶⠦
⠯ ♦ ⠽⠿⠿⠿
⠿⠷⠶⠾⠿⠿⠿⠿
⠯  +2   ⠇
⠿⠿⠿⠿⠟⠛⠻⠿
⠿⠿⠿⠯ ♦ ⠽
⠙⠛⠛⠛⠓⠒⠚⠋
 
⠴⠖⠒⠲⠶⠶⠶⠦
⠿ w |   ⠿
⠿   |   ⠿
⠿-------⠿
⠿   |   ⠿
⠿   | w ⠿
⠙⠛⠛⠛⠓⠒⠚⠋

⠴⠖⠒⠲⠶⠶⠶⠦
⠯⠿⠿⠿⠿⠿⠿⠿
⠿⠿⠿⠿⠿⠿⠿⠿
⠯⠿ +4  ⠿⠇
⠿⠿⠿⠿⠿⠿⠿⠿
⠿⠿⠿⠿⠿⠿⠿⠽
⠙⠛⠛⠛⠓⠒⠚⠋
 
 */
