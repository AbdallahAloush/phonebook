#include "contact.h"
#include "contact_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

//TODO: add date of birth and address
//TODO: persist contact to a file
//TODO: validate input from user



//TODO: insert contact function

int main(int argc, char const *argv[]){
    // Contact contact = contact_from_stdin();
    // // ContactTree contact_tree = init_tree(contact);
    // print_contact(&contact_tree.root.contact);

    char* string = "a";
    char* another_string = "b";
    printf("\n%d\n", strcasecmp(another_string, string));
    return 0;
}
