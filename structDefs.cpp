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
using namespace std;

const int NUM_OF_MACHINES = 10; // This might not be the right way to do this...should definitely go in our header file.

// part inventory
struct Part
{
    int partNum;                            // Part number
    int count;                              // Count of part in inventory
    string name;                            // Part name
    string description;                     // Description of part
    Request *head;                          // Head to linked list of requests
    Part *next;                             // Next field for chaining collisions
    MachinePart *machines[NUM_OF_MACHINES]; // Array of MachinePart pointers to hold this part on each machine
};
// machine tracking
struct MachinePart
{
    int count;
    int partNum;
    string notes;
    Replacement *head;
};
// sorted chronologically per part per machine
struct Replacement
{
    tm date;
    string mechanic;
    string notes;
    Replacement *next;
};
// for ordering tracking
struct Request
{
    tm date;
    string mechanic;
    string notes;
    bool isOrded;
    bool isFulfilled;
    Request *next;
};

int main()
{
    return 0;
}