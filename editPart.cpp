/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
*/

#include "project.hpp"

using namespace std;

/*
This function is used to edit the count, name, and/or description of a part.

It s always called with all four arguments. It edits only the fields whose input argument values differ from:
int count          = -1;
string name        = "";
string description = "";
*/

bool Connection::editPart(int partNum, int count, string name, string description)
{
    Part* curr = findPart(partNum);

    if(curr==NULL)
    {
        return false;
    }
    
    int index = hashFunction(partNum);
    
    if(count != -1)
    {
        curr->count = count;
    }
    if(name!="")
    {
        curr->name = name;
    }
    if(description!="")
    {
        curr->description = description;
    }
    return true;
}