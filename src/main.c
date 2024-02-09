#include "contact.h"
#include "contact_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

//TODO: add date of birth and address
//TODO: persist contact to a file
//TODO: validate input from user

int main(int argc, char const *argv[]){
    ContactNode* root = (ContactNode*)malloc(sizeof(ContactNode));
    root = NULL;
    Contact new_contact = contact_from_stdin();
    root = insert_contact(root, new_contact);
    Contact another_contact = contact_from_stdin();
    root = insert_contact(root, another_contact);

    return 0;
}
