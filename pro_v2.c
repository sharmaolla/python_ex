#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define INPUT_SIZE 30
#define BUFFER_SIZE 200

typedef struct{
    double temp;
    char room[50];
}record;


int check_input(char *input) { // input validation function --------------------------------------------
    int status_number;
    if (strchr(input, '\n')== NULL){
        printf("Input is too long.\n");             // or fprintf(stderr, "Error"); ?
        while(getchar() != '\n'){}                         //  reads every char until \n and cleans buffer
    }
    else {
        input[strcspn(input, "\n")] = '\0';
        if (strcasecmp(input, "end") == 0) {
            printf("Program stopped.");
            status_number = 0;
            return status_number;
        }

        else if(strcasecmp(input, "Kitchen")== 0 || strcasecmp(input, "Bedroom")== 0 || strcasecmp(input, "Living room")== 0){
            status_number = 1;
            return status_number;
        }

        else{
            printf("ERROR. Invalid input OR ROOM '%s' does NOT exist.\n", input);
            status_number = 2;
            return status_number;
        }
    }
}   // function ends--------------------------------------------------------------------


int fill_struct(FILE *file, record *records, int line){
    int read;
    do{
        read = fscanf(file, "%lf,%49[^\n]", &records[line].temp, records[line].room);

        if(read == 2) line++;
        if(read != 2 && !feof(file)){
            printf("Incorrect file format.\n"); //???
        }

    } while (!feof(file));  // check if array is full   while (!feof(file) || line = 101);*/
    return line;
} //function ends----------------------------------------------------------------------------------------

void print_temp(char *input, record *records, int lines_read){ // print output function
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] = toupper(input[i]);
    }
    printf("\033[4m%s\033[0m\n", input);
    for (int i = 0; i < lines_read; i++){
        if(strcasecmp(records[i].room, input)== 0){
            printf("%4.1f", records[i].temp);
            if (records[i].temp < 0 || records[i].temp > 30){
                printf(" X");
            }
            else{
                printf(" ");  // insert space before dashes?
                int dash = records[i].temp/0.5;
                for(int j = 0; j <dash; j++){
                    printf("-");
                }
            }
            printf("\n");
        }
    }
} //function ends ----------------------------------------------------------------------------------------
int main(){
    FILE *file;

    char input[INPUT_SIZE];
    char buffer[BUFFER_SIZE];
    bool prog_run = true;
    record records[100];

    while(prog_run) {
        int line = 0; // initially no lines read

        printf("Enter a room to display temperatures inside OR 'end' to stop: ");

        if (fgets(input, INPUT_SIZE, stdin) != NULL) {

            int status = check_input(input); // function 1: validate input

            if (status == 1) {
                file = fopen("Temperatures.circ", "r");

                if (file == NULL) {
                    fprintf(stderr, "Error opening file.\n"); //???
                    return 1;
                }
                fgets(buffer, BUFFER_SIZE, file);  // read in the 1st line

                int lines_read =fill_struct(file, records, line); // function 2: fill in the array of structures

                fclose(file);

                //printf("There are %d lines in the file.\n", lines_read);

                print_temp(input, records, lines_read); // function 3: print the result
            }
            else if(status == 0){
                prog_run = false;
            }
            else{  // when status_number = 2
                prog_run = true;
            }
        }
    }
    return 0;
}