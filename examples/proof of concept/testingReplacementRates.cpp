#include "project.hpp"
using namespace std::chrono;
using secs = chrono::duration<int, std::ratio<1, 1>>;
using days = chrono::duration<int, std::ratio<86400>>;
int main()
{
    auto start = std::chrono::system_clock::now();
    system_clock::time_point t;
    cout << chrono::duration_cast<days>(t.time_since_epoch()).count();
    return 0;
}