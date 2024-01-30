#include "contact.h"

//TODO: add date of birth and address
//TODO: persist contact to a file
//TODO: validate input from user

int main(int argc, char const *argv[]){
    Contact contact = new_contact();
    print_contact(&contact);
    return 0;
}
