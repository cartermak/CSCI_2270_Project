#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class strmod
{
public:
  strmod();
  strmod(string instr);
  ~strmod();
  void setStr(string instr);
  void apdStr(string apdstr);
  string getStr();

private:
  vector<char> str;
};