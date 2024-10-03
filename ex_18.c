/*Write a program that asks user to enter a number in the range from 0 to 15 or a negative number to stop.
If user enters a number between 0 and 15 the program generates a random number and prints it in hexadecimal.
Then program shifts the number to the right by the amount user entered and uses bitwise and to clear all other bits
except bits 0-5 and prints the result in hexadecimal with two digits and leading zeros.
Note: bit numbering starts from 0*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char input[20];
    int shift_amount;
    bool status= true;
    int mask = 0b00111111; // 63 or 3F;

    srand(time(NULL));

    while(status)
    {
        printf( "Enter a number from 0 to 15 or a negative number to stop: ");
        fgets(input, 20, stdin);
        //input[strcspn(input, "\n")] = '\0';

        if(sscanf(input, "%d", &shift_amount) == 1){
           if(shift_amount < 0){
               status = false;
               printf("Program stopped.\n");
           }
           else if ( shift_amount> 15){
               printf("Invalid range.\n");

           }
           else{                                                     //valid input
               int rand_num = rand() % 256;
               printf("Random number is %02x (in hex)\n", rand_num);
               //printf("random number in decimal  is %d\n", rand_num);
               int shift_num = rand_num >> shift_amount;
               printf("Result after shifting by %d is %02x (in hex)\n", shift_amount, shift_num);
               int result = shift_num & mask;
               printf("Result in decimal: %d, in hex: %02x\n\n", result, result);

           }
        }
        else
        {
            printf("Invalid input.\n");
        }
    }

    return 0;

}