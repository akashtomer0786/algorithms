//geeksforgeeks->https://p...content-available-to-author-only...s.org/problems/permutations-of-a-given-string/0
#include<bits/stdc++.h>
using namespace std;
string a = "ABC";
void permute(int l,int r){
    if(l==r)
        cout<<a<<endl;
    for(int i=l;i<=r;i++){
     //   cout<<a<<endl;
        swap(a[l],a[i]);
 
        permute(l+1,r);
        swap(a[l],a[i]);
    }
}
using namespace std;
int main(){
    permute(0,2);
}
