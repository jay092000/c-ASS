// FileLib Template
#include "FileLib.h"
#include <stdio.h>
#include <string.h>

FILE *OpenFile(int argc, char *argv[])
{
	FILE *fptr;
	fptr = fopen(argv[1], "r");

	if (argc < 2 || fptr == NULL)
	{
		while (1)
		{
			printf("File Name Is InValid\n");
			char fileName[50];
			printf("Enter File Name:");
			scanf(" %s", fileName);
			fptr = fopen(fileName, "r");
			if (fptr == NULL)
			{
			}
			else
			{
				return fptr;
			}
		}
	}

	return fptr;
}

int ReadFileIntoArry(FILE *fptr, Data data[MAX_ENTRIES])
{
	int i = 0;
	char buffer[1024];
	int row_count = 0;
	int field_count = 0;

	while (fgets(buffer, 1024, fptr))
	{
		field_count = 0;
		row_count++;
		char *field = strtok(buffer, "|");
		while (field)
		{
			if (field_count == 0)
			{
				strcpy(data[i].singer, field);
			}
			else if (field_count == 1)
			{
				strcpy(data[i].song, field);
			}
			else if (field_count == 2)
			{
				strcpy(data[i].year, field);
			}
			else
			{
				strcpy(data[i].album, field);
			}

			field = strtok(NULL, "|");
			field_count++;
		}
		i++;
	}

	return row_count;
}

void RemoveEntryFromFile(Data *data, char *Phrase, FILE *fptr)
{
	int i = 0;
	char buffer[1024];
	int row_count = 0;
	int field_count = 0;
	int selected = 0;

	while (fgets(buffer, 1024, fptr))
	{
		field_count = 0;
		row_count++;
		char *field = strtok(buffer, "|");
		while (field)
		{

			if (field_count == 1)
			{
				if (strcmp(field, Phrase) == 0)
				{
					selected = row_count;
				}
			}

			field = strtok(NULL, "|");
			field_count++;
		}
		i++;
	}

	printf("%d", selected);
}