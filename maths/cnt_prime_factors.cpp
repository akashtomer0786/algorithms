//Project Euler #47: Distinct primes factors
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define int long long 
using namespace std;
vector<int>primefactcnt;
void modified_sieve(int maxnumber) {
    primefactcnt.resize(maxnumber + 1, 0);
    for (int i = 2; i <= maxnumber; i++) {
        if(primefactcnt[i]==0)
        for (int j = 1; i*j <= maxnumber; j++) {
            primefactcnt[i*j]++;
        }
    }
}
int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    n = n + k - 1;
    modified_sieve(n);
    int consecutive = 0;
    for (int i = 2; i <= n; i++) {
        if (primefactcnt[i] == k) {
            consecutive++;
            if (consecutive >= k) {
                cout << i - k + 1 << endl;
                //consecutive = 0;
            }
        }
        else {
            consecutive = 0;
        }
    }
    return 0;
}
