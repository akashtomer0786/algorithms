class Solution {
public:
    int k(vector<int>a,int l,int r){
    if(l>r){
        return INT_MIN;
    }
    int m=(l+r)/2;
    int leftmax = k(a,l,m-1);
    int rightmax = k(a,m+1,r);

    int curlmax=0;
    int currmax=0;
    for(int i=m-1,sum=0;i>=l;i--){
        sum+=a[i];
        curlmax=max(sum,curlmax);
    }
    for(int i=m+1,sum=0;i<=r;i++){
        sum+=a[i];
        currmax=max(sum,currmax);
    }
    return max(max(leftmax,rightmax),curlmax+currmax+a[m]);
}
    int maxSubArray(vector<int>& nums) {
        return k(nums,0,nums.size()-1);
    }
};
