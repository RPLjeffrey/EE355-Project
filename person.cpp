
#include "person.h"
#include "date.h"
#include "contact.h"
#include "fstream"
#include "misc.h"
#include <map>
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
  //
    // TODO: Complete this method!
    // phone and email strings are in full version
    first = first_name;
    last = last_name;
    birthdate = new Date(b_date);
    email = new Email(new_email_type, new_email);
    phone = new Phone(new_phone_type, new_phone);
    ID = codeName(first, last);

}

Person::Person(string filename){
    set_person(filename);
    ID = codeName(first, last);
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
    std::getline(std::cin,this->first);

    cout << "Last Name: ";
    std::getline(std::cin,this->last);

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
        this->first = input1;
        getline(person_file, input1);
        this->last = input1;
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

void Person::makeFriend(Person* newFriend)
{
    int cnt = count(friends.begin(), friends.end(), newFriend);
    if (cnt == 0) {
      friends.push_back(newFriend);
    }

}


bool Person::operator==(const Person& rhs){
    if (this->first == rhs.first   &&   this->last == rhs.last   &&   this->birthdate->get_date() == rhs.birthdate->get_date())
    {
      return 1;
    }
    return 0;
}

bool Person::operator!=(const Person& rhs){
    // TODO: Complete this method!
    return !operator==(rhs);
}


void Person::print_person(){
    // Already implemented for you! Do not change!
    cout << this->last  << ", " << this->first << endl;
    birthdate->print_date();
    phone->print();
    email->print();

    for(auto it = friends.begin(); it != friends.end(); ++it)
    {
      cout << (*it)->get_id() << endl;
    }
}

string Person::get_id()
{
  string output = ID + " (" + first + " " + last + ")";
  return output;
}

string Person::get_plain_id()
{
  return ID;
}

void Person::pprint_friends() {
  cout << this->first << ", " << this->last << endl;
  cout << "------------------------------" << endl;

  vector<string> friend_ids;
  vector<Person*> sorted_friends;
  // friend_map is used to map the unique id to the pointer of the Person in the friend list
  map<string, Person*> friend_map;
  // Iterates through friend list of pointesr
  for(auto it = friends.begin(); it != friends.end(); ++it)
  {
    // Maps the unique id to the pointer
    friend_map[(*it)->get_plain_id()] = *it;
    // Stores the ids of the friends in friend_ids vector
    friend_ids.push_back((*it)->get_plain_id());
  }
  // Sorts friend_ids in alphabetic order
  sort(friend_ids.begin(), friend_ids.end());

  // Iterates through sorted vector of unique ids
  for(auto it2 = friend_ids.begin(); it2 != friend_ids.end(); ++it2) {
    // Accesses the pointer to the Person object associated with the id to get proper first and last name
    cout << friend_map[*it2]->first << ", " << friend_map[*it2]->last << endl;
  }

}
