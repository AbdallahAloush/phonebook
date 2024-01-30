#include <stdio.h>
#include <stdlib.h>
#include "contact_tree.h"
#include "contact.h"

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
