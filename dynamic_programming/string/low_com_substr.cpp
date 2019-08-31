#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<functional>
#include<string.h>
using namespace std;
string a, b;
int dp[300][300];
int lcsubstr(int alen, int blen, int s) {
	for (int i = 0; i < alen; i++) {
		dp[0][i] = 0;
	}
	for (int j = 0; j < blen; j++) {
		dp[j][0] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= blen; i++) {
		for (int j = 1; j <= alen; j++) {
			if (b[i - 1] == a[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
			else dp[i][j] = 0;
		}
	}
	return ans;
	//int ans = 0;

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		memset(dp, -1, sizeof(dp));
		cin >> x >> y;
		cin >> a >> b;
		cout << lcsubstr(a.length(), b.length(), 0) << endl;
	}
}
