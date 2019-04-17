#include "project.hpp"

using namespace std;
bool IsPathExist(const std::string &s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}
/*
Instantiates class
Input:
    savDir: string, directory containing save files. Must end in "/" or "/", depending on operating system
*/
SaveMethod::SaveMethod(string savDir)
{
    this->savDir = savDir; // load save directory

    // Load the save log into memory
    log = SaveLog(savDir);
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
    // cout << "We got here" << endl;
    // Get string for the save time
    stringstream s;
    s << currentTime;
    string timeStr = s.str();

    string filename = "savefile_" + timeStr; // filename string
    currentSave.filename.setStr(filename);   // Write the save file name to the Save struct

    // ---Save the actual class---
    // cout << "Maybe here" << endl;
    ofstream o(savDir + filename, ios::binary);
    o.write((char *)&A, sizeof(A));
    currentSave.size = o.tellp();
    o.close();
    cout << "HERE?" << endl;
    log.addSave(currentSave); // Log the new save
    cout << "HERE" << endl;
    updateSaveLog();
}

/*
Loads a class object
*/
Connection SaveMethod::load(int savNum)
{
    cout << "We are here" << endl;
    string filename = log.loadSave(savNum);
    cout << filename << endl;
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
    cout << savDir + "saveLog/" << endl;
    if (!IsPathExist(savDir + "saveLog/"))
    {
        cout << "IT WORKED" << endl;
    }
    ifstream ingest(savDir + "saveLog/", ios::binary);
    if (!ingest.is_open())
        cout << "ERROR" << endl;
    ingest.read((char *)this, sizeof(SaveLog));
    ingest.close();
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

    while ((logSize > MAX_LOG_SIZE || (long int)getCurrentTime - saves[0].savTime > MAX_FILE_AGE) && saves.size() > 1)
    {
        logSize -= saves[0].size;                              // Decrement the total log size
        string fullfile = savDir + saves[0].filename.getStr(); // Full file path + name
        remove((char *)&fullfile);                             // Delete the file
        saves.erase(saves.begin());                            // Remove the save struct from the directory
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
    cout << "NOT EMPTY" << endl;
    cout << saves.size() - savNum << endl;
    cout << saves.size() << endl;
    try
    {
        saves[saves.size() - savNum].filename;
    }
    catch (exception const &e)
    {
        cout << e.what() << endl;
    }
    return saves[saves.size() - savNum].filename.getStr(); // Return the requested filename
}

void SaveLog::addSave(Save A)
{
    logSize += A.size;

    // cleanLog();
    cout << "HERE" << endl;
    saves.push_back(A);

    cleanLog();
}

void SaveLog::printSaveHistory()
{
    int counter = 1;

    cout << "------Current Save Log------" << endl;

    for (vector<Save>::iterator i = saves.end() - 1; i >= saves.begin(); i--)
    {
        cout << counter++ << ". Saved " << ctime(&i->savTime);
    }

    cout << "----------------------------" << endl;
}