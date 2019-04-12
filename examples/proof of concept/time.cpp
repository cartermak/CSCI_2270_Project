#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include "project.hpp"
using namespace std;

int main()
{
    MachinePart temp;
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    cout << ctime(&end_time);
    // temp.date = *localtime(&end_time);
    // end_time = mktime(&temp.date);
    cout << ctime(&end_time);
    return 0;
}