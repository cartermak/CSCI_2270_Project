#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// sorted chronologically per part per machine
struct Replacement {
    tm date;
    Replacement* next;
    string mechanic;
};
// for ordering tracking
struct Request {
    tm date;
    string mechanic;
    bool isOrded;
    bool isFulfilled;
    Request* next;
};
// part inventory
struct Part {
    int partNum;
    int count;
    string name;
    string description;
    Request* head;
};
// machine tracking
struct MachinePart {
    MachinePart* next;
    tm date;
    int count;
    int partNum;
    Replacement* head;
};

int main() {
    MachinePart temp;
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    cout << ctime(&end_time);
    temp.date = *localtime(&end_time);
    end_time = mktime(&temp.date);
    cout << ctime(&end_time);
    return 0;
}