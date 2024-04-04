
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <algorithm>

// TODO: You may need to add other libraries here!
using namespace std;


class Contact {
    // TODO: private or protected? Look at your children!
protected:
	string type;

public:
	virtual void print() = 0;
  virtual string get_contact(string style="full") = 0;
	virtual void set_contact() = 0;
};


class Email: public Contact{
private:
    string email_addr;
    string type;
public:
    Email(string _type, string _email_addr);

    // Implementing the virtual functions
    void print() override;
    string get_contact(string style) override;
    void set_contact() override;
};


class Phone: public Contact{
private:
    // TODO: modify dataType! Can int store 10 digit phone-number?
	string phone_num;
    string type;
public:
    Phone(string _type, string _phone_number);
    // virtual function implementation
    void print() override;
    string get_contact(string style) override;
    void set_contact() override;
};



#endif
