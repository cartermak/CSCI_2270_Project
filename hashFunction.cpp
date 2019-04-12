/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
*/

#include "project.hpp"

using namespace std;

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