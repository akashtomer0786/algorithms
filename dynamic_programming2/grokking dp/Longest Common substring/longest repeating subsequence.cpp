#include<bits/stdc++.h>
using namespace std;
int lrslength(string x,int m,int n){
    if(m==0||n==0)return 0;
    if(x[m-1]==x[n-1]&&m!=n)
        return lrslength(x,m-1,n-1)+1;
    return max(lrslength(x,m,n-1),lrslength(x,m-1,n));
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<lrslength(s,s.size(),s.size());
	}
	return 0;
}
