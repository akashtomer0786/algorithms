#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
void dectobinary1(int n) {
	vector<int> v;
	while (n) {
		v.push_back(n % 2);
		n = n / 2;
	}
	//reverse(v.begin(),v.end());
	for (int p : v) {
		cout << p;
	}
}
int binarytodecimal(int n){
    int cnt = 0;
    int ans = 0;
    while(n){
        if(n%10){
            ans+=pow(2,cnt);
        }
        n=n/10;
        cnt++;
    }
    cout<<ans<<endl;
}
void dectobinary2(int n) {
	int cnt = 0;
	int ans = 0;
	while (n) {
		int rem = n % 2;
		n = n / 2;
		int c = pow(10, cnt);
		ans += c * rem;
		cnt++;
	}
	cout << ans << endl;
}
int octaltodecimal(int n){
    int base = 1;
    int dec_value = 0;
    while(n){
        int last_digit = n%10;
        dec_value += base*last_digit;
        base = base*8;
        n = n/10;
    }
    cout<<dec_value<<endl;
}
int DecimalToBase(int n, int b)
{
    int rslt=0, digitPos=1;
    while (n)
    {
        rslt += (n%b)*digitPos;
        n /= b;
        digitPos *= 10;
    }
    return rslt;
}
int main() {
	int t;
	//dectobinary1(4);
	dectobinary2(10);
 
}
 
