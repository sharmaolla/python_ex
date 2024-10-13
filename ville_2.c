/*Write a program that reads input lines using read_line-function.
read_line returns true if input was read and false when input ends. Each line contains two numbers and
a command "add", "sub", "mul", or "div". Program reads lines one by one and checks that input is valid
(first 2 integers then a string that is a valid command). If line is not properly formatted the program prints the line
and displays an error message. For each properly formatted line the program prints out a calculation which is determined by the command.
For example input that contains:
7 2 sub
43 -3 add
ill make the program print:
7 - 2 = 5
43 + -3 = 40

If the input can't be parsed then program
must print the invalid line and an error message that describes
the location of the error. See the example solution output for details.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE 100

int main(){
    int num1= 0;
    int num2 = 0;
    char operand[10];
    int line = 0;
    int error = 0;
    int suc_line = 0;

    FILE *file;
    char buffer[BUFFER_SIZE];

    file = fopen("test.txt", "r");
    if(file == NULL){
        fprintf(stderr, "Error opening file.\n");
    }
    else{
        while(!feof(file)){
            int read = fscanf(file, "%d %d %5[^\n]", &num1, &num2, operand); // operand used as a pointer to the first element
            if (read != 3) {
                error++;
                printf("Unable to read %d\n", line+1);
                                                                        // Clear the buffer if fscanf didn't match all three expected items
                int ch;
                while ((ch = fgetc(file)) != '\n' && ch != EOF) {      // Consume characters until the end of the line or file
                }
            }
            else{
                int j = 0;                                             // delete white spaces if they are
                for (int i = 0; i < strlen(operand); i++) {
                    if (!isspace((unsigned char)operand[i])) {
                        operand[j++] = operand[i];
                    }
                }

                operand[j] = '\0';     // Add null terminator to the cleaned operand

                if(strcmp(operand, "add") == 0){
                    int result = num1 + num2;
                    printf("%d + %d = %d\n", num1, num2, result);
                    suc_line++;
                }
                else if(strcmp(operand, "sub") == 0){
                    int result = num1 - num2;
                    printf("%d - %d = %d\n", num1, num2, result);
                    suc_line++;
                }
                else if(strcmp(operand, "mul") == 0){
                    int result = num1 * num2;
                    printf("%d * %d = %d\n", num1, num2, result);
                    suc_line++;
                }
                else if(strcmp(operand, "div") == 0){
                    float result = num1 / num2;
                    printf("%d / %d = %.2f\n", num1, num2, result);
                    suc_line++;
                }
                else{
                    printf("Operand error.\n");
                }
                line++;
            }
        }
        printf("/TOTAL: %d lines were read successfully/\n", suc_line);
        printf("/TOTAL: Unable to read %d lines/\n", error);
    }


    fclose(file);

    return 0;
}