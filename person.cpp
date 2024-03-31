
#include "person.h"

Person::Person(){
    // I'm already done!
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
}


Person::Person(string f_name, string l_name, string b_date, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    birthdate = new Date(b_date);

}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!

    string input_date;
    string type;
    string address;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

    cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,input_date);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(input_date);

    cout << "Type of email address: ";
    std::getline(std::cin,type);


    cout << "Email address: ";
    std::getline(std::cin,address);

    cout << "Type of phone number: ";
    std::getline(std::cin,type);
    cout << "Phone number: ";
    // code here
    // code here
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
}

bool Person::operator!=(const Person& rhs){
    // TODO: Complete this method!
}


void Person::print_person(){
    // Already implemented for you! Do not change!
    cout << l_name <<", " << f_name << endl;
    birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
}

int main() {
    Person test();
}