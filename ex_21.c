#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200
#define NAME_SIZE 20

int main(){
    FILE *file;
    char file_name[NAME_SIZE];
    char line_buffer[BUFFER_SIZE];
    int xorResult;

    printf("Enter a filename:");
    fgets(file_name, NAME_SIZE, stdin);
    file_name[strcspn(file_name, "\n")]='\0';
    file = fopen(file_name, "r");
    if(file == NULL){
        fprintf(stderr, "Error opening file '%s'\n", file_name);
        return 1;
    }
    else{
        while(  fgets(line_buffer, BUFFER_SIZE, file) != NULL){
            line_buffer[strcspn(line_buffer, "\n")] = '\0';
            xorResult = 0;

            if (line_buffer[0] != '$'){
                continue;
            }
            char *asterisk = strchr(line_buffer, '*');
            if (asterisk == NULL) {
                continue;
            }
            int i = 1;
            while(line_buffer[i] != '*' && line_buffer[i] != '\0'){
                xorResult = xorResult ^ line_buffer[i];
                i++;
            }

            char hexString[20];
            sprintf(hexString, "%X", xorResult);

            char *token = strtok(asterisk + 1, " ");
            if(token != NULL){
                if(strcmp(hexString,token) == 0){
                    printf("[OK] %s\n", line_buffer);
                }
                else{
                    printf("[FAIL] %s\n", line_buffer);
                }
            }
        }
    }
    fclose(file);
    return 0;
}