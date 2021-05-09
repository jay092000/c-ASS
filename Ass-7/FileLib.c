// FileLib Template

#include <stdio.h>
#include <string.h>
#include "ListLib.h"

/* Use function OpenFile() from previous assignment */

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
	char line[500];
	while (fgets(line, sizeof(line), DCFile))
	{
		char *firstchar = strtok(line, "|");
		char *dc = strdup(strtok(NULL, "|"));
		AddDrawCommandToList(*firstchar, dc, LinkedListHead);
	}
}
FILE *OpenFile(int argc, char *argv[])
{
	FILE *fptr = NULL;
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("File Name Is InValid\n");
		// return 0;
	}
	return fptr;
}

// /* return type */ ReadFileIntoLinkedList(/* parameters */)
// {
// 	/* declare various variables needed */

// 	/* while fgets() reads the file */
// 	{
// 		/* if line from file ends with \n, then replace \n with \0 */

// 		/* tokenize to get the Letter and the DrawCommand */

// 		/* Call AddDrawCommandToList with correct parameters */
// 	}
// }
