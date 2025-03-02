#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),b(k);
    for(auto & it:a)cin>>it;
    for(auto & it:b)cin>>it;
    ll res=0;
    for(ll i=1;i<n;i++){
    res=__gcd<ll>(res,abs(a[i]-a[0]));
    }
    //cout<<res<<endl;
    for(ll i=0;i<k;i++){
    cout<<__gcd<ll>(res,a[0]+b[i])<<" ";
    }
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
    
    //cin >> t;
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