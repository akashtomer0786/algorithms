class Solution{
public:
    int isLeap(int N){
        if(N%400==0)return 1;
        if(N%100==0)return 0;
        if(N%4==0)return 1;
        return 0;
    }
};
