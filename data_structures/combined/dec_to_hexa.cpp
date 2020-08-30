class Solution {
public:
    string toHex(int num1) {
        if(num1==0)return "0";
        string hex = "0123456789abcdef";
        string ans;
        unsigned int num = num1;
        while(num){
            ans = hex[num%16]+ans;
            num=num/16;
        }
        return ans;
    }
};
