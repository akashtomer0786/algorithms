#include <iostream>
#include <string>
#include <set>
using namespace std;
 
struct lexical_compare {
	bool operator() (int a, int b) const {
		return to_string(a) < to_string(b);
	}
};
 
int main() {
    set<int, lexical_compare> s;
 
    s.insert(1);
    s.insert(10);
    s.insert(11);
    s.insert(100);
 
    for (int x : s)
        cout << x << ' ';
 
    return 0;
}
