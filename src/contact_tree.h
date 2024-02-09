#ifndef CONTACT_TREE_H
#define CONTACT_TREE_H

#include "contact.h"

typedef struct ContactNode{
    Contact contact;
    struct ContactNode* left;
    struct ContactNode* right;
}ContactNode;

ContactNode* insert_contact(ContactNode* root, Contact contact);

Contact* search_contact(ContactNode* root, char* last_name);

void inorderTraversal(ContactNode* root);
#endif
