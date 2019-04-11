/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
*/

#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>

#include "project.hpp"

using namespace std;

/*
Constructor and Destructor.
No input arguments.
Might need to add things to the desctructor eventually, but the hash table is statically allocated and the vectors should (?) automagically be destructed.
*/

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
        Part *temp = partsTable[i];
        Part *prev = NULL;
        while (temp)
        {
            for (int j = 0; j < NUM_OF_MACHINES; j++)
            {
                delete temp->machines[j];
            }
            prev = temp;
            temp = temp->next;
            delete prev;
            prev = NULL;
        }
    }
}
Part *Connection::searchPart(int partNumber, string name)
{
    int index = hashFunction(partNumber);
    if (!partsTable[index])
        return NULL;
    Part *temp = partsTable[index];
    while (temp)
    {
        if (temp->name == name)
            break;
        temp = temp->next;
    }
    return temp;
}



bool Connection::addPart(int partNumber, int count, string name, string description)
{
    Part *tmp = searchPart(partNumber, name);
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
        if (partsTable[index])
        {
            Part *temp = partsTable[index];
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = p;
        }
        else
        {
            partsTable[index] = p;
        }
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------
// Temporary main
int main()
{
    return 0;
}