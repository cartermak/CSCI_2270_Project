#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    while (true) {
        cout << "============Main Menu============" << endl;
        cout << "1. Order a part" << endl;
        cout << "2. Add a part to the inventory" << endl;
        cout << "3. Show part in inventory" << endl;
        cout << "4. Replace a Part on a Machine" << endl;
        cout << "5. See active parts" << endl;
        cout << "6. Quit" << endl;
        string switc;
        string fileName;

        getline(cin, switc);
        switch (stoi(switc)) {
            case 1:
                cout << "Enter Part #" << endl;
                // show number in inventory
                cout << "Enter number to be ordered" << endl;
                // increment int order in Part
                break;
            case 2:
                cout << "Enter Part #" << endl;
                // search for number in inventory
                // if not in inventory add it to the hash table
                // else increment int number in Part
                break;
            case 3:
                cout << "Enter Part #" << endl;
                // shows Part data
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