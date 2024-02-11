#include "contact.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_contact(Contact* contact){
    printf("Contact:{\n");
    printf("\tName:\t%s %s\n", contact->name.first, contact->name.last);
    printf("\tEmail:\t%s\n", contact->email);
    printf("\tPhone Number:\t%s\n", contact->phonenumber);
    printf("}\n");
}

void safe_input(char* destination, size_t max_length, const char* prompt){
    printf("%s", prompt);
    if(fgets(destination, max_length, stdin) == NULL){
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    destination[strcspn(destination, " \n")] = '\0';     //Remove trailing
}

Contact contact_from_stdin(){
    Contact new_contact;

    safe_input(new_contact.name.first, MAX_NAME_LENGTH, "Enter first name:\t");
    safe_input(new_contact.name.last, MAX_NAME_LENGTH, "Enter last name:\t");
    safe_input(new_contact.email, MAX_EMAIL_LENGTH, "Enter email:\t");
    safe_input(new_contact.phonenumber, MAX_PHONE_LENGTH, "Enter phonenumber:\t");
    return new_contact;
}

Contact contact_from_string(char* contact_line){
    Contact new_contact;
    const char delimeter[] = ",";
    char* token;
    int i = 0;

    token = strtok(contact_line, delimeter);
    while(token!=NULL){
        // if iterator equal zero it will use the first name
        // if equal 1 it will use the second name
        // if equal 2 it will use the third name
        // printf(" %s\n", token);
        int token_len = strlen(token)+1;
        // printf("This is the length of the token: %d\n and %d", token_len, i);
        switch (i)
        {
        case 0:
            strncpy(new_contact.name.first, token, token_len);
            break;
        case 1:
            strncpy(new_contact.name.last, token, token_len);
            break;
        case 4:
            strncpy(new_contact.email,token, token_len);
            break;
        case 5:
            strncpy(new_contact.phonenumber,token, token_len);
            break;
        default:
            printf("\033[1;31m\nTODO:Address\nTODO:DOB\n\033[0m");
            break;
        }
        token = strtok(NULL, delimeter);
        i++;
    }
    print_contact(&new_contact);
    return new_contact;

}
