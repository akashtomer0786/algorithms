class Solution {
public:
    int cntpalindromes(string s,int i,int j){
        int cnt=0;
        while(i>=0 && j<s.size()&&s[i]==s[j])cnt++,i--,j++;
        return cnt;
    }
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            int odd = cntpalindromes(s,i,i);
            int even = cntpalindromes(s,i,i+1);
            res+=odd+even;
        }
        return res;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int res=n;   //string of length 1
        if(n<=1)return res;
        bool dp[n][n];
        for(int i=0;i<n;i++)dp[i][i]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j]=((s[i]==s[j])&&((j-i+1<=3)||dp[i+1][j-1]));
                if(dp[i][j])res++;
            }
        }
        return res;                  
    }
};
