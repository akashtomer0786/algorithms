#include<bits/stdc++.h>
using namespace std;
int matrixchainmultiplication(int dims[],int i,int j){
    if(i+1>=j){
        ///equal to because no cost for multiplying single matrices
        return 0;
    }
    int mincost=INT_MAX;
    for(int k=i+1;k<=j-1;k++){
        int cost=matrixchainmultiplication(dims,i,k);
        cost+=matrixchainmultiplication(dims,k,j);
        cost+=dims[i]*dims[j]*dims[k];
        mincost=min(cost,mincost);
    }
    return mincost;
}
int solve(int dims[],int n){
    /// Matrix M[i] has dimension dims[i-1] x dims[i] for i = 1..n
	/// input is 10 x 30 matrix, 30 x 5 matrix, 5 x 60 matrix
    int c[n+1][n+1];
    for(int i=1;i<=n;i++){
        c[i][i]=0;
        ///no cost for single matrix
    }
    /// c[i,j] = Minimum number of scalar multiplications (i.e., cost)
	/// needed to compute the matrix M[i]M[i+1]...M[j] = M[i..j]
	/// The cost is zero when multiplying one matrix
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            c[i][j]=INT_MAX;
            for(int k=i;j<n&&k<=j-1;k++){
                int cost = c[i][k]+c[k+1][j]+dims[i-1]*dims[k]*dims[j];
                c[i][j]=min(c[i][j],cost);
            }

        }
    }
    return c[1][n-1];

}
int main(){
    int t;
    cin>>t;
    while(t--){

    }
}
