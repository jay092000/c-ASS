#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct node
{
    char Letter;
    char *DrawCommand;
    struct node *next_ptr;
} NODE;
struct node *current = NULL;

void insert(char a, char DC[], NODE **aa)

{
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->Letter = a;
    link->DrawCommand = DC;

    //point it to old first node
    link->next_ptr = *aa;

    //point first to new first node
    *aa = link;
}

void main()
{
    struct node *head = NULL;
    insert('a', "AAAA", &head);
    insert('B', "BBBB", &head);
    insert('c', "CCCC", &head);
    // printf("%s",head->DrawCommand);
    struct node *ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL)
    {
        printf("(%c,%s) ", ptr->Letter, ptr->DrawCommand);
        ptr = ptr->next_ptr;
    }

    printf(" ]");
}