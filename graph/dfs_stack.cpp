#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>g;
    stack<int>st;
    vector<int>visited(10,false);

    st.push(0);
    visited[0]=true;

    while(st.size()){
        auto cur =  st.top();
        cout<<cur<<endl;
        for(auto next : g[cur]){
            if(!visited[next]){
                visited[next]=true;
                st.push(next);
            }
        }
    }
}
