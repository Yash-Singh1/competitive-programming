// (a^b)%m;
long long binpow(long long a,long long b,long long m){
    a=a%m;
    long long res=1;
    while(b>0){
        if(b%2==1){
            res=res*a%m;
        }
        a=a*a%m;
        b=b/2;
    }
    return res;
}