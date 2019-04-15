#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

struct testStruct
{
    int key;
    string name;
    vector<int> testVec;
};

class testClass
{
  public:
    testClass()
    {
        quantity = 0;
    }
    ~testClass()
    {
    }

    void addStruct(testStruct A)
    {
        if (quantity < 3)
        {
            structs[quantity++] = A;
        }
        else
        {
            cout << "error array full\n";
        }
    }

    testStruct getStruct(int ind)
    {
        return structs[ind];
    }

  private:
    testStruct structs[3];
    int quantity;
};

void printStruct(testStruct curr)
{
    cout << "--------------------------" << endl;

    cout << "Key: " << curr.key << endl;
    cout << "Name: " << curr.name << endl;

    for (vector<int>::iterator i = curr.testVec.begin(); i < curr.testVec.end(); i++)
    {
        cout << "   Vector element: " << *i << endl;
    }

    cout << "--------------------------" << endl;
}

int main()
{
    string filename = "test";

    testClass BB;

    ifstream inStream;
    inStream.open(filename, ios::binary);
    inStream.read((char *)&BB, sizeof(BB));
    inStream.close();

    cout << "test" << endl;

    printStruct(BB.getStruct(0));
    printStruct(BB.getStruct(1));

    return 0;
}
