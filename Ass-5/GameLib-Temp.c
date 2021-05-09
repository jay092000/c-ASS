#include "PhraseBank.txt"
#include "GameLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void StartGame(char ChosenPhrase[MAX_INPUT])
{
	char DashPhrase[MAX_INPUT] = {0};
	int i = 0;
	int Choice = 0;

	/* put an include here to include PhraseBank.txt in your program */
	printf("\n\nWelcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n", STRIKES);

	printf("Please pick a phrase from the following menu\n\n");

	while (PhraseBank[i] != "")
	{
		printf("--IN while---");
		CheckPhrase(PhraseBank[i]);
		/* Call CheckPhrase with PhraseBank[i] */
		/* Call DashIt with PhraseBank[i] and DashPhrase */
		DashIt(PhraseBank[i],DashPhrase);
		printf("%d.\t%s\n", i + 1, DashPhrase);
		i++;
	}

	printf("\nEnter choice : ");
	scanf("%d", &Choice);
	getchar();

	/* create a while condition that is true when Choice is less than 1 or greater than i */
	{
		printf("You entered an invalid choice.\nPlease reenter ");
		scanf("%d", &Choice);
	}

	/* copy the phrase from PhraseBank based on Choice into ChosenPhrase */
}

void CheckPhrase(char *Phrase)
{
	/* Declare a char pointer named FindDash and initialize it to NULL */
	char *FindDash = NULL;
	printf("--%s---", Phrase);

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

int GuessALetter(char Phrase[], char DashedPhrase[], char UpperPhrase[])
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

	toupper(Guess);

	FindGuess = strchr(UpperPhraseCopy, Guess);

	while (FindGuess != NULL)
	{
		FoundALetter = 1;
		DashedPhrase[FindGuess - UpperPhraseCopy] = Phrase[FindGuess - UpperPhraseCopy];
		/* Dereference FindGuess and set it to a dash */
		UpperPhraseCopy[FindGuess - DashedPhrase] = '-';

		FindGuess = strchr(UpperPhraseCopy, Guess);
	}

	return FoundALetter;
}

void DashIt(char *Phrase, char DashPhrase[])
{
	char *ReplaceIt;
	printf("--IN Dash---");

	char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;

	/* Put the uppercase version of Phrase into DashPhrase */
	for (i = 0; i < strlen(Phrase); i++)
	{
		toupper(Phrase[i]);
		DashPhrase[i] = Phrase[i];
	}
	/* Call strpbrk() with DashPhrase and Alphabet and save the result in ReplaceIt */
	ReplaceIt = strpbrk(DashPhrase, Alphabet);
	while (ReplaceIt != NULL)
	{
		/* Dereference ReplaceIt and set it to a dash */
		DashPhrase[ReplaceIt - Phrase] = '-';
		/* Call strpbrk() again */
		ReplaceIt = strpbrk(DashPhrase, Alphabet);
	}
}
