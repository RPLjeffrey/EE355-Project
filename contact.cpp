
#include "contact.h"
// TODO: Add needed libraries!

Email::Email(string type, string email_addr){
    // TODO: Complete me!
}


void Email::set_contact(){
    // TODO: Do not change the prompts!

    cout << "Enter the type of email address: ";
    // some code here
    cout << "Enter email address: ";
    // some code here
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
        return "(" + type + ") " + email_addr;
    else
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
    cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!


}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    cout <<"Enter the type of phone number: ";
    cout << "Enter the phone number: ";
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email

}


void Phone::print(){
    // Note: get_contact is called with default argument
    cout << get_contact() << endl;
}
