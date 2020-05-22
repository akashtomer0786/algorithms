class Solution {
public:
    /**
     * @param N: an integer
     * @return: return an integer
     */
    int maxA(int N) {
        // write your code here
        int dp[N+1];
        ///dp[i] represent the max number of A that can be printed using number i
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=N;i++){
            ////three steps you require for select copy and paste 
            ///check before last three steps
            dp[i]=i;
            for(int j=i-3;j>=1;j--){
                int howmanytimesvcanyoutype = i-j-1;
                dp[i]=max(dp[i],dp[j]*howmanytimesvcanyoutype);
            }
        }
        return dp[N];
    }
};
