
#ifndef NETWORK_H
#define NETWORK_H

#include "person.h"
#include "date.h"
#include "misc.h"
#include <stdlib.h>
class Network{

private:
    Person* head;
    Person* tail;
    int count;
    Person* search(Person* searchEntry);
    Person* search(string fname, string lname);
    bool search(string lname);
    void clearNetwork();

public:
    Network();
    Network(string fileName);
    ~Network();
    void printDB();
    void loadDB(string fileName);
    void saveDB(string fileName);
    void push_front(Person* newEntry);
    void push_back(Person* newEntry);
    bool remove(string fname, string lname);
    void showMenu();
};

#endif
