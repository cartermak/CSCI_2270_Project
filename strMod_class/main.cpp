#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class strmod
{
public:
  // Instantiate a strmod
  strmod()
  {
  }
  // Instantiate and intialize strmod as an input string
  strmod(string instr)
  {
    for (char &c : instr)
    {
      str.push_back(c);
    }
  }
  // Destructor. Doesn't need to do...anything.
  ~strmod()
  {
  }
  // Setter
  void setStr(string instr)
  {
    str.clear();
    for (char &c : instr)
    {
      str.push_back(c);
    }
  }
  // Append to the string
  void apdStr(string apdstr)
  {
    for (char &c : apdstr)
    {
      str.push_back(c);
    }
  }
  // Getter
  string getStr()
  {
    string outstr;
    for (vector<char>::iterator i = str.begin(); i < str.end(); i++)
    {
      outstr.push_back(*i);
    }
    return outstr;
  }

private:
  vector<char> str;
};

int main()
{
  strmod x("asdf motherfucker");

  string outstr = x.getStr();

  cout << outstr << endl;

  x.setStr("fdsa mafusa fucka");

  outstr = x.getStr();

  cout << outstr << endl;

  return 0;
}