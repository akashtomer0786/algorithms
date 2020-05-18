class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=values[n-1];
        dp[n-2]=values[n-2]+values[n-1];
        dp[n-3]=values[n-3]+values[n-2];
        int total = 0;
        for(int i : values)total+=i;
        ///dp[i]the max amount player 1 can pick from i to n-1
        for(int i=n-4;i>=0;i--){
            //P1 pick only i
              //then second can pick one or both 
              //also note one thing that opponenet wants to get us minimum coins
              //he will leave us in such a condition so that we will get 
              //minimum of remaining
            int val1 = values[i]+min(dp[i+2],dp[i+3]);
            //P1 pick i and i+1 
            //then second can pick further one or both
            int val2 = values[i] + values[i+1] + min(dp[i+3],dp[i+4]);
            
            dp[i]=max(val1,val2);
        }
        cout<<dp[0]<<endl;
        cout<<total<<endl;
        int secondplayervalue = total-dp[0];
        if(dp[0]>secondplayervalue)return true;
        return false;
    }
};
