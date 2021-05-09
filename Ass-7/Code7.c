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
POINTS *DrawPoints(char inputStr[])
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
    int temp = check(from, to, &count, MAXMAPSIZE, inputStr[0]);
    if (temp == 1)
    {
        POINTS *pointsA = (POINTS *)malloc(sizeof(POINTS));
        pointsA->count = count;
        pointsA->from = from;
        pointsA->to = to;
        // DrawLine(arr, from, to, inputStr[0], count, a);
        return pointsA;
    }
    else
    {
        return NULL;
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
                char *Dc = TempPointer->DrawCommand;
                POINTS p = *DrawPoints(TempPointer->DrawCommand);
                // if()
                // printf("%s",Dc);
                // DrawLine(Map, p.from, (p.to + (i * 6)), Dc[0], p.count, Dc[strlen(Dc) - 2]);
                TempPointer = TempPointer->next_ptr;
            }
        }
    }
    // printf("%s\n", printData);
    PrintMap(Map, MAXMAPSIZE);
}