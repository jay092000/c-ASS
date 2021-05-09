#include "ListLib.h"
#include "FileLib.h"
#include "DrawTool.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check(int from, int to, int *count, int size, char inputStr)
{
    if (0 > to || 0 > from || to > size || from > size)
    {
        printf("That draw command is out of range");
        return 0;
    }
    else
    {

        if (inputStr == 'H' || inputStr == 'h')
        {
            if ((from + *count) > size)
            {
                printf("That draw command is out of range");
                return 0;
            }
        }
        else if ((inputStr == 'V' || inputStr == 'V'))
        {
            if ((to + *count) > size)
            {
                printf("That draw command is out of range");
                return 0;
            }
        }
        else if (inputStr == 'P' || inputStr == 'p')
        {
            *count = 1;
        }
        return 1;
    }
}
int DrawChars(char arr[][MAXMAPSIZE], char inputStr[])
{
    int from, to, count;
    char tempString[40];
    int i = 2;
    int j = 0;
    while (inputStr[i + j] != ')')
    {
        tempString[j] = inputStr[i + j];
        j++;
    }
    i = 0;
    char *token = strtok(tempString, ",");
    if (token == NULL)
    {
        printf("Invalid Input");
    }
    from = atoi(token);
    token = strtok(NULL, ",");
    if (token == NULL)
    {
        printf("Invalid Input");
    }
    to = atoi(token);
    token = strtok(NULL, ",");
    if (token == NULL)
    {
        printf("Invalid Input");
    }
    count = atoi(token);
    if (inputStr[0] == 'q' || inputStr[0] == 'Q')
    {
        return 0;
    }
    else
    {
        int temp = check(from, to, &count, MAXMAPSIZE, inputStr[0]);
        if (temp == 1)
        {
            printf("%d %d %d \n%s \t %c", from, to, count,inputStr,inputStr[strlen(inputStr) - 1]);

            DrawLine(arr, from, to, inputStr[0], count, inputStr[strlen(inputStr) - 1]);
        }
        else
        {
        }
    }
}
int main(int argc, char *argv[])
{
    // NODE *FirstNode = NULL;
    struct node *head = NULL;

    char Map[MAXMAPSIZE][MAXMAPSIZE];
    char printData[3];
    char Background = ' ';
    if (argc < 2)
    {
        printf("Please Enter Valid File Name\n");
        return 0;
    }
    ReadFileIntoLinkedList(OpenFile(argc, argv), &head);
    printf("What is the background character? ");
    scanf(" %c", &Background);
    for (int j = 0; j < MAXMAPSIZE; j++)
    {
        for (int k = 0; k < MAXMAPSIZE; k++)
        {
            Map[j][k] = Background;
        }
    }
    PrintMap(Map, MAXMAPSIZE);
    printf("\nPlease enter 1-3 letters: ");
    scanf(" %s", printData);

    // PrintMap(Map, MAXMAPSIZE);
    for (int i = 0; i < strlen(printData); i++)
    {
        printData[i] = toupper(printData[i]);
        struct node *TempPointer = head;
        char *DC;
        while (TempPointer != NULL)
        {
            TempPointer = FindLetter(TempPointer, printData[i], DC);
            if (TempPointer != NULL)
            {
                DrawChars(Map, TempPointer->DrawCommand);
                TempPointer = TempPointer->next_ptr;
            }
        }
    }
    // printf("%s\n", printData);
    PrintMap(Map, MAXMAPSIZE);
}