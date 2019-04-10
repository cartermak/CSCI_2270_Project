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

#include <ctime>
#include <iostream>
#include <string>
using namespace std;

const int NUM_OF_MACHINES =
    10;  // This might not be the right way to do this...should definitely go in
         // our header file.

// part inventory
struct Part {
    int partNum;
    int count;
    string name;
    string description;
    Request *head;
    Part *next;
    MachinePart *machines[NUM_OF_MACHINES];
};
// machine tracking
struct MachinePart {
    int count;
    int partNum;
    string notes;
    Replacement *head;
};
// sorted chronologically per part per machine
struct Replacement {
    tm date;
    Replacement *next;
    string mechanic;
    string notes;
};
// for ordering tracking
struct Request {
    tm date;
    string mechanic;
    string notes;
    bool isOrded;
    bool isFulfilled;
    Request *next;
};

int main() { return 0; }