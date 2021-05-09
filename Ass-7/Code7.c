#include "ListLib.h"
#include "FileLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void prinData(NODE *a);
int main(int argc, char *argv[])
{

    NODE *FirstNode = NULL;

    ReadFileIntoLinkedList(OpenFile(argc, argv), &FirstNode);
    // NODE temp = *FirstNode;
    printf("%s", (*FirstNode).DrawCommand);
    // prinData(FirstNode);
}
void prinData(NODE *a)
{

    // NODE temp = *a;
    printf("%s\n", a->DrawCommand);
    if (a->next_ptr != NULL)
    {
        prinData(a->next_ptr);
    }
}