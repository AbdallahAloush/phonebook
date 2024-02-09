#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "contact_tree.h"
#include "contact.h"

//TODO: Add delete functionality
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
        printf("\nAdd New Contact\n");
        return root;
    }

    // Sort based on the last name
    int order_result = strcasecmp(contact.name.last, root->contact.name.last);

    if (order_result >= 0){
        root->right = insert_contact(root->right, contact);
    }
    else{
        root->left = insert_contact(root->left, contact);
    }
    return root;
}

Contact* search_contact(ContactNode* root, char* last_name){
    if (root == NULL){
        printf("\n\033[1;31mError:\033[0m Not Found\n");
        return NULL;        //! Check for this error when using the function
    }
    int result = strcasecmp(last_name, root->contact.name.last);
    if (result == 0){
        printf("\033[1;32mContact Found\033[0m\n");
        return &(root->contact);
    }
    else if (result > 0){
        return search_contact(root->right, last_name);
    }
    else {
        return search_contact(root->left, last_name);
    }
}

void inorderTraversal(ContactNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left); // Traverse left subtree
    print_contact(&(root->contact));
    inorderTraversal(root->right);// Traverse right subtree
}
