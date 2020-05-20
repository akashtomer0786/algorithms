class Solution {
public:
    int maxlen=0;
    int start;
    void ispalindrome(string s,int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            if(maxlen<j-i+1){
                maxlen=j-i+1;
                start=i;
            }
            i--,j++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1)return s;
        for(int i=0;i<s.size();i++){
            ispalindrome(s,i,i);
            ispalindrome(s,i,i+1);
        }
        return s.substr(start,maxlen);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1)return s;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int maxlen=1;
        int start=0;
        for(int i=0;i<n;i++)dp[i][i]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i==1)dp[i][j]=true;
                    else dp[i][j]=dp[i+1][j-1];
                } 
                if(j-i+1>maxlen && dp[i][j]){
                    maxlen=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,maxlen);
        
    }
};
