
#include "contact.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


Email::Email(string _type, string _email_addr){
    // TODO: Complete me!
    type = _type;
    email_addr = _email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
    cout << "Enter the type of email address: ";
    cin >> type;

    cout << "Enter email address: ";
    cin >> email_addr;
}

string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style == "full")
        return "Email (" + type + "): " + email_addr;
    else
        return email_addr;
}

string Email::get_db_contact(){
    // Format for DB implementation
        return "(" + type + ") " + email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
    // printf("Email (%s): %s", type, email_addr);
    cout << get_contact("full") << endl;
}


Phone::Phone(string _type, string _num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    type = _type;

    phone_num = _num;

    // easiest for us to go through and remove all hyphens and then add them back. This will allow
    // us in the future to remove different special characters from phone numbers
    // and makes our data formatting more robust

    // go through and remove all hyphens
    phone_num.erase(remove(phone_num.begin(), phone_num.end(), '-'), phone_num.end());

    // add back the hyphens
    phone_num = phone_num.substr(0,3) + "-" + phone_num.substr(3,3) + "-" + phone_num.substr(6);

}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    cout <<"Enter the type of phone number: ";
    cin >> type;
    cout << "Enter the phone number: ";
    cin >> phone_num;

    // go through and remove all hyphens
    phone_num.erase(remove(phone_num.begin(), phone_num.end(), '-'), phone_num.end());


    // add back the hyphens
    phone_num = phone_num.substr(0,3) + "-" + phone_num.substr(3,3) + "-" + phone_num.substr(6);
}

string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email
    if (style == "full")
        return "Phone (" + type + "): " + phone_num;
    else
        return phone_num;
}

string Phone::get_db_contact(){
    // Format for DB implementation
        return "(" + type + ") " + phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
    cout << get_contact("full") << endl;
}
