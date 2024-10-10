#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define INPUT_SIZE 30
#define BUFFER_SIZE 200
#define ARRAY_SIZE 100

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
}   // ----------------------------------------------------------------------------------


int fill_struct(FILE *file, record *records, int line){
    int read;
    do{
        read = fscanf(file, "%lf,%49[^\n]", &records[line].temp, records[line].room);

        if(read == 2) line++;
        if(read != 2 && !feof(file)){
            printf("Incorrect file format.\n"); //???
        }

    } while (!feof(file) && line < ARRAY_SIZE);  // check if array is full
    return line;
} //----------------------------------------------------------------------------------------

void print_temp(char *input, record *records, int line){ // print output function
    for (int i = 0; input[i] != '\0'; i++) {   // valid input(room name) to upprecase
        input[i] = toupper(input[i]);
    }
    printf("\033[4m%s\033[0m\n", input); // underscore room name
    for (int i = 0; i < line; i++){
        if(strcasecmp(records[i].room, input)== 0){
            printf("%4.1f", records[i].temp);
            if (records[i].temp < 0 || records[i].temp > 30){
                printf(" X");
            }
            else{
                printf(" ");  // insert space before dashes?
                int dash = records[i].temp/0.5;
                for(int i= 0; i < dash; i++){
                    printf("-");
                }
            }
            printf("\n");
        }
    }
} // ----------------------------------------------------------------------------------------
int main(){
    FILE *file;

    char input[INPUT_SIZE];
    char buffer[BUFFER_SIZE];
    bool prog_run = true;
    record records[ARRAY_SIZE];

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

                line =fill_struct(file, records, line); // function 2: fill in the array of structures
                printf("%d lines were read.\n", line);

                fclose(file);

                print_temp(input, records, line); // function 3: print the result
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




//edited
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define INPUT_SIZE 30
#define BUFFER_SIZE 200
#define ARRAY_SIZE 100

typedef struct{
    double temp;
    char room[50];
}record;

int check_input(char *input, record *records, int line) { // input validation function --------------------------------------------
    if (strchr(input, '\n')== NULL){
        printf("Input is too long.\n");             // or fprintf(stderr, "Error"); ?
        while(getchar() != '\n'){}                         //  reads every char until \n and cleans buffer
    }
    else {
        input[strcspn(input, "\n")] = '\0';
        if (strcasecmp(input, "end") == 0) {
            printf("Program stopped.\n");
            return 0;
        }
        else{
            int match_found;
            for(int i = 0; i < line;  i++) {
                if (strcasecmp(input, records[i].room) == 0) {
                    match_found = 1;
                }
            }
            if(match_found){
                return 1;
            }
            else{
                printf("ERROR. Invalid input OR ROOM '%s' does NOT exist.\n", input);
                printf("----------------------------------\n\033[4mVALID ROOMS:\033[0m\n");
                int same_room;
                int diff_rooms = 0;
                for(int i = 0; i < line; i++) {
                    same_room = 0;
                    for(int j = 0  ; j < i; j++){
                        if (strcmp(records[i].room, records[j].room) == 0){
                            same_room =1;
                            break;
                        }
                    }
                    if(!same_room){
                        printf("%s\n",records[i].room);
                        diff_rooms++;
                    }
                }
                printf("----------------------------------\n");
                return 2;
            }
        }
    }
}   // ----------------------------------------------------------------------------------

int fill_struct(FILE *file, record *records, int line){
    int read;
    do{
        read = fscanf(file, "%lf,%49[^\n]", &records[line].temp, records[line].room);

        if(read == 2) line++;
        if(read != 2 && !feof(file)){
            printf("Incorrect file format.\n");
        }

    } while (!feof(file) && line < ARRAY_SIZE);  // check if array is full
    return line;
} //----------------------------------------------------------------------------------------

void print_temp(char *input, record *records, int line){ // print output function
    for (int i = 0; input[i] != '\0'; i++) {             // valid input(room name) to uppercase
        input[i] = toupper(input[i]);
    }
    printf("\n\033[4m%s\033[0m\n", input);          // underscore room name
    for (int i = 0; i < line; i++){
        if(strcasecmp(records[i].room, input)== 0){
            printf("%4.1f", records[i].temp);
            if (records[i].temp < 0 || records[i].temp > 30){
                printf(" X");
            }
            else{
                printf(" ");  // insert space before dashes?
                int dash = records[i].temp/0.5;
                for(int i= 0; i < dash; i++){
                    printf("-");
                }
            }
            printf("\n");
        }
    }
} // ----------------------------UPDATED
/*int main(){
    FILE *file;

    char input[INPUT_SIZE];
    char buffer[BUFFER_SIZE];
    bool prog_run = true;
    record records[ARRAY_SIZE];

    while(prog_run) {
        int line = 0; // initially no lines read
        file = fopen("Temperatures.circ", "r");

        if (file == NULL) {
            fprintf(stderr, "Error opening file.\n");
            return 1;
        }
        fgets(buffer, BUFFER_SIZE, file);  // read in the 1st line

        line =fill_struct(file, records, line); // function 1: fill in the array of structures
        printf("/%d lines were read successfully/\n", line);

        fclose(file);

        printf("Enter a room to display temperatures inside OR 'end' to stop: ");

        if (fgets(input, INPUT_SIZE, stdin) != NULL) {

            int status = check_input(input, records, line); // function 2: validate input

            if (status == 1) {
                print_temp(input, records, line); // function 3: print the result
            }
            else if(status == 0){
                prog_run = false;
            }
            else{  // when status = 2
                prog_run = true;
            }
        }
    }
    return 0;
}*/
