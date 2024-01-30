#include "contact.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_contact(Contact* contact){
    printf("Contact:{\n");
    printf("\tName:\t%s %s\n", contact->name.first, contact->name.last);
    printf("\tEmail:\t%s\n", contact->email);
    printf("}\n");
}

void safe_input(char* destination, size_t max_length, const char* prompt){
    printf("%s", prompt);
    if(fgets(destination, max_length, stdin) == NULL){
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    destination[strcspn(destination, "\n")] = '\0';     //Remove trailing
}

Contact new_contact(){
    Contact new_contact;

    safe_input(new_contact.name.first, MAX_NAME_LENGTH, "Enter first name:\t");
    safe_input(new_contact.name.last, MAX_NAME_LENGTH, "Enter last name:\t");
    safe_input(new_contact.email, MAX_EMAIL_LENGTH, "Enter email:\t");

    return new_contact;
}
