#include<bits/stdc++.h>

using namespace std;
unordered_map<string,bool>mep;
bool part(vector<int>&nums,int i,int sum){
    string s = to_string(sum)+" "+to_string(i);
    if(mep.count(s))return mep[s];
    if(sum==0)return true;
    if(sum<0||i==nums.size())return false;
    
    return mep[s]=part(nums,i+1,sum-nums[i])||part(nums,i+1,sum);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    int sum=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    if(sum&1){
	        cout<<"NO"<<endl;
	        continue;
	    }
	    if(part(a,0,sum/2)){
	        cout<<"YES";
	    }else{
	        cout<<"NO";
	    }
	    cout<<endl;
	}
	return 0;
}
