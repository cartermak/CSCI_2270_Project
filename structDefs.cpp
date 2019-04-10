/*
----------
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
----------
Last edit:
Carter Mak, April 9
----------
*/

#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;

const int NUM_OF_MACHINES = 10; // This might not be the right way to do this...should definitely go in our header file.

// part inventory
struct Part
{
    int partNum;                            // Part number
    int count;                              // Count of part in inventory
    string name;                            // Part name
    string description;                     // Description of part
    vector<Request> requests;               // Vector of order requests
    MachinePart *machines[NUM_OF_MACHINES]; // Array of MachinePart pointers to hold this part on each machine
};
// machine parts (stored in array for each part in hash table)
struct MachinePart
{
    int count;                        // Number of this part on this machine
    int partNum;                      // Part number (may or may not use this)
    string notes;                     // Notes field for the part (e.g. "This screw has screwed me so many times")
    vector<Replacement> replacements; // Vector of repacements
};
// sorted chronologically per part per machine
struct Replacement
{
    tm date;         // Date of replacement
    string mechanic; // Mechanic who replaced it
    string notes;    // Notes on replacement (e.g. "This screw was so fucked when I pulled it out, idk how nobody wasn't killed by a bowling pin")
};
// for ordering tracking
struct Request
{
    tm dateRequested; // Date the order was requested by a mechanic
    tm dateOrdered;   // Date the order was placed (e.g. by Nate)
    tm dateFulfilled; // Date the order was fulfilled (receieved at the Connection)
    string mechanic;  // Mechanic who placed the order
    string notes;     // Notes about the order (e.g. hurry it the fuck up)
};

int main()
{
    cout << "Skooooooooooooo Buffs\n";
    return 0;
}