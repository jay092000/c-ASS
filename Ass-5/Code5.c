#include "GameLib.h"
#include <string.h>
int main()
{
    char Phrase[MAX_INPUT], DashedPhrase[MAX_INPUT], UpperPhrase[MAX_INPUT];
    int c = 0;
    StartGame(Phrase);

    int i = 0;
    for (i = 0; i < strlen(Phrase); i++)
    {
        UpperPhrase[i] = toupper(Phrase[i]);
    }
    DashIt(Phrase, DashedPhrase);
    printf("Here's the phrase you need to guess\n");
    int s = 1;
    do
    {
        int r, s;

        r = GuessALetter(Phrase, DashedPhrase, UpperPhrase);
        s = strchr(DashedPhrase, '-') != NULL;
        if(s == 0)
        {
            break;
        }
        if (r == 0)
        {
            printf("\nStrike %d", (c + 1));
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
    }
}