#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n, base=1, pw=0,res=0;
    cin>>n;
    while(base*9<n){
    	base*=9;
    	pw++;
    }
    //cout<<base<<endl;
    while(n>0){
    	((n/base)>=4)?res+=pow(10,pw)*((n/base)+1):res+=pow(10,pw)*(n/base);
        n%=base;
    	while(n<base){
    		base/=9;
    		pw--;
    	}
    	
    	
    }
   
    cout<<res<<endl;

}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(ll i = 1; i <= t; i++) 
    {
       // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}