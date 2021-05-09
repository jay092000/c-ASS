#include "FileLib.h"
#include "GameLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fptr;
    char Phrase[MAX_INPUT], DashedPhrase[MAX_INPUT], UpperPhrase[MAX_INPUT], fileName[MAX_INPUT];
    int size, choice;
    Data array[MAX_ENTRIES];
    fptr = OpenFile(argc, argv, fileName);
    printf("%s", fileName);
    size = ReadFileIntoArry(fptr, array);
    Data finalData[size];
    for (int i = 0; i < size; i++)
    {
        finalData[i] = array[i];
    }

    choice = StartGame(finalData, Phrase, size);
    printf("%s", Phrase);
    printf("Here's the phrase you need to guess\n");
    int s = 1;
    int c = 0;
    for (int i = 0; i < strlen(Phrase); i++)
    {
        UpperPhrase[i] = toupper(Phrase[i]);
    }
    DashIt(Phrase, DashedPhrase);
    do
    {
        int r, s;

        r = GuessALetter(Phrase, DashedPhrase, UpperPhrase);
        s = strchr(DashedPhrase, '-') != NULL;
        if (s == 0)
        {
            break;
        }
        if (r == 0)
        {
            c++;
        }
    } while (c < 3);
    if (c == 3)
    {
        printf("3 STRIKES - YOU'RE OUT!!\n");
        printf("Game over!\n");
    }
    else
    {
        printf("You figured it out!!\n\n");
        printf("The phrase was\n\n");
        printf("%s", Phrase);
        printf("\n\nYOU WIN!!!!\n");
        RemoveEntryFromFile(fileName, choice, fptr);
        fclose(fptr);
    }
}