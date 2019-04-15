#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class strmod
{
public:
  strmod()
  {
  }
  strmod(string instr)
  {
    for (char &c : instr)
    {
      str.push_back(c);
    }
  }
  ~strmod()
  {
  }
  void setStr(string instr)
  {
    str.clear();
    for (char &c : instr)
    {
      str.push_back(c);
    }
  }
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