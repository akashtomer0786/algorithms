#include<bits/stdc++.h>
using namespace std;

int josephus4(int n,int k){
    if(n==1)return 1;
    
    return (josephus4(n-1,k) + k-1)%n+1;
}

//unable to understand this below one
long long int josephus3(long long int n, long long int k)
{
    long long int sum = 0, i;

    // For finding out the removed
    // chairs in each iteration


    ///this equation is giving answer correct only in last iteration
    ///that is previous value
    for (i = 2; i <= n; i++){
        sum = (sum + k) % i;
        cout<<sum<<" ";
    }

    return sum + 1;
}
int josephus1(int n,int k){
    int killpos = k-1;
    vector<int>soldiers;

    for(int i=0;i<n;i++){
        soldiers.push_back(i+1);
    }

    while(soldiers.size()>1){

        soldiers.erase(soldiers.begin()+killpos);
        killpos = (killpos + k-1)%soldiers.size();
    }
    return soldiers[0];

}
int josephus2(int n,int k){
    deque<int>dq;
    for(int i=1;i<=n;i++)dq.push_back(i);
    int ans;
    while(dq.size()>1){
        for(int i=0;i<k-1;i++){
            int val = dq.front();
            dq.push_back(val);
            dq.pop_front();
        }
        ans=dq.front();
        dq.pop_front();
    }
    return ans;
}
int main(){
    int t;
    t=1;
    while(t){
        int n;
        cin>>n;
        int k;
        cin>>k;
        if(n==0&&k==0)break;
        cout<<josephus4(n,k)<<endl;

    }
}
