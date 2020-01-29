#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    
	    char s[1005];
	    cin>>s;
	    int len = strlen(s);
	    int acount=0;
	    int bcount=0;
	    int ccount=0;
	    for(int i=0;i<len;i++){
	        if(s[i]=='a'){
	            acount=1+2*acount;
	        }else if(s[i]=='b'){
	            bcount=acount+2*bcount;
	        }else{
	            ccount=bcount+2*ccount;
	        }
	    }
	    cout<<ccount<<endl;
	    
	}
	return 0;
}
