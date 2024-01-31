#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "contact_tree.h"
#include "contact.h"

ContactNode new_node(Contact contact)
{
    ContactNode contact_node;
    contact_node.contact = contact;
    contact_node.left = NULL;
    contact_node.right = NULL;
    return contact_node;
}

// ContactTree init_tree(Contact contact){
//     ContactTree contact_tree;
//     contact_tree.root = new_node(contact);
//     contact_tree.contact_count = 1;
//     return contact_tree;
// }

void insert_contact(ContactNode *root, Contact contact)
{
    if (root == NULL){
        *root = new_node(contact);
        return;
    }

    // Sort based on the last name
    int order_result = strcasecmp(contact.name.last, root->contact.name.last);

    if (order_result >= 0){
        insert_contact(root->right, contact);
    }
    else{
        insert_contact(root->left, contact);
    }
}
