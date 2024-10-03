#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
 // quit the program
 // header line
 //use define
 //use functions
 //stderr

typedef struct{
    double temp;
    char room[50];

}record;

int main(){
    FILE *file;
    record records[100];



    char input[20];  // define size using #define
    //bool validInput = true;

    while(1){
        int line = 0;
        int read;

        printf("Enter a room to display temperatures in there: ");
        if(fgets(input, sizeof(input), stdin) != NULL) {
            if (strchr(input, '\n')== NULL){
                //validInput = false;
                printf("Input is too long.\n"); // or fprintf(stderr, "Error"); return 1;
                //return 1;
                while(getchar() != '\n'){} //  reads every char until \n and cleans buffer
            }
            else {
                input[strcspn(input, "\n")] = '\0';
                if(strcasecmp(input, "Kitchen")== 0 || strcasecmp(input, "Bedroom")== 0 || strcasecmp(input, "Living room")== 0){
                    //printf("Main code here.\n");
                    file = fopen("Temperatures.circ", "r");
                    if(file == NULL){
                        fprintf(stderr, "Error opening file.\n"); //???
                        return 1;
                    }
                    do{
                        read = fscanf(file, "%lf,%49[^\n]", &records[line].temp, records[line].room);

                        if(read == 2) line++;
                        if(read != 2 && !feof(file)){
                            printf("Incorrect file format.\n"); //???
                            return 1;
                        }
                        /*if(ferror(file)){
                            fprintf(stderr,"Error reading file.\n"); //??
                            return 1;
                        }*/

                    } while (!feof(file));
                    fclose(file);

                    printf("There are %d lines in the file.\n", line);
                    for (int i = 0; input[i] != '\0'; i++) {
                        input[i] = toupper(input[i]);
                    }
                    printf("\033[4m%s\033[0m\n", input);
                    for (int i = 0; i < line; i++){
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
                    printf("\n");

                }
                else{
                    printf("ERROR. Invalid input OR ROOM '%s'   does NOT exist.\n\n", input); // 2 cases here?
                }
            }
        }
    }


}