#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pii;
 /*gp exists (a(r^n-1)/r-1)*/
ll const MOD = 1e9+7;
ll binexp(ll a, ll b){
    if(!b) return 1LL;
    ll ans = binexp(a, b/2);
    ans = ans * ans % MOD;
    if(b%2) return ans * a % MOD;
    return ans;
}
 
void solve_tc(){
 
    ll l, r, k;
    cin >> l >> r >> k;
 
    ll mx = 9 / k;
    cout << (binexp(mx+1, r) - binexp(mx+1, l) + MOD) % MOD << '\n';
 
}
 
int main(){
 
    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;
 
    while(tc--) solve_tc();
}
    
