#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
// TODO: You may need to add other libraries here!
using namespace std;


class Date {
    // TODO: private or protected? Look at your children!
protected:
    int month;
    string month_name;
    int day;
    int year;
    string original_date_string;
public:
    Date(string date);
    void print_date();
    string get_date();
    string get_og_date();
};
#endif
