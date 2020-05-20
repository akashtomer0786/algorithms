//min cost climbing stairs
class Solution {
public:
    vector<int>dp;
    int helper(vector<int>&cost,int n){
        if(dp[n]!=-1)return dp[n];
        if(n==2)return cost[n-1];
        if(n==1)return cost[0];
        return dp[n]=min(helper(cost,n-1),helper(cost,n-2))+cost[n-1];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        dp.resize(n+1,-1);
        return min(helper(cost,n-1),helper(cost,n-2)+cost[n-1]);
    }
    
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[1]=cost[0];
        dp[2]=cost[1];
        dp[0]=0;
        
        for(int i=3;i<=cost.size();i++){
            dp[i]=cost[i-1]+min(dp[i-1],dp[i-2]);
        }
         return min(dp[n],dp[n-1]);
        
    }
};
