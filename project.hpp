/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

const int NUM_OF_MACHINES = 10; // This might not be the right way to do this...should definitely go in our header file.
time_t getCurrentTime();
struct Replacement
{
    time_t date;     // Date of replacement
    string mechanic; // Mechanic who replaced it
    string notes;    // Notes on replacement (e.g. "This screw was so fucked when I pulled it out, idk how nobody wasn't killed by a bowling pin")
};
// machine parts (stored in array for each part in hash table)
struct MachinePart
{
    int count;                             // Number of this part on this machine
    int partNum;                           // Part number (may or may not use this)
    string notes;                          // Notes field for the part (e.g. "This screw has screwed me so many times")
    std::vector<Replacement> replacements; // Vector of repacements
    MachinePart() : count(0), partNum(0), notes("") {}
};
// sorted chronologically per part per machine
// for ordering tracking
struct Request
{
    time_t dateRequested; // Date the order was requested by a mechanic
    time_t dateOrdered;   // Date the order was placed (e.g. by Nate)
    time_t dateFulfilled; // Date the order was fulfilled (receieved at the Connection)
    string mechanic;      // Mechanic who placed the order
    string notes;         // Notes about the order (e.g. hurry it the fuck up)
    int count;            // Number of parts to order
    Request() : dateRequested(0), dateOrdered(0), dateFulfilled(0), mechanic(""), notes(""), count(0) {}
    Request(time_t dateRequested, time_t dateOrdered, time_t dateFulfilled, string mechanic, string notes, int count) : dateRequested(dateRequested), dateOrdered(dateOrdered), dateFulfilled(dateFulfilled), mechanic(mechanic), notes(notes), count(count) {}
};
// part inventory
struct Part
{
    int partNum;                           // Part number
    int count;                             // Count of part in inventory
    string name;                           // Part name
    string description;                    // Description of part
    std::vector<Request> requests;         // Vector of order requests
    MachinePart machines[NUM_OF_MACHINES]; //Array of MachineParts for each machine
    Part() : partNum(0), count(0), name(""), description("") {}
    Part(int partNumber, int count, string name, string description) : partNum(partNumber), count(count), name(name), description(description) {}
};

// 8=============================================================================D

const int HASH_TABLE_SIZE = 100; // Number of elements in the hash table

// Class
class Connection
{
  public:
    Connection();  // Constructor
    ~Connection(); // Desctructor

    // Return boolean true if part is successfully added, otherwise false (e.g. part already exists)
    bool addPart(int partNumber, int count, string name, string description);

    //finds pointer to part in inventory
    Part *searchPart(int partNumber);

    // same as searchPart, but uses some neat vector stuff
    Part *findPart(int partNumber);

    // Allows easy editing of part fields
    bool editPart(Part* curr    , int count, string name, string description);

    // Place an order for a part
    bool orderPart(Part* curr, int count, string mechanic, string notes);

    // Fields to store general info
    time_t timeOpened; // Field to store when the struct was instantiated

  private:
    vector<Part> partsTable[HASH_TABLE_SIZE]; // Statically allocated hash table

    int hashFunction(int key);
};