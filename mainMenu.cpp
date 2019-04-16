#include "project.hpp"

using namespace std;

void printMainMenu();
void addPartHelper(Connection &classObj, int partNum);
void printPartData(Part* curr);

int main()
{
    // Instantiate class object
    Connection A;

    // Instantiate a class object for file saving
    SaveMethod saver("saveFiles/");

    // Declare various things
    string switc; // Damnit, Will
    string temp, fileName, mechanic, notes;
    int partNum,count;
    Part* curr;


    while (true)
    {
        printMainMenu();

        getline(cin, switc);
        switch (stoi(switc))
        {
        case 1:
            cout << "Enter Part Number: ";
            getline(cin, temp);                 // User input for part #
            partNum = stoi(temp);           // Part number
            curr = A.searchPart(partNum); // Load a pointer to the part

            if (curr)
            {
                cout << "Number of '" << curr->name.getStr() << "' in inventory: " << curr->count << endl; // print part name and quantity
                cout << "   Place an order for this part? (y/n): ";
                getline(cin, temp);
                if (temp != "y")
                {
                    break;
                }
            }
            else
            {
                cout << "This part isn't currently in the inventory.\n   Add it to the inventory now? (y/n): ";
                getline(cin, temp);
                if (temp == "y")
                {
                    addPartHelper(A, partNum);
                    curr = A.searchPart(partNum);

                    cout << "Part successfully added!\n   Place an order for this part? (y/n): ";
                    getline(cin, temp);
                    if (temp != "y")
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            cout << "   Enter number to be ordered: ";
            getline(cin, temp);
            count = stoi(temp);

            cout << "   Enter your name: ";
            getline(cin, mechanic);

            cout << "   Enter any notes: ";
            getline(cin, notes);

            if (A.orderPart(curr, count, mechanic, notes))
            {
                cout << "Part ordered!" << endl;
            }
            else
            {
                cout << "Error: part could not be ordered." << endl;
            }

            break;
        case 2:
            cout << "Add a part\n   Enter Part Number: ";
            getline(cin,temp);
            partNum = stoi(temp);
            // search for number in inventory
            curr = A.searchPart(partNum);

            if(curr)
            {
                cout << "Part already exists." << endl;
                break;
            }

            addPartHelper(A,partNum);

            cout << "Part successfully added!" << endl;

            break;
        case 3:
            cout << "Show a part in the inventory\n   Enter Part Number: ";
            getline(cin,temp);
            partNum = stoi(temp);

            curr = A.searchPart(partNum);

            if(curr)
            {
                printPartData(curr);
            }
            else
            {
                cout << "Error: part cannot be found in the inventory." << endl;
            }
            

            // Shows Part data
            // Give option to edit data. If yes, call editPart
            break;
        case 4:
            cout << "Enter Machine #" << endl;
            cout << "Enter Part number to replace" << endl;
            cout << "Enter # of parts to be replaced" << endl;
            break;
        case 5:
            cout << "Enter Machine #" << endl;
            // display parts on machine given
            break;
        case 6:
            cout << "Goodbye!" << endl;
            return 0;
        }
    }

    return 0;
}

void printMainMenu()
{
    cout << "============Main Menu============" << endl;
    cout << "1. Order a part" << endl;
    cout << "2. Add a part to the inventory" << endl;
    cout << "3. Show part in inventory" << endl;
    cout << "4. Replace a Part on a Machine" << endl;
    cout << "5. See active parts" << endl;
    cout << "6. Quit" << endl;
}

/*
Function facilitates adding a new part to the inventory via UI.
    This function assumes the part does not already exist.
    Do not call this function if the part already exists.
    It would probably be fine,...but don't try it.
*/
void addPartHelper(Connection &classObj, int partNum)
{
    string temp;

    cout << "   Enter a part name: ";
    string name;
    getline(cin, name);

    cout << "   Enter a part description: ";
    string description;
    getline(cin, description);

    cout << "   Enter the number currently in inventory: ";
    getline(cin, temp);
    int count = stoi(temp);

    classObj.addPart(partNum, count, name, description);

    return;
}

void printPartData(Part* curr)
{
    cout << "\nPart: " << curr->name.getStr() << endl;
    cout << "   Description: " << curr->description.getStr() << endl;
    cout << "   Number in inventory: " << curr->count << endl;
    
    bool checker = true;

    for(vector<Request>::iterator i = curr->requests.begin();i<curr->requests.end();i++)
    {
        if(!i->dateFulfilled) // If order isn't fulfilled (dateFulfilled is initialized as 0)
        {
            if(checker)
            {
                checker = false;
                cout << "   Open Requests: " << endl;
            }

            cout << endl;
            cout << "      " << i->count << " requested by " << i->mechanic.getStr() << ", " << ctime(&i->dateRequested);
            
            if(i->notes.getStr()!="")
            {
                cout << "      Notes: " << i->notes.getStr() << endl;
            }

            if(i->dateOrdered)
            {
                cout << "      Order placed, " << ctime(&i->dateOrdered);
            }
            else
            {
                cout << "      Order has not been placed." << endl;
            }
            cout << endl;
        }
    }

    if(checker)
    {
        cout << "   This part has no open orders." << endl;
    }
}