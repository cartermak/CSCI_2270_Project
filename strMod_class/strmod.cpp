#include "strmod.hpp"

using namespace std;

// Instantiate a strmod
strmod::strmod()
{
}
// Instantiate and intialize strmod as an input string
strmod::strmod(string instr)
{
  for (char &c : instr)
  {
    str.push_back(c);
  }
}
// Destructor. Doesn't need to do...anything.
strmod::~strmod()
{
}
// Setter
void strmod::setStr(string instr)
{
  str.clear();
  for (char &c : instr)
  {
    str.push_back(c);
  }
}
// Append to the string
void strmod::apdStr(string apdstr)
{
  for (char &c : apdstr)
  {
    str.push_back(c);
  }
}
// Getter
string strmod::getStr()
{
  string outstr;
  for (vector<char>::iterator i = str.begin(); i < str.end(); i++)
  {
    outstr.push_back(*i);
  }
  return outstr;
}