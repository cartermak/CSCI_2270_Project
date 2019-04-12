/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
*/

//for finding in a vector
#include "project.hpp"

using namespace std;
using namespace std::chrono;
using secs = chrono::duration<int, std::ratio<1, 1>>;
using days = chrono::duration<int, std::ratio<86400>>;
using hour = chrono::duration<int, std::ratio<3600>>;
/*
Constructor and Destructor.
No input arguments.
Might need to add things to the desctructor eventually, but the hash table is statically allocated and the vectors should (?) automagically be destructed.
*/
bool operator==(const Part one, const Part two)
{
    return one.partNum == two.partNum;
}
chrono::time_point<chrono::_V2::system_clock, chrono::nanoseconds> getCurrentTime()
{
    auto start = std::chrono::system_clock::now();
    // std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    return start;
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

//deprecated/integrated into searchPart
// Part *Connection::findPart(int partNumber)
// {
//     Part v;
//     v.partNum = partNumber;
//     int index = hashFunction(partNumber);
//     vector<Part>::iterator it;
//     it = find(partsTable[index]->inventory.begin(), partsTable[index]->inventory.end(), v);
//     int i = std::distance(partsTable[index]->inventory.begin(), it);
//     Part *p = &partsTable[index]->inventory.at(i);
//     return p;
// }

Part *Connection::searchPart(int partNumber)
{
    int index = hashFunction(partNumber);
    if (!partsTable[index])
        return NULL;
    Part *temp = partsTable[index];
    if (temp->partNum != partNumber)
    {
        Part v;
        v.partNum = partNumber;
        int index = hashFunction(partNumber);
        vector<Part>::iterator it;
        it = find(partsTable[index]->inventory.begin(), partsTable[index]->inventory.end(), v);
        int i = std::distance(partsTable[index]->inventory.begin(), it);
        temp = &partsTable[index]->inventory.at(i);
    }
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
        if (partsTable[index])
        {
            partsTable[index]->inventory.push_back(*p);
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
    Connection c;
    c.addPart(1, 1, "test", "this is a thing");
    cout << "Part added" << endl;
    cout << "Search Part" << endl;
    Part *v = c.searchPart(1);
    cout << v->name << " " << v->description << endl;

    // time experimentation
    auto start = std::chrono::system_clock::now();
    auto fin = system_clock::now();
    time_t testing = system_clock::to_time_t(fin);
    cout << ctime(&testing) << endl;

    while (true) // loop to test printing out time differences
    {
        string temp;
        getline(cin, temp);
        fin = std::chrono::system_clock::now();
        break;
    }

    duration<double> db = fin - start; // finding duration between start and finish
    time_t f = system_clock::to_time_t(fin);
    cout << ctime(&f) << endl;
    auto day = chrono::duration_cast<days>(db);       // finding total number of days
    auto hour = chrono::duration_cast<hours>(db);     // total number of hours
    auto minute = chrono::duration_cast<minutes>(db); // total number of minutes
    auto second = chrono::duration_cast<seconds>(db); // total number of seconds

    // printing each value subtracting the next highest value
    cout << "Difference is" << day.count() << " days " << hour.count() - 24 * day.count() << " hours " << minute.count() - 60 * hour.count() << " minutes " << second.count() - 60 * minute.count() << " seconds " << endl;
    return 0;
}