#include "project.hpp"

using namespace std;

/*
Instantiates class
Input:
    savDir: string, directory containing save files. Must end in "/" or "\", depending on operating system
*/
SaveMethod::SaveMethod(string savDir)
{
    this->savDir = savDir; // load save directory

    // Load the save log into memory
    ifstream i(savDir + saveLogFile, ios::binary);
    i.read((char *)&log, sizeof(log));
    i.close();

    log.setDir(savDir);
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

    cout << "The filename in the Save struct is: " << currentSave.filename.getStr() << endl;

    cout << "The size field in the Save struct is: " << currentSave.size << endl;

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
    this->savDir.setStr(savDir);
    logSize = 0;
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
    if (saves.size() > 1000000)
    {
        while (logSize > MAX_LOG_SIZE || (long int)getCurrentTime - saves[0].savTime > MAX_FILE_AGE)
        {
            logSize -= saves[0].size;                                       // Decrement the total log size
            string fullfile = savDir.getStr() + saves[0].filename.getStr(); // Full file path + name
            remove((char *)&fullfile);                                      // Delete the file
            saves.erase(saves.begin());                                     // Remove the save struct from the directory
        }
    }
}

/*
Returns the filename of the desired save file, or an empty string if the save index does not exist
*/
string SaveLog::loadSave(int savNum)
{
    if ((unsigned int)savNum > saves.size()) // If the save number is outside the list of all saves, return an empty string
    {
        return "";
    }

    return saves[saves.size() - savNum].filename.getStr(); // Return the requested filename
}

void SaveLog::addSave(Save A)
{
    logSize += A.size;

    // cleanLog();

    saves.push_back(A);

    // cleanLog();
}

void SaveLog::printSaveHistory()
{
    int counter = 1;

    cout << "------Current Save Log------" << endl;

    cout << "Size of saves: " << saves.size() << endl;

    cout << "The savDir is: " << savDir.getStr() << endl;

    for (vector<Save>::iterator i = saves.begin(); i < saves.end(); i++)
    {
        cout << counter++ << ". Saved " << endl;
    }

    cout << "----------------------------" << endl;
}

void SaveLog::setDir(string strIn)
{
    this->savDir.setStr(strIn);
    return;
}