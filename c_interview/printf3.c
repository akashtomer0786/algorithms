#include<bits/stdc++.h>
using namespace std;
int main(){
    char c = 255;
    c = c + 10;
    ///ans total chars can be 256 
    ///so ans will be (255+10)%256 = 9
    printf("%d",c);
    return 0;
}
