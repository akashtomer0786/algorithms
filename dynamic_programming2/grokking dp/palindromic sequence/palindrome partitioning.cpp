class Solution {
public:
    void recurpartitions(string &s,vector<string>&path,vector<vector<string>>&res,int start){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(ispalindrome(s,start,i)){
                path.push_back(s.substr(start,i-start+1));
                recurpartitions(s,path,res,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>res;
        recurpartitions(s,path,res,0);
        return res;
    }
private:
    bool ispalindrome(string s,int i,int j){
        int left=i;
        int right=j;
        while(left<right){
            if(s[left]!=s[right])return false;
            left++,right--;
        }
        return true;
    }
    
};
