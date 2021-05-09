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
		char *dc = strtok(NULL, "|");
		AddDrawCommandToList(*firstchar, dc, LinkedListHead);
	}
}
FILE *OpenFile(int argc, char *argv[])
{
	FILE *fptr;
	if (argc < 2)
	{
		printf("Please Enter Valid File Name\n");
		// return 0;
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("File Name Is InValid\n");
		// return 0;
	}
	return fptr;
}