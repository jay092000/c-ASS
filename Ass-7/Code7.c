#include "ListLib.h"
#include "FileLib.h"
#include "DrawTool.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    NODE *FirstNode = NULL;
    char Map[20][20];
    char printData[3];
    char Background = ' ';
    if (argc < 2)
    {
        printf("Please Enter Valid File Name\n");
        return 0;
    }
    ReadFileIntoLinkedList(OpenFile(argc, argv), &FirstNode);
    printf("What is the background character? ");
    scanf(" %c", &Background);
    for (int j = 0; j < 20; j++)
    {
        for (int k = 0; k < 20; k++)
        {
            Map[j][k] = Background;
        }
    }
    printf("\n\nPlease enter 1-3 letters: ");
    scanf(" %s", printData);

    PrintMap(Map, 20);
    for (int i = 0; i < strlen(printData); i++)
    {
        printData[i] = toupper(printData[i]);
    }
    printf("%s", printData);
}