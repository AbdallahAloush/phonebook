#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "contact.h"
#include "contact_tree.h"

#define MAX_LINE_LENGTH 512     //TODO: optimize this length
#define MAX_PATH_LENGTH 512

int load_file(ContactNode** root){
    char filename[MAX_PATH_LENGTH];
    safe_input(filename, MAX_PATH_LENGTH, "\033[34mEnter the name of the file you want to load from:\033[0m\t");

    FILE* save_file = fopen(filename, "r");
    if (save_file == NULL){
        printf("\033[1;31merror: File does not exist\033[0m\n");
        return 0;
    }

    int i = 0;
    char buffer[MAX_LINE_LENGTH];
    ContactNode* local_root = *root;

    while(fgets(buffer, MAX_LINE_LENGTH, save_file)){
        buffer[strcspn(buffer, "\n")] = '\0';     //Remove trailing
        local_root = insert_contact(local_root, contact_from_string(buffer));
        i++;
    }
    fclose(save_file);

    return i;
}
