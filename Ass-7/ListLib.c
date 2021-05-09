/* ListLib-Template */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ListLib.h"

void AddDrawCommandToList(char a, char DC[], NODE **aa)
{
	struct node *NewNode = (struct node *)malloc(sizeof(struct node));
	NewNode->Letter = toupper(a);
	// NewNode->DrawCommand = DC;
	NewNode->DrawCommand = DC;
	NewNode->next_ptr = *aa;
	*aa = NewNode;
}

NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{

	struct node *ptr = LinkedListHead;
	if (LinkedListHead == NULL)
	{
		return NULL;
	}
	while (ptr->Letter != Letter)
	{
		if (ptr->next_ptr == NULL)
		{
			return NULL;
		}
		else
		{
			ptr = ptr->next_ptr;
		}
	}
	return ptr;
}

NODE *FindLetter1(NODE *LinkedListHead)
{

	struct node *ptr = LinkedListHead;
	//start from the beginning
	if (LinkedListHead == NULL)
	{
		return NULL;
	}
	while (ptr != NULL)
	{
		printf("%c|%s ", ptr->Letter, ptr->DrawCommand);
		ptr = ptr->next_ptr;
	}
	return ptr;
}
