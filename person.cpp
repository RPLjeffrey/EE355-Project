
#include "person.h"
#include "date.h"
#include "contact.h"
#include "fstream"
using namespace std;

Person::Person(){
    // I'm already done!
    set_person();
}


Person::~Person(){
    delete birthdate;
    delete email;
    delete phone;
}


Person::Person(string first_name, string last_name, string b_date, string new_email, string new_email_type, string new_phone, string new_phone_type){
    // TODO: Complete this method!
    // phone and email strings are in full version
    f_name = first_name;
    l_name = last_name;
    birthdate = new Date(b_date);
    email = new Email(new_email_type, new_email);
    phone = new Phone(new_phone_type, new_phone);

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
    string phone_number;

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
    email = new Email(type, address);

    cout << "Type of phone number: ";
    std::getline(std::cin,type);
    cout << "Phone number: ";
    std::getline(std::cin,phone_number);
    phone = new Phone(type, phone_number);

}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    fstream person_file;
    person_file.open(filename);
    string input1;
    string input2;
    if (!person_file) {
        cout << "Error opening file" << endl;
    } else {
        getline(person_file, input1);
        f_name = input1;
        getline(person_file, input1);
        l_name = input1;
        getline(person_file, input1);
        birthdate = new Date(input1);

        person_file >> input1;
        input1 = input1.substr(1, input1.length()-2);
        person_file >> input2;
        phone = new Phone(input1, input2);

        person_file >> input1;
        input1 = input1.substr(1, input1.length()-2);
        person_file >> input2;
        email = new Email(input1, input2);

    }


}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    return 0;
}

bool Person::operator!=(const Person& rhs){
    // TODO: Complete this method!
    return 0;
}


void Person::print_person(){
    // Already implemented for you! Do not change!
    cout << this->l_name  << ", " << this->f_name << endl;
    birthdate->print_date();
    phone->print();
    email->print();
}
