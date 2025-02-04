#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    ll k=__gcd(a,b);
    for(ll i=0;i<n;i++){
      v[i]=v[i]%k;
    }
    sort(v.begin(),v.end());
    ll mx=v[n-1];
    ll res=INF;
    for(ll i=0;i<n;i++){
       res=min(mx-v[i],res);
      mx=v[i]+k;
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
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}