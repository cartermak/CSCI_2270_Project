#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
#include <chrono>
#include <sstream>
#include <algorithm>

#include "strmod.hpp"
#include "project.hpp"

using namespace std;

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

  private:
    string savDir;      // Directory to store saved files
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

/*
Instantiates class
Input:
    savDir: string, directory containing save files. Must end in "/" or "/", depending on operating system
*/
SaveMethod::SaveMethod(string savDir)
{
    this->savDir = savDir; // load save directory

    // Load the save log into memory
    ifstream i(savDir + saveLogFile, ios::binary);
    i.read((char *)&log, sizeof(log));
    i.close();
}

SaveMethod::~SaveMethod()
{
    updateSaveLog();
}

void SaveMethod::updateSaveLog()
{
    ofstream o(savDir + saveLogFile, ios::binary);
    o.write((char *)&log, sizeof(log));
    o.close();
}

/*
Save the class object A
Input:
    Connection A: an instantiated class object of type Connection.
    The file will be saved and the save recorded in the save log
*/
void SaveMethod::save(Connection A)
{
    // ---Save log---
    time_t currentTime = getCurrentTime(); // Get the current time
    Save currentSave;                      // Instantiate a Save struct
    currentSave.savTime = currentTime;     // Write the current time to the new Save struct

    // Get string for the save time
    stringstream s;
    s << currentTime;
    string timeStr = s.str();

    string filename = "savefile_" + timeStr; // filename string
    currentSave.filename.setStr(filename);   // Write the save file name to the Save struct

    // ---Save the actual class---

    ofstream o(savDir + filename, ios::binary);
    o.write((char *)&A, sizeof(A));
    currentSave.size = o.tellp();
    o.close();

    log.addSave(currentSave); // Log the new save

    updateSaveLog();
}

/*
Loads a class object
*/
Connection SaveMethod::load(int savNum)
{
    string filename = log.loadSave(savNum);

    if (filename.empty())
    {
        cerr << "Error: File could not be found in directory " << savDir << endl;
    }

    Connection A;

    ifstream i(savDir + filename, ios::binary);
    i.read((char *)&A, sizeof(A));
    i.close();

    return A;
}

/*
Calls the printSaveHistory() function of the current save log
*/
void SaveMethod::printSaveHistory()
{
    log.printSaveHistory();
}

SaveLog::SaveLog()
{
}
SaveLog::SaveLog(string savDir)
{
    this->savDir = savDir;
}

SaveLog::~SaveLog()
{
}

/* Clear out old save files
    Conditions:
    1. The size of the log is too great, or
    2. The oldest log is older than the set time
    *and*
    There is more than one save file
*/
void SaveLog::cleanLog()
{
    
    while ((logSize > MAX_LOG_SIZE || (int)(getCurrentTime - saves[0].savTime) > MAX_FILE_AGE) && saves.size() > 1)
    {
        logSize -= saves[0].size;                               // Decrement the total log size
        remove((char *)&(savDir + saves[0].filename.getStr())); // Delete the file
        saves.erase(saves.begin());                             // Remove the save struct from the directory
    }
}

/*
Returns the filename of the desired save file, or an empty string if the save index does not exist
*/
string SaveLog::loadSave(int savNum)
{
    if (savNum > saves.size()) // If the save number is outside the list of all saves, return an empty string
    {
        return "";
    }

    return saves[saves.size() - savNum].filename.getStr(); // Return the requested filename
}

void SaveLog::addSave(Save A)
{
    logSize += A.size;

    cleanLog();

    saves.push_back(A);

    cleanLog();
}

void SaveLog::printSaveHistory()
{
    int counter = 1;

    cout << "------Current Save Log------" << endl;

    for (vector<Save>::iterator i = saves.end()-1; i>=saves.begin();i--)
    {
        cout << counter++ << ". Saved " << ctime(&i->savTime);
    }

    cout << "----------------------------" << endl;
}