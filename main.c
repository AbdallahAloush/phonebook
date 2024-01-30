#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char const *argv[]){

    return 0;
}
