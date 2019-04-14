#include "project.hpp"
using namespace std;
using namespace std::chrono;
using secs = chrono::duration<int, std::ratio<1, 1>>;
using days = chrono::duration<int, std::ratio<86400>>;
using hour = chrono::duration<int, std::ratio<3600>>;
int main()
{
    Connection c;
    c.addPart(1, 1, "test", "this is a thing");
    cout << "Part added" << endl;
    cout << "Search Part" << endl;
    Part *v = c.searchPart(1);
    cout << v->name << " " << v->description << endl;

    // time experimentation
    auto start = std::chrono::system_clock::now();
    auto fin = system_clock::now();
    time_t testing = system_clock::to_time_t(fin);
    cout << ctime(&testing) << endl;

    while (true) // loop to test printing out time differences
    {
        string temp;
        getline(cin, temp);
        fin = std::chrono::system_clock::now();
        break;
    }

    duration<double> db = fin - start; // finding duration between start and finish
    time_t f = system_clock::to_time_t(fin);
    cout << ctime(&f) << endl;
    auto day = chrono::duration_cast<days>(db);       // finding total number of days
    auto hour = chrono::duration_cast<hours>(db);     // total number of hours
    auto minute = chrono::duration_cast<minutes>(db); // total number of minutes
    auto second = chrono::duration_cast<seconds>(db); // total number of seconds

    // printing each value subtracting the next highest value
    cout << "Difference is" << day.count() << " days " << hour.count() - 24 * day.count() << " hours " << minute.count() - 60 * hour.count() << " minutes " << second.count() - 60 * minute.count() << " seconds " << endl;
    return 0;
}