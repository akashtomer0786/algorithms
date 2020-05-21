class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int dp[n+1];
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            int premax=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&dp[j]>premax){
                    premax=dp[j];
                }
            }
            dp[i]=1+premax;
            ans=max(ans,dp[i]);
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int bs(int temp[],int i,int j,int x){
        while(i<j){
            int mid = (i+j)>>1;
            if(temp[mid]<x)i=mid+1;
            else j=mid;
        }
        return i;
    }
    int lengthOfLIS(vector<int>& nums) {
        int sz=0;
        //suppose we have the sequence 1 3 4 8 and we want to put 5 here then we will search
        //the next greater element put 5 there so that when any element like 6 comes we can extend
        //our length but this was not possible if 8 was not replaced 
        int temp[nums.size()];
        for(int x : nums){
            int mid = bs(temp,0,sz,x);
            temp[mid]=x;
            if(mid==sz)sz++;
        }
        return sz;
    }
};
int LIS(int arr[],int i,int n,int prev){
    if(i==n)return 0;

    int excl = LIS(arr,i+1,n,prev);
    int incl=0;
    if(arr[i]>prev)
    int incl = LIS(arr,i+1,n,arr[i]);
    return max(incl,excl);
}
void findLIS(int arr[],int n){
    vector<int>LIS[n];
    LIS[0].push_back(arr[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]&&LIS[j].size()>LIS[i].size())
                LIS[i] = LIS[j];
        }
        LIS[i].push_back(arr[i]);
    }
}
