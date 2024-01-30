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
void new_contact(){
    Contact new_contact;
    char* scanner = malloc(sizeof(char)*MAX_EMAIL_LENGTH);
    printf("Enter the first name:\t");
    fgets(scanner, MAX_EMAIL_LENGTH, stdin);
    strcpy(new_contact.name.first, scanner);
    printf("Enter the last name:\t");
    fgets(scanner, MAX_EMAIL_LENGTH, stdin);
    strcpy(new_contact.name.last, scanner);
    printf("Enter the email:\t");
    fgets(scanner, MAX_EMAIL_LENGTH, stdin);
    strcpy(new_contact.email, scanner);
}

int main(int argc, char const *argv[]){
    new_contact();
    return 0;
}
