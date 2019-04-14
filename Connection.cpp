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
    // EVERYTHING IS A VECTOR!!! As long as we never type "new", we gucci.
}

/*
deprecated/integrated into searchPart
Part *Connection::findPart(int partNumber)
{
    Part v;
    v.partNum = partNumber;
    int index = hashFunction(partNumber);
    vector<Part>::iterator it;
    it = find(partsTable[index]->inventory.begin(), partsTable[index]->inventory.end(), v);
    int i = std::distance(partsTable[index]->inventory.begin(), it);
    Part *p = &partsTable[index]->inventory.at(i);
    return p;
}
*/

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

    // Code from different implementation:
    // if (!partsTable[index])
    //     return NULL;
    // Part *temp = partsTable[index];
    // if (temp->partNum != partNumber)
    // {
    //     Part v;
    //     v.partNum = partNumber;
    //     int index = hashFunction(partNumber);
    //     vector<Part>::iterator it;
    //     it = find(partsTable[index]->inventory.begin(), partsTable[index]->inventory.end(), v);
    //     int i = std::distance(partsTable[index]->inventory.begin(), it);
    //     temp = &partsTable[index]->inventory.at(i);
    // }
    // return temp;
}

bool Connection::addPart(int partNumber, int count, string name, string description)
{
    Part *tmp = searchPart(partNumber);

    if (tmp)
    {
        cout << "Part already in inventory, incrementing count" << endl;
        tmp->count += count; // Iterate part count by the number of parts the user tried to add
        return false;
    }
    else
    {
        Part p(partNumber, count, name, description);
        int index = hashFunction(partNumber);
        partsTable[index].push_back(p);

        // cout << "Connection::addPart -- the size of the vector at index " << index << " is " << partsTable[index].size() << endl;
        // cout << "Connection::addPart -- the name of the first part is: " << partsTable[index][0].name << endl;
        return true;
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
        curr->name = name;
    }
    if (description != "")
    {
        curr->description = description;
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

    return sum;
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
bool Connection::orderPart(Part *curr, int count, string mechanic, string notes)
{
    time_t currentTime = getCurrentTime();
    Request newRequest(currentTime, 0, 0, mechanic, notes, count); // Create new struct
    curr->requests.push_back(newRequest);                               // Add request to list
    return true;
}

//----------------------------------------------------------------------------------------------------
// Temporary main
/*
int main()
{
    Connection c;
    c.addPart(1, 1, "test", "this is a thing");
    cout << "Part added" << endl;
    cout << "Search Part" << endl;
    Part *v = c.searchPart(1);
    cout << v->name << " " << v->description << endl;
    time_t time = getCurrentTime();
    cout << ctime(&time);
    cout << endl
         << endl;
    time_t t = getCurrentTime();
    time_t o = 1000000;
    time_t result = t - o;
    cout << ctime(&result);
    return 0;
}
*/