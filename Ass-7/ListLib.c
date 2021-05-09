/* ListLib-Template */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListLib.h"
void AddDrawCommandToList(char a, char DC[], NODE **aa)

{
	NODE *TempPtr, *NewNode = NULL;
	// printf("%c", (**aa).Letter);
	TempPtr = *aa;
	while (TempPtr != NULL)
	{
		TempPtr = TempPtr->next_ptr;
	}
	NewNode = (struct node *)malloc(sizeof(struct node));
	NewNode->Letter = toupper(a);
	NewNode->DrawCommand = DC;
	NewNode->next_ptr = NULL;
	*aa = NewNode;
}

NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{
	NODE *TempPtr = LinkedListHead;
	while (TempPtr != NULL)
	{
		if (TempPtr->Letter == Letter)
		{
			break;
		}
		TempPtr = TempPtr->next_ptr;
	}
	if (TempPtr != NULL)
	{
		DC = TempPtr->DrawCommand;
	}

	return TempPtr;
}
