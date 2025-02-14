/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopallil
*/

//header file
#include "project.hpp"

using namespace std;

// Redefine the equality (==) operator to compare the part numbers between parts
bool operator==(const Part one, const Part two)
{
    return one.partNum == two.partNum;
}

// Returns the current time
time_t getCurrentTime()
{
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    return end_time;
}

/*
Constructor and Destructor.
No input arguments.
*/
Connection::Connection()
{
    timeOpened = getCurrentTime();
}
Connection::~Connection()
{
    // EVERYTHING IS A VECTOR!!! As long as we never type "new", no need for a destructor.
}

Part *Connection::searchPart(int partNumber)
{
    int index = hashFunction(partNumber); // hashed index
    int counter = -1;                     // counter to count indices

    // Iterate through Part vector in the hash table element `index`
    for (vector<Part>::iterator i = partsTable[index].begin(); i < partsTable[index].end(); i++)
    {
        counter++;                    // Iterate the counter
        if (partNumber == i->partNum) // If we've found the desired part
        {
            return &partsTable[index][counter]; // Return the address of (pointer to) that part
        }
    }
    return NULL; // If part isn't found, return NULL
}

Part *Connection::addPart(int partNumber, int count, string name, string description)
{
    Part *tmp = searchPart(partNumber);

    if (tmp)
    {
        cout << "Part already in inventory, incrementing count" << endl;
        tmp->count += count; // Iterate part count by the number of parts the user tried to add
        return NULL;
    }
    else
    {
        Part p(partNumber, count, name, description);

        // Enter correct part numbers in machinePart structs
        for (int i = 0; i < NUM_OF_MACHINES; i++)
        {
            p.machines[i].partNum = partNumber;
        }

        int index = hashFunction(partNumber);
        partsTable[index].push_back(p);

        return &(*partsTable[index].rbegin());
    }
}

/*
This function is used to edit the count, name, and/or description of a part.
    It's always called with all four arguments. It edits only the fields whose input argument values differ from:
    int count          = -1;
    string name        = "";
    string description = "";
*/
bool Connection::editPart(Part *curr, int count, string name, string description)
{
    if (!curr) // If the part isn't found, return false
    {
        return false;
    }

    // Edit fields
    if (count != -1)
    {
        curr->count = count;
    }
    if (name != "")
    {
        curr->name.setStr(name);
    }
    if (description != "")
    {
        curr->description.setStr(description);
    }
    return true;
}

/*
Input:
    -key: part number of int type to be hashed.
Output:
    -sum: integer index for the hash table.
*/
int Connection::hashFunction(int key)
{
    int sum = 0;

    while (key != 0)
    {
        sum += key % 10;
        key = key / 10;
    }

    return sum % HASH_TABLE_SIZE;
}

/*
Function will add a Request struct to the appropriate vector for the given part.
Inputs:
    - partNum: part number of part to order
    - count: number to order
    - mechanic: name of mechanic ordering the part
    - notes: field to store any notes about the order
Output:
    Returns a boolean true if the part was successfully ordered.
    Currently no reason for it not to work, but it's there just in case.
*/
bool Connection::orderPart(Part *curr, int count, string mechanic, string notes, int priority)
{
    time_t currentTime = getCurrentTime();
    Request newRequest(currentTime, 0, 0, mechanic, notes, count, priority, curr->partNum); // Create new struct
    curr->requests.push_back(newRequest);                                                   // Add request to list
    q.push_back(&*curr->requests.rbegin());
    return true;
}

void Connection::printRequest(Request *r)
{
    cout << "Request for: ";
    cout << r->count << " of " << r->partNumber << " by " << r->mechanic.getStr();
    cout << " with notes: " << r->notes.getStr() << " is ";
    if (!r->dateOrdered)
        cout << "not ordered ";
    else if (!r->dateFulfilled)
        cout << "ordered but not fulfilled ";
    else
        cout << "fulfilled! ";
    cout << endl;
}

void Connection::printRequestQueue()
{
    for (vector<Request *>::iterator i = q.begin(); i < q.end(); i++)
    {
        printRequest(*i);
    }
}

bool Connection::addReplacement(int machineNum, int partNum, int numOff, int numOn, string mechanic, string notes)
{
    Part *curr = searchPart(partNum);

    if (curr)
    {
        if (machineNum > NUM_OF_MACHINES || machineNum < 1)
        {
            cout << "Error: Machine number out of range" << endl;
        }
        Replacement newRepl(numOff, numOn, getCurrentTime(), mechanic, notes); // Instantiate and populate new replacement struct
        cout << "Current time is: " << ctime(&newRepl.date) << endl;
        curr->machines[machineNum - 1].replacements.push_back(newRepl);        // Add the replacement to the replacement vector for that part

        curr->count -= numOn;

        return true;
    }
    else
    {
        return false;
    }
}

void Connection::getReplacements(Part *curr, int partNum, int machineNum, vector<Replacement *> &outVec)
{
    if (!curr)
    {
        curr = searchPart(partNum);

        if (!curr)
        {
            cout << "Error: Part could not be found" << endl;
            return;
        }
    }

    for (vector<Replacement>::iterator i = curr->machines[machineNum - 1].replacements.begin(); i < curr->machines[machineNum - 1].replacements.end(); i++)
    {
        outVec.push_back(&*i);
    }
}

void Connection::getRequests(vector<Request *> &q)
{
    q.clear();
    q = this->q;
    return;
}

bool Connection::placeOrder(Request *order, string notes)
{
    if (order)
    {
        order->dateOrdered = getCurrentTime();
        order->notes.apdStr(" | Order Notes: " + notes);
        return true;
    }
    else
    {
        return false;
    }
}

bool Connection::fulfillOrder(Request *order, string notes)
{
    if (order && order->dateOrdered)
    {
        order->dateFulfilled = getCurrentTime();
        order->notes.apdStr(" | Fulfillment Notes: " + notes);
        Part *curr = searchPart(order->partNumber);
        curr->count += order->count;
        return true;
    }
    else
    {
        return false;
    }
}

void Connection::getAllParts(vector<Part *> &parts)
{
    parts.clear();

    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        for (vector<Part>::iterator j = partsTable[i].begin(); j < partsTable[i].end(); j++)
        {
            parts.push_back(&*j);
        }
    }
}

void Connection::closeRequest(Request *curr)
{
    q.erase(remove(q.begin(), q.end(), curr), q.end());
}