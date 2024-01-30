#ifndef CONTACT_H
#define CONTACT_H

#include <stddef.h>

#define MAX_NAME_LENGTH 35
#define MAX_EMAIL_LENGTH 320    //according to RFC 5321
#define MAX_PHONE_LENGTH 35     //according to ITU the max length of a phonenumber is 15 digits

typedef struct{
    char first[MAX_NAME_LENGTH];
    char last[MAX_NAME_LENGTH];
}Name;

typedef struct{
    Name name;
    char email[MAX_EMAIL_LENGTH];
    char phonenumber[MAX_PHONE_LENGTH];
}Contact;

void print_contact(Contact* contact);

void safe_input(char* destination, size_t max_length, const char* prompt);

Contact contact_from_stdin();

#endif
