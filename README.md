# EE355-Project
members: Elliott Meeks (emeeks@usc.edu), Jason Skender (jskender@usc.edu), and Victor Gutierrez (vagutier@usc.edu)
Note: You may receive a warning when running the makefile regarding some destructors for Email and Phone objects, but this has not caused any runtime errors for us
# Note: When running, the primary database file to load from is "netDB.txt" This contains 7 users with some premade friendships made to demonstrate loading friendships when the program closes. 
For Pt5 of Phase 2:
The output format of database files has been modified to account for friendships being saved when the program closes. An additional line after the phone number contains the unique IDs of other network members. These IDs are separated by commas to indicate different users. If this line is blank, then that user has no current friendships. When a user is deleted while having friendships with other users, the other users are *NOT* updated, so illegible data may be stored in database files if this occurs. To see the "pretty" prints of a user's friends, a new friendship must be made by using option 6 in the menu. After adding a new friend, the first user's old and new friendships will be displayed in the "pretty" format.

# Network Management System
---
## README: C++ Project File Structure

### `Contact.cpp`
- **Purpose**: Defines the `Email` and `Phone` classes for handling contact information.
- **Key Components**:
  - `Email` class with methods to set and retrieve email addresses in various formats.
  - `Phone` class with methods to manage phone numbers, including hyphen removal and addition.

### `Date.cpp`
- **Purpose**: Implements the `Date` class to handle date information.
- **Key Components**:
  - `Date` class constructor that parses a date string and stores day, month, and year.
  - Methods to print and retrieve date information in different formats.

### `Misc.cpp`
- **Purpose**: Contains miscellaneous functions like printing banners and generating code names.
- **Key Components**:
  - `printMe` function to display a banner.
  - `codeName` function to create a lowercase, space-free string from two input strings.

### `Network.cpp`
- **Purpose**: Defines the `Network` class for managing a network of `Person` objects.
- **Key Components**:
  - Methods for loading and saving the network database.
  - Functions to add, remove, and search for `Person` objects within the network.

### `Person.cpp`
- **Purpose**: Defines the `Person` class with attributes and methods for individual person records.
- **Key Components**:
  - Constructors for creating `Person` objects from user input or file data.
  - Methods for setting person information, making friends, and printing person details.

### `Test_Network.cpp`
- **Purpose**: Contains the `main` function to run the network application.
- **Key Components**:
  - Instantiation of a `Network` object.
  - Invocation of the `showMenu` method to interact with the user.

### `Test_Person_Eq.cpp`
- **Purpose**: A test file to demonstrate the equality and inequality operators for `Person` objects.
- **Key Components**:
  - Creation of `Person` objects and comparison.

---

These `.cpp` files form a contact management system, enabling the creation, handling, and storage of personal contacts and network relationships.
