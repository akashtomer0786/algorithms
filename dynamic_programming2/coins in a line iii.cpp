///https://leetcode.com/problems/predict-the-winner/
///dp[i][j] represents the score of player in action more than opponent (second player) will get from i to j 
///First in action whoever moves first 
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for(int i=0;i<n;i++)dp[i][i]=nums[i];
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j = i+len-1;
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};


// F(i, j)  represents the maximum value the user can collect from 
//          i'th coin to j'th coin.

//     F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
//                    Vj + min(F(i+1, j-1), F(i, j-2) )) 
// Base Cases
//     F(i, j)  = Vi           If j == i
//     F(i, j)  = max(Vi, Vj)  If j == i+1

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n+3][n+3];
        memset(dp,0,sizeof(dp));
        int sum=0;
        for(int i=0;i<n;i++)dp[i][i]=nums[i];
        for(int i=0;i<n;i++)sum+=nums[i];
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                dp[i][j]=max(nums[i]+min(dp[i+2][j],dp[i+1][j-1]),nums[j]+min(dp[i+1][j-1],j-2>=0?dp[i][j-2]:0));
            }
        }
        return sum-dp[0][n-1]<=dp[0][n-1];
    }
};

class Solution {
public:
    int solve(int a,int b,vector<int>&arr){
        if(b-a<0)return 0;
        if(b-a==1)return arr.size()%2==0?max(arr[a],arr[b]):min(arr[a],arr[b]);
        int left = arr[a]+min(solve(a+2,b,arr),solve(a+1,b-1,arr));
        int right =arr[b]+min(solve(a+1,b-1,arr),solve(a,b-2,arr));
        return max(left,right);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i : nums)sum+=i;
        int first = solve(0,n-1,nums);
        int second = sum-first;
        return first>=second;
    }
};
