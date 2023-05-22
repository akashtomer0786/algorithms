#include <iostream>
#include <map>
#include <queue>
using namespace std;
// Custom comparator to sort integers in descending order
struct GreaterComparator {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

struct check {
    bool operator()(const map<int, int>& a, const map<int, int>& b) const {
        return a.size() > b.size();
    }
};

int main() {
    map<int, map<int, int, GreaterComparator>> myMap;
    priority_queue<int, vector<int>, GreaterComparator>pq;
    

    // Inserting values into the map
    myMap[1][1] = 10;
    myMap[1][2] = 20;
    myMap[2][1] = 30;
    myMap[2][2] = 40;

    // Accessing and printing the values
    for (const auto& outerPair : myMap) {
        for (const auto& innerPair : outerPair.second) {
            cout << "Outer Key: " << outerPair.first << " | Inner Key: " << innerPair.first << " | Value: " << innerPair.second << endl;
        }
    }

    return 0;
}
