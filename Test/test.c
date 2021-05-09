#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char i[100];
    printf("\nEnter draw command (enter Q to quit)");
    scanf("%s", i);
    printf("\n%s",i);
    char *token = strtok(i, ",");
    // loop through the string to extract all other tokens
    while (token != NULL)
    {
        printf(" %s\n", token); //printing each token
        token = strtok(NULL, ",");
    }
    return 1;
}
