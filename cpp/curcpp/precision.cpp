#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double value = 32.14159265358979323846;
    cout  << setprecision(2) << value << endl;  // 32
    cout  << setprecision(3) << value << endl;  // 32.1
    cout  << fixed << setprecision(2) << value << endl;  // 32.14
    cout<<value<<std::endl;
    return 0;
}
