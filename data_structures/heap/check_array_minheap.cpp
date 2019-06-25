#include<iostream>
using namespace std;
bool check(int a[], int n, int i) {
	if (2*i +1 >= n )
		return true;
	bool x = false;
	bool y = false;
 
	if (2 * i + 1 < n && a[2 * i + 1] >= a[i])
		x = check(a, n, 2 * i + 1);
	if (2 * i + 2 < n && a[2 * i + 2] >= a[i])
		y = check(a, n, 2 * i + 2);
    if(2*i+2==n)
        y=true;
	return x && y;
}
int main() {
	int a[] = { 2,3,5,8,10};
	if (check(a, 6, 0))
		cout << "Yes";
}
