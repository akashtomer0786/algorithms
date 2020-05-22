class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        unordered_set<int>istravel(days.begin(),days.end());
        int dp[366];
        dp[0]=0;
        for(int i=1;i<=365;i++){
            if(istravel.count(i)==0)dp[i]=dp[i-1];
            else {
                cout<<i<<endl;
    
                 ///what price i am going to pay today because ticket is ending today
                ///for today i need to pay based on my previous journey
                int one = dp[i-1]+cost[0];
                int seven = dp[max(0,i-7)]+cost[1];
                int thirty = dp[max(0,i-30)]+cost[2];
                dp[i] = min(one,min(seven,thirty));
            }
           // cout<<dp[i]<<endl;
        }
        return dp[365];
    }
};
