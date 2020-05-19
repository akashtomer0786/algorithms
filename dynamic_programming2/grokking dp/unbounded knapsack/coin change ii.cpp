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
