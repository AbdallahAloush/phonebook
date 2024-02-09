#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "contact.h"

#define MAX_LINE_LENGTH 512     //TODO: optimize this length
#define MAX_PATH_LENGTH 512

bool load_file(){
    char filename[MAX_PATH_LENGTH];
    safe_input(filename, MAX_PATH_LENGTH, "\033[34mEnter the name of the file you want to load from:\033[0m\t");

    FILE* save_file = fopen(filename, "r");
    if (save_file == NULL){
        printf("\033[1;31merror: File does not exist\033[0m\n");
        return false;
    }

    int i = 0;
    char buffer[MAX_LINE_LENGTH];
    while(fgets(buffer, MAX_LINE_LENGTH, save_file)){
        buffer[strcspn(buffer, "\n")] = '\0';     //Remove trailing
        printf("line %d: %s\n\n", i, buffer);
        i++;
    }
    fclose(save_file);

}
