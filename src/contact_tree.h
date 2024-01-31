#ifndef CONTACT_TREE_H
#define CONTACT_TREE_H

#include "contact.h"

typedef struct ContactNode{
    Contact contact;
    struct ContactNode* left;
    struct ContactNode* right;
}ContactNode;

// typedef struct{
//     ContactNode root;
//     int contact_count;
// }ContactTree;

// ContactNode new_node(Contact contact);
// ContactTree init_tree(Contact contact);
void insert_contact(ContactNode* root, Contact contact);
#endif
