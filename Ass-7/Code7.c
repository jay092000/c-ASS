#include "ListLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    struct node FirstNode;
    // File Read Pointer For Closing File Reading
    FILE *fptr;
    if (argc < 2)
    {
        printf("Please Enter Valid File Name\n");
        return 0;
    }
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("File Name Is InValid\n");
        return 0;
    }
    char line[500];

    while (fgets(line, sizeof(line), fptr))
    {
        // printf("%c\n", line[0]);
        // printf("%s", line);
        char *firstchar = strtok(line,"|");
        printf(" %s\n", firstchar); //printing each token
        char *dc = strtok(NULL, "|");
        printf(" %s\n", dc); //printing each token
        AddDrawCommandToList(firstchar,dc,&FirstNode.next_ptr);
    }
    fclose(fptr);
}