
#include<bits/stdc++.h>
using namespace std;
template <typename T>
T mymax(T x,T y){
    return (x>y)?x:y;
}
template <typename T>
void bubbleSort(T a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<j-i+1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
    int val = mymax<int>(3,7);
    cout<<val<<endl;

    int a[] = {1,2,3,4};
    bubbleSort<int>(a,5);
}
