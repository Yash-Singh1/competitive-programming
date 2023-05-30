#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
void solve(){
    ll x,y,c,t; cin >> x >> y >> c >> t; 
    if(c - x == t) {
        cout << "YES\n" ; 
        return; 
    }
    if(c - y == t) {
        cout << "YES\n" ; 
        return; 
    }
    if(c - x - y == t) {
        cout << "YES\n" ; 
        return; 
    }
    if(t % x == 0) {
        cout << "YES\n" ; 
        return; 
    }
    if(t % y == 0){
        cout << "YES\n"; 
        return; 
    }
    if((t-y) % x == 0 || ((t-x) % y == 0)) {
        cout << "YES\n" ; 
        return; 
    }
    cout << "No\n"; 
}
int main() {
    int t; cin >> t;
    while(t--) solve() ; 
}
