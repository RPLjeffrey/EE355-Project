
#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"
class Person{
    friend class Network;

private:
    string first;
    string last;
    Date *birthdate;
    Email *email;
    Phone *phone;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;
    string ID;

    vector <Person *> friends;


public:

    Person();
    ~Person();
    Person(string, string);
    Person(string filename);
    Person(string, string, string, string, string, string, string);
    //
    string get_id();
    string get_plain_id();
    void print_person();
    void print_person_2();
    void makeFriend(Person*);
    void set_person();
    void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
    void pprint_friends();
};
#endif
