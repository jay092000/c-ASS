/* Donna French 1000074079 */

#ifndef _GAMELIB_H_
#define _GAMELIB_H_

#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT 81
#define STRIKES 3

int StartGame(Data data[], char ChosenPhrase[], int size);
char *FormSentace(char album[200], char singer[200], char year[200], char DashData[1000]);
void DashIt(char *Phrase, char DashPhrase[]);
int GuessALetter(char Phrase[], char DashedPhrase[], char UpperPhrase[]);
void CheckPhrase(char *Phrase);

#endif
