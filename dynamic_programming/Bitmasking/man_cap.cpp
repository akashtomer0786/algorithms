#include<bits/stdc++.h>
 
using namespace std;
const int N = 101;
int n;
const int mod = 1000000007;
 int allmask;
///suppose there are 4 persons and so mask can be 1111 when all bit
/// are set
/// so highest set bit is 3rd here highest value will be 2^4-1 == (1<<4)-1
vector <int> caplist[N];
/// N -> is number of cap which is 100 here
 
///n is number of persons
///highest value for mask for n number of persons is allmask
///mask is here to check if person is already
///wearing a cap or not
int dp[1025][101];
int count_ways(int mask, int i) {
	if (mask == allmask)
		return 1;
	if (i > 100)
		return 0;
	///if we already solved this problem
	///with same mask and i value
	if (dp[mask][i] != -1)
		return dp[mask][i];
	long long int ways = count_ways(mask, i + 1);
	int size_1 = caplist[i].size();
	for (int j = 0; j < size_1; j++) {
		if (mask & (1 << caplist[i][j]))continue;
		else ways += count_ways(mask | (1 << caplist[i][j]), i + 1);
		ways %= mod;
	}
	return dp[mask][i] = ways;
}
 
int main() {
 
	cin >> n;
	allmask = (1 << n) - 1;
	string temp, str;
	int x;
	getline(cin, str);
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		stringstream ss(str);
 
		while (ss >> temp) {
			stringstream s;
			s << temp;
			s >> x;
			caplist[x].push_back(i);
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << count_ways(0, 1);
 
}
 
