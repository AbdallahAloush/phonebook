#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 35
#define MAX_EMAIL_LENGTH 320    //according to RFC 5321
#define MAX_PHONE_LENGTH 35     //according to ITU the max length of a phonenumber is 15 digits

typedef struct{
    char first[MAX_NAME_LENGTH];
    char last[MAX_NAME_LENGTH];
}Name;
//TODO: add date of birth and address
//TODO: persist contact to a file
typedef struct{
    Name name;
    char email[MAX_EMAIL_LENGTH];
    char phonenumber[MAX_PHONE_LENGTH];
}Contact;


// We will start by building the project in-memory

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

void print_contact(Contact* contact){
    printf("Contact:{\n");
    printf("\tName:\t%s %s\n", contact->name.first, contact->name.last);
    printf("\tEmail:\t%s\n", contact->email);
    printf("}\n");
}

int main(int argc, char const *argv[]){
    Contact contact = new_contact();
    print_contact(&contact);
    return 0;
}
