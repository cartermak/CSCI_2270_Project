/*
Carter Mak and William Walker
CSCI 2270 Data Structures
Instructor: Ashutosh Trivedi
TA: Divya Athoopalil
*/

#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <sys/stat.h>
// #include <jni.h>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

time_t getCurrentTime();

class strmod
{
public:
  strmod();
  strmod(string instr);
  ~strmod();
  void setStr(string instr);
  void apdStr(string apdstr);
  string getStr();

private:
  vector<char> str;
};

// 8=============================================================================D

struct Replacement
{
  int numOff;      // Number of parts removed
  int numOn;       // Number of parts installed
  time_t date;     // Date of replacement
  strmod mechanic; // Mechanic who replaced it
  strmod notes;    // Notes on replacement (e.g. "This screw was so fucked when I pulled it out, idk how nobody was killed by a bowling pin")

  Replacement() : numOff(0), numOn(0), date(0), mechanic(""), notes("") {}
  Replacement(int numOff, int numOn, time_t currTime, string mechanic, string notes) : numOff(numOff), numOn(numOn), date(currTime), mechanic(mechanic), notes(notes) {}
};

// machine parts (stored in array for each part in hash table)
struct MachinePart
{
  int count;                             // Number of this part on this machine
  int partNum;                           // Part number (may or may not use this)
  strmod notes;                          // Notes field for the part (e.g. "This screw has screwed me so many times")
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
  strmod mechanic;      // Mechanic who placed the order
  strmod notes;         // Notes about the order (e.g. hurry it the fuck up)
  int count;            // Number of parts to order
  int priority;         //priority of order
  int partNumber;       //partNum of that part
  Request() : dateRequested(0), dateOrdered(0), dateFulfilled(0), mechanic(""), notes(""), count(0), priority(0), partNumber(0)
  {
  }
  Request(time_t dateRequested, time_t dateOrdered, time_t dateFulfilled, string mechanic, string notes, int count, int priority, int partNum) : dateRequested(dateRequested), dateOrdered(dateOrdered), dateFulfilled(dateFulfilled), mechanic(mechanic), notes(notes), count(count), priority(priority), partNumber(partNum) {}
};

// part inventory
const int NUM_OF_MACHINES = 10;
const int PART_NAME_SIZE = 50;
struct Part
{
  int partNum;                           // Part number
  int count;                             // Count of part in inventory
  strmod name;                           // Part name
  strmod description;                    // Description of part
  std::vector<Request> requests;         // Vector of order requests
  MachinePart machines[NUM_OF_MACHINES]; // Array of MachineParts for each machine
  Part() : partNum(0), count(0), name(""), description("") {}
  Part(int partNumber, int count, string name, string description) : partNum(partNumber), count(count), name(name), description(description) {}
};

// 8=============================================================================D

struct wordNode
{
  string word;
  vector<Part *> parts;
  wordNode *left;
  wordNode *right;
};

class wordSearch
{
public:
  wordSearch();
  ~wordSearch();
  Part *searchPart(string words, vector<Part *> &commonParts);
  void addPart(Part *part);
  void printTree();

private:
  wordNode *addNodeHelper(wordNode *currNode, string word, Part *part);
  wordNode *createNode(string word, Part *part);
  void addNode(string word, Part *part);
  void destructorHelper(wordNode *curr);
  wordNode *searchWordHelper(wordNode *currNode, string word);
  void findCommonPtrs(vector<Part *> &a, vector<Part *> &b);
  wordNode *root;
  void printTreeHelper(wordNode *currNode);
};

// 8=============================================================================D

const int HASH_TABLE_SIZE = 100; // Number of elements in the hash table
class Compare
{
public:
  bool operator()(Request one, Request two)
  {
    return one.priority > two.priority;
  }
};
// Class for the main stuff
class Connection
{
public:
  Connection();  // Constructor
  ~Connection(); // Desctructor

  // Return boolean true if part is successfully added, otherwise false (e.g. part already exists)
  Part *addPart(int partNumber, int count, string name, string description);

  //finds pointer to part in inventory
  Part *searchPart(int partNumber);

  // same as searchPart, but uses some neat vector stuff
  Part *findPart(int partNumber);

  // Allows easy editing of part fields
  bool editPart(Part *curr, int count, string name, string description);

  /*
  Function to return a vector of all replacements for a part on a given machine.
    Pass EITHER a part number or a part pointer. If both are passed, the pointer will be used.
    Machine numbers are 1-10 (as opposed to 0-9).
  */
  void getReplacements(Part* curr, int partNum, int machineNum, vector<Replacement*> &outVec);

  // Add a replacement for a part
  bool addReplacement(int machineNum, int partNum, int numOff, int numOn, string mechanic, string notes);

  // Place an order for a part
  bool orderPart(Part *curr, int count, string mechanic, string notes, int priority);

  void printRequestQueue();
  void printRequest(Request r);
  // Fields to store general info
  time_t timeOpened; // Field to store when the struct was instantiated

private:
  vector<Part> partsTable[HASH_TABLE_SIZE]; // Statically allocated hash table
  priority_queue<Request, vector<Request>, Compare> pq;
  int hashFunction(int key);
};

// 8=============================================================================D

const int MAX_LOG_SIZE = 1e9;      // 1e9 characters...if a character is a byte, then like...1GB?
const time_t MAX_FILE_AGE = 2.6e6; // roughly one month of seconds

struct Save
{
  time_t savTime;  // Time the file was saved
  strmod filename; // Name of the saved file
  int size;        // Save file size
};

class SaveLog
{
public:
  SaveLog();
  SaveLog(string savDir);
  ~SaveLog();
  void printSaveHistory();
  void addSave(Save A);
  string loadSave(int savNum);
  void setDir(string savDir);

private:
  strmod savDir;      // Directory to store saved files
  int logSize;        // I know this sounds like the size of a shit, but it's actually the size of all the logs.
  vector<Save> saves; // Vector of all saves, in chronological order

  void cleanLog();
};

class SaveMethod
{
public:
  SaveMethod(string savDir);
  ~SaveMethod();
  void save(Connection A);
  Connection load(int savNum);
  void printSaveHistory();

private:
  string savDir;
  const string saveLogFile = "saveLog"; // Filename saving the saveLog class object to store save history
  SaveLog log;                          // SaveLog class instance to log saves

  void updateSaveLog();
  void cleanSaveLog();
};
