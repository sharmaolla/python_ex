#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
}nnode;

nnode *getNewNode(const int number)
{
    nnode *newNode = NULL;
    newNode = malloc(sizeof(nnode));
    if (newNode != NULL)
    {
        newNode->next = NULL;
        newNode->number = number;
    }
    else
    {
        printf("Memory allocation failed!\n");
    }
    return newNode;
}

void PrintList(const nnode *first)
{
    printf("List:\n");

    if(first == NULL)
    {
        printf("List is empty\n");
    }
    else{
        const nnode *ptr = first;
        while(ptr != NULL)
        {
            printf("%-8d", ptr->number);
            ptr = ptr->next;
        }
    }
}

void CleanUp(nnode *list)
{
    nnode *next;
    while(list)
    {
        next = list->next;
        printf("\nCleaning %d", list->number);
        free(list);
        list = next;
    }
}

int main()
{
    nnode *first = NULL;
    nnode *added = NULL;

    char input[100];
    int number;

    while(1)
    {
        printf( "Enter a number or 'end' to stop: ");
        fgets(input, 100, stdin);

        if (strcmp("end\n", input) == 0)
        {
            PrintList(first);
            break;
        }
        else if(sscanf(input, "%d", &number) != 0)
        {
            if (first == NULL)
            {
                first = getNewNode(number);
                if(first != NULL)
                {
                    added = first;
                }
            }
            else
            {
                added->next = getNewNode(number);
                if(added->next != NULL)
                {
                    added = added->next;
                }
            }
        }
        else
        {
            printf("Invalid input.\n");
            break;
        }
    }
   // fflush(stdin); difference with fgets?
    CleanUp(first);

    first = NULL;
    added = NULL;

    return 0;
}
