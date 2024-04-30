#include "date.h"
#include <iostream>
#include <string>
#include <sstream>

Date::Date(string date) {
    original_date_string = date;
    // Finds first instance of '/' character for month
    int slash_index = date.find("/");

    string month_str = date.substr(0, slash_index);
    month = stoi(month_str);

    // Finds second instance of '/' character that separates day and year
    int new_slash_index = date.find("/", slash_index + 1);

    string day_str = date.substr(slash_index + 1, new_slash_index - (slash_index + 1));
    day = stoi(day_str);

    string year_str = date.substr(new_slash_index + 1);
    year = stoi(year_str);

}

void Date::print_date() {
    switch(month) {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
        default:
            month_name = "Month out of range";
    }

    cout << month_name << " " << day << ", " << year << endl;
}

string Date::get_date()
{
  switch(month) {
      case 1:
          month_name = "January";
          break;
      case 2:
          month_name = "February";
          break;
      case 3:
          month_name = "March";
          break;
      case 4:
          month_name = "April";
          break;
      case 5:
          month_name = "May";
          break;
      case 6:
          month_name = "June";
          break;
      case 7:
          month_name = "July";
          break;
      case 8:
          month_name = "August";
          break;
      case 9:
          month_name = "September";
          break;
      case 10:
          month_name = "October";
          break;
      case 11:
          month_name = "November";
          break;
      case 12:
          month_name = "December";
          break;
      default:
          month_name = "Month out of range";
  }

  std::ostringstream oss;

  // Print month name, day, and year into the stringstream
  oss << month_name << " " << day << ", " << year;

  // Return the string from stringstream
  return oss.str();

}

string Date::get_og_date() {
  return original_date_string;
}
