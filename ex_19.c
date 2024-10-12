#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT 20
#define MAX_ARRAY 40
#define MAX_LINE 100

typedef struct menu_item{
    char name[50];
    double price;
}menu_item;

int comparePrice(const void *pa, const void *pb);
int compareName(const void *pa, const void *pb);
void print_sorted(const menu_item *items, int numItems, int result);
int options(char selection, menu_item *items, int numItems, bool *select_done, bool *stop_entered);

int comparePrice(const void *pa, const void *pb){
    const menu_item *p1 = (const menu_item *)pa;
    const menu_item *p2 = (const menu_item *)pb;
    if(p1->price > p2->price){
        return 1;
    }
    if(p1->price < p2->price){
        return -1;
    }
    else{
        return 0;
    }
}//---------------------------------------------------------------------------------------------------

int compareName(const void *pa, const void *pb){
    const menu_item *p1 = (const menu_item *)pa;
    const menu_item *p2 = (const menu_item *)pb;
    return strcmp(p1->name, p2->name);
}//---------------------------------------------------------------------------------------------------

void print_sorted(const menu_item *items, int numItems, int result){
    if(result == 1){
        printf("\n\033[4mSORTED BY PRICE\033[0m\n");
    }
    else if(result == 2){
        printf("\n\033[4mSORTED BY NAME\033[0m\n");
    }
    for(int i = 0; i < numItems; i++) {
        printf("%-8.2f %s\n", items[i].price, items[i].name);
    }
}//---------------------------------------------------------------------------------------------------

int options(char selection, menu_item *items, int numItems, bool *select_done, bool *stop_entered){
    switch(selection){
        case '1':
            qsort(items, numItems, sizeof(menu_item), comparePrice);
            *select_done = true;
            fflush(stdin);
            return 1;

        case '2':
            qsort(items, numItems, sizeof(menu_item), compareName);
            *select_done= true;
            fflush(stdin);
            return 2;
        case 's':
            printf("Program stopped.\n");
            *stop_entered = true;
            *select_done = true;
            fflush(stdin);
            return 0;
        default:
            printf("Invalid input.\n");
            *select_done= true;
            fflush(stdin);
            return 0;
    }
}//------------------------------------------------------------------------------------------------------------

int main(){
    FILE *file;
    menu_item items[MAX_ARRAY];
    int numItems = 0;
    int error = 0;
    char input[MAX_INPUT];
    char line[MAX_LINE];
    bool select_done = false;
    bool stop_entered= false;
    bool correct_file = false;

    while(!correct_file){
        numItems = 0;
        error = 0;
        fflush(stdin);
        printf("Enter a filename: ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")]='\0';

        file = fopen(input, "r");
        if(file == NULL){
            fprintf(stderr, "Error opening file '%s'\n", input);
            continue;
        }
        while(fgets(line, MAX_LINE, file)!=NULL && numItems < MAX_ARRAY){
            if(sscanf(line, "%49[^;]; %lf", items[numItems].name, &items[numItems].price)==2){// set the length
                numItems++;
            }
            else{
                error++;
            }
        }
        fclose(file);

        if (numItems == 0){
            printf("Unable to read the file '%s'\n", input);
            correct_file = false;
        }
        else{
            correct_file = true;
        }

        printf("---------------------\n");
        printf("Lines read: %d\nUnable to read %d line(s).\n", numItems,error);
        printf("---------------------\n");
        for(int i = 0; i < numItems; i++) {
            printf("%-8.2f %s\n", items[i].price, items[i].name);
        }
    }

    while(!stop_entered){
        select_done = false;
        while(!select_done){
            char selection;
            printf("\nHow would you like to sort menu?\nby PRICE     (enter 1)\nby ITEM NAME (enter 2)\nTo STOP (Enter 's')\nEnter your choice here:");
            scanf(" %c", &selection);

            int result = options(selection, items, numItems, &select_done, &stop_entered);
            if(result == 1 || result == 2){
                print_sorted(items, numItems, result);
            }
        }
    }
    return 0;
}
