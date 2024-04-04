#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
// TODO: You may need to add other libraries here!
using namespace std;


class Date {
    // TODO: private or protected? Look at your children!
protected:
    string original_date_string;
    int month;
    string month_name;
    int day;
    int year;
public:
    Date(string date);
    void print_date();
    string get_date();
};
#endif
