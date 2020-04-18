binpow(int a,int b){
    int res=1;
    while(b){
        if(b&1){  ///it seems to be that we are checking of odd but here we checking the lsb bit
            res=res*a;
        }
        a=a*a;
        b=b/2; ///right shift
    }
    return res;
}
