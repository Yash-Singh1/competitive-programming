const int MOD=1000000007;
    vector<int>prime;
    vector<int> p;
    void sieve(){
        for(int i=2;1LL*i*i<1000001;i++){
            if(!prime[i]){
                prime.push_back(i);
                for(int j=i*i;j<1000001;j+=i){
                    prime[j]=1;
                }
            }
        }
    }
    int seg(int L,int R){
        if(L==1)L++;
        int max=(R-L+1),res=1;
        vector<bool> arr(max,false);
        for(auto &x:p){
            if(1LL*x*x<=R){
                long long i=(L/x)*x;
                if(i<L)i+=x;
                for(;i<=R;i+=x){
                    if(i!=x)arr[i-L]=1;
                }
            }
        }
        for(int i=L;i<=R;i++)if(!arr[i-L])res=1LL*res*i%MOD;
        return res;
    }
    long long primeProduct(long long L, long long R){
        sieve();
        return seg(L,R);
    }