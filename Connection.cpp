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
}