#include "FileLib.h"
#include "GameLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int StartGame(Data data[MAX_ENTRIES], char ChosenPhrase[], int size)
{
	char DashPhrase[1000];
	int i = 0;
	int Choice = 0;
	Data finalData[size];
	for (int i = 0; i < size; i++)
	{
		finalData[i] = data[i];
	}

	/* put an include here to include PhraseBank.txt in your program */
	printf("\n\nWelcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n", STRIKES);

	printf("Please pick a phrase from the following menu\n\n");

	while (i < size)
	{
		FormSentace(finalData[i].album, finalData[i].singer, finalData[i].year, DashPhrase);
		printf("%d.\t%s\n", i + 1, DashPhrase);
		i++;
	}

	printf("\nEnter choice : ");
	scanf("%d", &Choice);
	getchar();
	/* create a while condition that is true when Choice is less than 1 or greater than i */
	while (Choice < 0 || Choice > size)
	{
		printf("You entered an invalid choice.\nPlease reenter ");
		scanf("%d", &Choice);
	}
	strcpy(ChosenPhrase, data[Choice - 1].song);
	return Choice;
}
// void FormSentace(Data val, char line[1000])
// {
// 	strcat(line, val.singer);
// 	strcat(line, " song that was released in ");
// 	strcat(line, val.year);
// 	strcat(line, " on album ");
// 	strcat(line, val.album);
// }
void CheckPhrase(char *Phrase)
{
	/* Declare a char pointer named FindDash and initialize it to NULL */
	char *FindDash = NULL;

	FindDash = strchr(Phrase, '-');
	/* call strchr() with Phrase and a dash and store the result in FindDash.  If that */
	/* value is not NULL, then you found a dash */
	if (FindDash != NULL)
	{
		printf("\n\"%s\" contains a dash in position %d!!\n", Phrase, abs(Phrase - FindDash) + 1);
		printf("\nYou broke the rules.  We can't play.  BYE!!\n\n");
		exit(0);
		/* exit the program */
	}
}

int GuessALetter(char Phrase[MAX_INPUT], char DashedPhrase[MAX_INPUT], char UpperPhrase[MAX_INPUT])
{
	char Guess;
	char *FindGuess = NULL;
	char UpperPhraseCopy[MAX_INPUT];
	int FoundALetter = 0;

	strcpy(UpperPhraseCopy, UpperPhrase);
	printf("\n\n%s", DashedPhrase);
	printf("\n\nGuess a letter : ");
	scanf(" %c", &Guess);
	getchar();

	Guess = toupper(Guess);

	FindGuess = strchr(UpperPhraseCopy, Guess);

	while (FindGuess != NULL)
	{
		FoundALetter = 1;
		DashedPhrase[FindGuess - UpperPhraseCopy] = Phrase[FindGuess - UpperPhraseCopy];
		/* Dereference FindGuess and set it to a dash */
		*FindGuess = '-';

		FindGuess = strchr(UpperPhraseCopy, Guess);
	}

	return FoundALetter;
}

char *FormSentace(char album[200], char singer[200], char year[200], char DashData[1000])
{
	char temp[1000] = "";
	strcat(temp, singer);
	strcat(temp, " song that was released in ");
	strcat(temp, year);
	strcat(temp, " on album ");
	strcat(temp, album);

	strcpy(DashData, temp);
}
void DashIt(char *Phrase, char DashPhrase[MAX_INPUT])
{
	char *ReplaceIt;

	char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;
	for (i = 0; i < strlen(Phrase); i++)
	{
		DashPhrase[i] = toupper(Phrase[i]);
	}
	ReplaceIt = strpbrk(DashPhrase, Alphabet);
	while (ReplaceIt != NULL)
	{
		*ReplaceIt = '-';
		ReplaceIt = strpbrk(DashPhrase, Alphabet);
	}
}
