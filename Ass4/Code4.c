#include "DrawTool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

int check(int, int, int *, int, char);
void main()
{
    char arr[MAXMAPSIZE][MAXMAPSIZE];
    char bgChar;
    int size, temp;

    char *mark, LineType, *token;

    int i, j;
    while (1)
    {
        printf("How big is the array? (Enter a value between 1 and 20) ");
        scanf("%d", &size);

        if (size < 21 || 0 < size)
        {
            break;
        }
        else
        {
            printf("That value is outside of the max bounds of the array. Please reenter \n");
        }
        printf("\n");
    }
    printf("\n");
    printf("What is the background character?");
    scanf(" %c", &bgChar);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arr[i][j] = bgChar;
        }
    }
    PrintInstructions();
    getchar();
    PrintMap(arr, size);
    while (1)
    {
        int from, to, count;
        char inputStr[40];
        printf("\nEnter draw command (enter Q to quit)");
        scanf("%s", inputStr);
        char tempString[40];
        i = 2;
        j = 0;
        while (inputStr[i + j] != ')')
        {
            tempString[j] = inputStr[i + j];
            j++;
        }
        i = 0;
        char *token = strtok(tempString, ",");
        if (token== NULL)
        {
            printf("Invalid Input");
        }
        from = atoi(token);
        token = strtok(NULL, ",");
        if (token== NULL)
        {
            printf("Invalid Input");
        }
        to = atoi(token);
        token = strtok(NULL, ",");
        if (token== NULL)
        {
            printf("Invalid Input");
        }
        count = atoi(token);
        printf("%d %d %d \n", from, to, count);
        if (inputStr[0] == 'q' || inputStr[0] == 'Q')
        {
            break;
        }
        else
        {
            temp = check(from, to, &count, size, inputStr[0]);
            if (temp == 1)
            {
                DrawLine(arr, from, to, inputStr[0], count, inputStr[strlen(inputStr) - 1]);
            }
            else
            {
            }
        }
        PrintMap(arr, size);
    }
}

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