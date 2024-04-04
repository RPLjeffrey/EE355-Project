#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>
#include "person.h"
#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

namespace fs = std::filesystem;

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network(){
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person *current = head;

    // outputFile << current->birthdate->get_date() << endl;
    // outputFile << current->phone->get_contact("full") << endl;
    // outputFile << current->email->get_contact("full") << endl;
    //still need to add

    while (current != NULL)
    {
      if (current->f_name == searchEntry->f_name   &&   current->l_name == searchEntry->l_name   &&   current->birthdate->get_date() == searchEntry->birthdate->get_date()
          &&   current->phone->get_contact("full") == searchEntry->phone->get_contact("full")   &&   current->email->get_contact("full") == searchEntry->email->get_contact("full"))
      {
        return current;
      }
      current = current->next;
    }

    return NULL;
}

void Network::clearNetwork() {
    Person* current = head;
    while (current != NULL) {
        Person* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}

Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname

    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly.
    Person *current = head;

    while (current != NULL)
    {
      if (current->f_name == fname  &&  current->l_name == lname)
      {
        return current;
      }
      current = current->next;
    }

    return NULL;
}

bool Network::search(string lname)
{
    bool flag = 0;
    Person *current = head;

    while (current != NULL)
    {
      if(current->l_name == lname)
      {
        current->print_person();
        cout << "--------------------" << endl;
        flag = 1;
      }
      current = current->next;
    }

    return flag;
}



void Network::loadDB(string filename){

    clearNetwork();
    ifstream file(filename);

    if (!file.is_open()) {
        // If file with name FILENAME does not exist:
        cout << "File FILENAME does not exist!" << endl;
        return;
    }

    string f_name, l_name, b_date, email_info, phone_info, line;
    while (getline(file, f_name)) {
        if (f_name.empty() || f_name == "--------------------") continue;

        getline(file, l_name);
        getline(file, b_date);

        getline(file, email_info);
        string email_type = email_info.substr(1, email_info.find(')') - 1);
        string email = email_info.substr(email_info.find(')') + 2);

        getline(file, phone_info);
        string phone_type = phone_info.substr(1, phone_info.find(')') - 1);
        string phone = phone_info.substr(phone_info.find(')') + 2);

        Person* newPerson = new Person(f_name, l_name, b_date, email, email_type, phone, phone_type);
        this->push_back(newPerson);

        // Skip the separator line if it exists before the next person block
        getline(file, line);
    }

    // If file is loaded successfully, also print the count of people in it:
    cout << "Network loaded from " << filename << " with " << count << " people \n";
    file.close();
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    Person *current = head;
    ofstream outputFile(filename);

    if (!outputFile) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return;
    }

    // Iterate over each person in the network database
    while (current != NULL)
    {
      outputFile << current->l_name << ", " << current->f_name << endl;
      outputFile << current->birthdate->get_date() << endl;
      outputFile << current->phone->get_contact("full") << endl;
      outputFile << current->email->get_contact("full") << endl;
      //still need to add
      outputFile << "------------------------------" << endl;
      current = current->next;
    }

    outputFile.close();
}


void Network::printDB(){
    // Leave me alone! I know how to print!
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;

    head = newEntry;
    count++;
}

void Network::push_back(Person* newEntry){
    newEntry->prev = tail;
    newEntry->next = NULL;

    if (tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;

    tail = newEntry;
    count++;
}


bool Network::remove(string fname, string lname){
    Person *person_rm = search(fname, lname);

    if(person_rm != NULL)
    {
        // If the person is the head of the list
        if (person_rm == head) {
            head = person_rm->next;
            if (head != NULL) { // If the list is not becoming empty
                head->prev = NULL;
            } else {
                tail = NULL; // The list is now empty
            }
        } else {
            person_rm->prev->next = person_rm->next;
        }

        // If the person is the tail of the list
        if (person_rm == tail) {
            tail = person_rm->prev;
            if (tail != NULL) { // If the list is not becoming empty
                tail->next = NULL;
            } else {
                head = NULL; // The list is now empty
            }
        } else {
            person_rm->next->prev = person_rm->prev;
        }

        delete person_rm;
        count--;
        return true;
    }

    return false;

}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you,
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "\nSelect an option ... ";

        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }

        cout << "\033[2J\033[1;1H";

        if (opt==1){
          cout << "Saving network database \n";
          cout << "Enter the name of the save file: ";
          string fileName;
          cin >> fileName;

          saveDB(fileName);

          cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            fs::path currentDir = fs::current_path();

            // Iterate over the files in the current directory
            for (const auto& entry : fs::directory_iterator(currentDir)) {
                // Check if the file is a regular file and ends with ".txt"
                if (fs::is_regular_file(entry) && entry.path().extension() == ".txt") {
                    // Print the file name
                    std::cout << entry.path().filename() << std::endl;
                }
            }
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            cout << "Enter the name of the load file: ";

            string fileName;
            cin >> fileName;

            loadDB(fileName);

            //printDB();


        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back
            // Add a new Person ONLY if it does not exists!
            Person *person = new Person;

            if (search(person) == NULL)
            {
              push_front(person);
              cout << "Adding a new person \n";
            } else
            {
              cout << "person already exists" << endl;
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            string fname, lname;
            cout << "Removing a person \n";
            cout << "First name: ";
            std::getline(std::cin,fname);
            cout << "Last name: ";
            std::getline(std::cin,lname);

            if (remove(fname,lname))
            {
              cout << "Remove Successful! \n";
            } else
            {
              cout << "Person not found! \n";
            }

        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            string lastname;
            cout << "Print people with last name \n";
            cout << "Last name: ";
            std::getline(std::cin,lastname);

            if(!search(lastname))
            {
              cout << "Person not found! \n";
            }

        }

        else
            cout << "Nothing matched!\n";

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
