# EE355-Project
members: Elliott Meeks (emeeks@usc.edu), Jason Skender (jskender@usc.edu), and Victor Gutierrez (vagutier@usc.edu)
Note: You may receive a warning when running the makefile regarding some destructors for Email and Phone objects, but this has not caused any runtime errors for us
# Note: when running: The primary database file used is "netDB.txt" This contains 7 users with some premade friendships made to demonstrate loading friendships when the program closes. 

For Pt5 of Phase 2:
The output format of database files has been modified to account for friendships being saved when the program closes. An additional line after the phone number contains the unique IDs of other network members. These IDs are separated by commas to indicate different users. If this line is blank, then that user has no current friendships. When a user is deleted while having friendships with other users, the other users are *NOT* updated, so illegible data may be stored in database files if this occurs. To see the "pretty" prints of a user's friends, a new friendship must be made by using option 6 in the menu. After adding a new friend, the first user's old and new friendships will be displayed in the "pretty" format.
