// FileLib.h
#include <stdio.h>
#ifndef _FILELIB_H_
#define _FILELIB_H_
#define MAX_ENTRIES  15
typedef struct data
{
   char singer[100];
   char year[100];
   char album[100];
   char song[100];
}Data;
FILE *OpenFile(int argc, char *argv[],char *fileName);
int ReadFileIntoArry(FILE *,Data [15]);
void RemoveEntryFromFile(char *fileName,int pos,FILE *);

#endif