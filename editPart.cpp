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
This function is used to edit the count, name, and/or description of a part.

It s always called with all four arguments. It edits only the fields whose input argument values differ from:
int count          = -1;
string name        = "";
string description = "";
*/

void Connection::editPart(int partNum, int count, string name, string description)
{
    int index = hashFunction(partNum);
    
    if(count != -1)
    {
        // Edit count
    }
    if(name!="")
    {
        // Edit name
    }
    if(description!="")
    {
        // Edit description
    }
    return;
}