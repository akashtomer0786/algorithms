class Solution {
public:
    int change(int amount, vector<int>& nums) {
        
        
        int n = nums.size();
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=nums.size();i++){           //initially i was using below layer but
                                                 //think it   uses last layer which is useful when coin                                                                 are not allowed to repeat 
            for(int j=1;j<=amount;j++){  //for(int j=amount;j>=nums.size();j--) 
              //here we require  current layer that is element in the ith row 
                if(j-nums[i-1]>=0)
                dp[j]+=dp[j-nums[i-1]];
                
            }
            cout<<endl;
        }
        return dp[amount];
    }
};

class Solution {
public:
    //top down
    int solve(vector<int>&nums,int amount,int i){
        if(amount==0)return 1;
        if(i<=0)return 0;
        if(amount<0)return 0;
        return solve(nums,amount-nums[i-1],i)+solve(nums,amount,i-1);
    }
    int change(int amount, vector<int>& nums) {
        int n = nums.size();
        return solve(nums,amount,int(nums.size()));
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=amount;i++)dp[0][i]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j]=dp[i-1][j];
                if(j-coins[i-1]>=0)dp[i][j]+=dp[i][j-coins[i-1]];
            }
        }
        return dp[n][amount];
    }
};
