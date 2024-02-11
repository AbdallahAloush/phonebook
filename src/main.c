#include "contact.h"
#include "contact_tree.h"
#include "file.h"
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
    int count_contacts = load_file(&root);
    printf("The number of loaded contacts:\t%d", count_contacts);
    system("clear");
    inorderTraversal(root);

    printf("The number of loaded contacts:\t%d\n", count_contacts);
    // Contact another_contact = contact_from_stdin();
    // root = insert_contact(root, another_contact);
    // inorderTraversal(root);
    // char* last = "Aloush";
    // Contact* result = (Contact*) malloc(sizeof(Contact));
    // result = search_contact(root, last);
    return 0;
}
