#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

char getRandomChar(){
    char random_c;
    random_c = '!' + rand() % 94;
    return random_c;
}

bool psw_generator(char *password, int size, const char *word);

bool psw_generator(char *password, int size, const char *word){
    int word_length = strlen(word);
    int psw_length = word_length * 2 + 1;

    if (size < psw_length) {
        return false;
    }

    for (int i = 0; i < psw_length; i++){
        if(i % 2 == 0){
            password[i] = getRandomChar();
        }
        else{
            password[i] = word[(i-1)/2] ;
        }
    }
    password[psw_length-1] = getRandomChar();
    return true;
}

int main() {
    srand(time(0));

    char input[32];

    char password[32];
    int onlyLetters;

    while (1) {
        printf("Enter a word to place in the password or 'stop' to quit: ");
        if(fgets(input, sizeof(input), stdin) != NULL) {
            if (strchr(input, '\n')== NULL){
                printf("Input is too lonq.\n");
                while(getchar() != '\n'){} //  reads every char and till \n and cleans buffer
            }
            else {
                onlyLetters = 1;
                input[strcspn(input, "\n")]='\0';

                for (int i = 0; input[i] != '\0'; i++) {
                    if (!isalpha(input[i])) {
                        onlyLetters = 0;
                        break; // needed?
                    }
                }
                if (onlyLetters == 0) {
                    printf("Invalid input.\n");
                }
                else if(strcmp(input, "stop") == 0) {
                    printf("Program stopped.\n");
                    break;
                }
                else {
                    bool result = psw_generator(password,sizeof(password), input);
                    if(result){
                        printf("Generated password is: %s\n", password);
                    }
                    else{
                        printf("Password does NOT fit into array and was not modified: %s\n", input);
                    }
                }

            }


        }

    }
    return 0;
}
