
#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"
class Person{
    friend class Network;

private:
    string f_name;
    string l_name;
    Date *birthdate;
    Email *email;
    Phone *phone;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;

public:
    Person();
    ~Person();
    Person(string filename);
    Person(string first_name, string last_name, string b_date, string email, string email_type, string phone, string phone_type);
    //
    void print_person();
    void set_person();
    void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
};
#endif
