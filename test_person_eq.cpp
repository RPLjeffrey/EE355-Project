
#include <iostream>
#include "person.h"

int main(){

    Person c1;
    c1.print_person();
    cout << "----------------\n";

    Person c2("person_template.txt");
    c2.print_person();
    cout << "----------------\n";

    cout << "Is c1 equal to c2: " << (c1==c2) << endl;
    cout << "Is c1 not equal to c2: " << (c1!=c2) << endl;

    return 0;
}