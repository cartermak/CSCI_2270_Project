#include "project.hpp"

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
  if(!str.size()){
    throw invalid_argument("Null string");
  }
  string outstr;
  cout << "We got to the string" << endl;
  cout << str.size() << endl;
  for (vector<char>::iterator i = str.begin(); i != str.end(); i++)
  {
    outstr.push_back(*i);
    cout << *i << endl;
  }
  return outstr;
}