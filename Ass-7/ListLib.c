/* ListLib-Template */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListLib.h"
void AddDrawCommandToList(char a, char DC[], NODE **aa)

{
	NODE *TempPtr, *NewNode;
	// printf("%c", (**aa).Letter);
	if (*aa == NULL)
	{

		NewNode = (struct node *)malloc(sizeof(struct node));
		// printf("It is Null");
		// struct node CurrentNode;
		NewNode->Letter = a;
		NewNode->DrawCommand = DC;
		NewNode->next_ptr = NULL;
		*aa = NewNode;
		// (**aa).next_ptr = &CurrentNode;
	}
	else
	{
		// printf("%s",(*aa)->DrawCommand);
		AddDrawCommandToList(a, DC, &(**aa).next_ptr);
	}

	/* declare pointers of type NODE named TempPtr and NewNode */

	/* malloc a new node and assign the Letter and the DrawCommand (after mallocing memory for it) */

	/* If the LinkedListHead is NULL, then give it the address of the new node */
	/* Else traverse to the end of the linked list and add the new node */
}

NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{
	/* while traversing the linked list AND the Letter in the node is not the Letter passed in */
	{
		/* move TempPtr */
	}

	// if (/* TempPtr is not NULL */)
	{
		/* copy the DrawCommand from the node into the passed in parameter */
		/* return the next pointer stored in TempPtr */
	}

	/* return TempPtr */
}