# EE355-Project
members: Elliott Meeks (emeeks@usc.edu), Jason Skender (jskender@usc.edu), and Victor Gutierrez (vagutier@usc.edu)
Note: You may receive a warning when running the makefile regarding some destructors for Email and Phone objects, but this has not caused any runtime errors for us
# Note: When running, the primary database file to load from is "netDB.txt" This contains 7 users with some premade friendships made to demonstrate loading friendships when the program closes. 
For Pt5 of Phase 2:
The output format of database files has been modified to account for friendships being saved when the program closes. An additional line after the phone number contains the unique IDs of other network members. These IDs are separated by commas to indicate different users. If this line is blank, then that user has no current friendships. When a user is deleted while having friendships with other users, the other users are *NOT* updated, so illegible data may be stored in database files if this occurs. To see the "pretty" prints of a user's friends, a new friendship must be made by using option 6 in the menu. After adding a new friend, the first user's old and new friendships will be displayed in the "pretty" format.
# Network Management System

## Overview
This system is designed to manage a network of individuals, allowing for the storage, retrieval, and manipulation of personal information and connections between individuals.
## File Structure
### `contact.cpp`
- Defines the `Email` and `Phone` classes for managing email and phone contact information.
- Methods include setting and getting contact details in various formats, including for database storage.
### `date.cpp`
- Implements the `Date` class to handle date information.
- Provides functionality to print and retrieve date information in different formats.
### `misc.cpp`
- Contains miscellaneous functions such as `printMe` for printing banners and `codeName` for generating code names from strings.
### `network.cpp`
- Defines the `Network` class which manages a list of `Person` objects.
- Includes methods for searching, adding, and removing individuals from the network, as well as loading and saving the network database.
### `person.cpp`
- Describes the `Person` class with attributes for personal details, contacts, and friends.
- Includes methods for setting personal information from user input or a file, making friends, and printing person details.
### `test_network.cpp`
- Contains the main function to run the network management system and display the menu for user interaction.
### `test_person_eq.cpp`
- A test file to demonstrate the equality and inequality operations between `Person` objects.
