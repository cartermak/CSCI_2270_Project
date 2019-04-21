#include "strmod.hpp"

using namespace std;

struct testStruct
{
  strmod testStr;
  int testInt;
};

class testClass
{
public:
  testClass()
  {
  }
  ~testClass()
  {
  }
  void addElement(int num, string str)
  {
    testStruct A;
    A.testInt = num;
    A.testStr.setStr(str);

    thestructs.push_back(A);
  }
  void printVector()
  {
    int counter = 0;

    cout << "The vector is: " << endl;

    for (vector<testStruct>::iterator i = thestructs.begin(); i < thestructs.end(); i++)
    {
      cout << "    Struct element " << counter++ << ": " << i->testStr.getStr() << " with int " << i->testInt << endl;
    }
  }

private:
  vector<testStruct> thestructs;
};

int main()
{
  testClass A;

  A.addElement(1, "asdf");
  A.addElement(2, "sdfg");
  A.addElement(3, "dfgh");
  A.addElement(4, "wer");
  A.addElement(5, "sdvsdf");

  A.printVector();

  string saveFile = "testSave";

  ofstream o(saveFile, ios::binary);
  o.write((char *)&A, sizeof(A));
  o.close();

  testClass B;

  B.printVector();

  ifstream i(saveFile, ios::binary);
  i.read((char *)&B, sizeof(B));
  i.close();

  B.printVector();

  return 0;
}