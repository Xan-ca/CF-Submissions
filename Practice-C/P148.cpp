#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>res;
    if(n%2==1){
    	ll x=(n-1)/2;

    for(ll i=1;i<n;i++){
    	ll k=0;
    for(ll j=i+1;j<=n;j++){
       // cout<<k;
         if(k<x){
         	res.push_back(1);
         	k++;
         }else{
         	res.push_back(-1);
         }
    }
    }

    }else{
        ll x=(n-1)/2;
      for(ll i=1;i<n;i++){
        ll k=0;
    for(ll j=i+1;j<=n;j++){
       if(j==i+1 && i%2==1){
        res.push_back(0);
        continue;
       }
         if(k<x){
            res.push_back(1);
            k++;
         }else{
            res.push_back(-1);
         }
    }
    }  
    }
    for(auto it:res)cout<<it<<" ";
        cout<<endl;
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
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}