#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: add date of birth and address
//TODO: persist contact to a file
//TODO: validate input from user
typedef struct ContactNode{
    Contact contact;
    struct ContactNode* left;
    struct ContactNode* right;
}ContactNode;

typedef struct{
    ContactNode root;
    int contact_count;
}ContactTree;

ContactNode new_node(Contact contact){
    ContactNode contact_node;
    contact_node.contact = contact;
    contact_node.left = NULL;
    contact_node.right = NULL;
    return contact_node;
}

ContactTree init_tree(Contact contact){
    ContactTree contact_tree;
    contact_tree.root = new_node(contact);
    contact_tree.contact_count = 1;
    return contact_tree;
}

//TODO: insert contact function

int main(int argc, char const *argv[]){
    Contact contact = contact_from_stdin();
    ContactTree contact_tree = init_tree(contact);
    print_contact(&contact_tree.root.contact);
    return 0;
}
