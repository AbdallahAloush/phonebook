#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "contact_tree.h"
#include "contact.h"

ContactNode* new_node(Contact contact)
{
    ContactNode* contact_node = (ContactNode*) malloc(sizeof(ContactNode));
    contact_node->contact = contact;
    contact_node->left = NULL;
    contact_node->right = NULL;

    return contact_node;
}

ContactNode* insert_contact(ContactNode*root, Contact contact)
{
    if (root == NULL){
        root = new_node(contact);
        return root;
    }

    // Sort based on the last name
    int order_result = strcasecmp(contact.name.last, root->contact.name.last);

    if (order_result >= 0){
        root = insert_contact(root->right, contact);
    }
    else{
        root = insert_contact(root->left, contact);
    }
    return root;
}
