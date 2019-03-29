#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// part inventory
struct Part {
    int partNum;
    int count;
    string name;
    string description;
    Request * head;
};
// machine tracking
struct MachinePart {
    MachinePart* next;
    tm date;
    int count;
    int partNum;
    Replacement *head;
};
// sorted chronologically per part per machine
struct Replacement {
    tm date;
    Replacement* next;
    string mechanic;
};
// for ordering tracking
struct Request{
    tm date;
    string mechanic;
    bool isOrded;
    bool isFulfilled;
    Request* next;

};

int main() {
    MachinePart temp;
    temp.date.tm_zone = "GMT";
    return 0;
}