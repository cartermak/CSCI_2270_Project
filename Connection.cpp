/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
*/

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <queue>
#include <vector>
#include <algorithm> //for finding in a vector
#include "project.hpp"

using namespace std;

/*
Constructor and Destructor.
No input arguments.
Might need to add things to the desctructor eventually, but the hash table is statically allocated and the vectors should (?) automagically be destructed.
*/
bool operator==(const Part one, const Part two)
{
    return one.partNum == two.partNum;
}
tm getCurrentTime()
{
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    return *localtime(&end_time);
}
Connection::Connection()
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        partsTable[i] = NULL;
    }
}
Connection::~Connection()
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        delete partsTable[i];
    }
}
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

Part *Connection::searchPart(int partNumber)
{
    int index = hashFunction(partNumber);
    if (!partsTable[index])
        return NULL;
    Part *temp = partsTable[index];

    return temp;
}

bool Connection::addPart(int partNumber, int count, string name, string description)
{
    Part *tmp = searchPart(partNumber);
    // cout << "Part found" << tmp << endl;
    if (tmp)
    {
        cout << "Part already in inventory, incrementing count" << endl;
        tmp->count++;
        return false;
    }
    else
    {
        Part *p = new Part(partNumber, count, name, description);
        int index = hashFunction(partNumber);
        partsTable[index] = p;
        partsTable[index]->inventory.push_back(*p);
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------
// Temporary main
int main()
{
    Connection c;
    c.addPart(1, 1, "test", "this is a thing");
    cout << "Part added" << endl;
    cout << "Search Part" << endl;
    Part *v = c.searchPart(1);
    cout << v->name << " " << v->description << endl;
    cout << "Find Part" << endl;
    v = c.findPart(1);
    cout << v->name << " " << v->description << endl;
    tm t = getCurrentTime();
    time_t time = mktime(&t);
    cout << ctime(&time) << endl;
    return 0;
}