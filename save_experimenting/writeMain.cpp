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
    testStruct A;

    A.key = 123;
    A.name = "test name one";
    A.testVec.push_back(1);
    A.testVec.push_back(2);
    A.testVec.push_back(3);
    A.testVec.push_back(4);
    A.testVec.push_back(5);

    printStruct(A);

    testStruct B;

    B.key = 321;
    B.name = "test name two";
    B.testVec.push_back(2);
    B.testVec.push_back(2);
    B.testVec.push_back(3);
    B.testVec.push_back(4);
    B.testVec.push_back(5);

    printStruct(B);

    testClass AA;
    AA.addStruct(A);
    AA.addStruct(B);

    string filename = "test";

    ofstream outStream;

    outStream.open(filename, ios::binary);
    outStream.write((char *)&AA, sizeof(AA));
    outStream.close();

    return 0;
}
