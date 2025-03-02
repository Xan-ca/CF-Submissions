#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 

     
    void Solve() 
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(auto &it:a)cin>>it;
        for(ll i=0;i<n;i++){
        	if( i+a[i]<n  && dp[i-1+1]  ==true)dp[i+a[i]+1]=true;
        	if( i-a[i]>=0 && dp[i+1-a[i]-1]==true)dp[i+1]=true;
        }
        cout<<((dp[n])?"YES":"NO")<<endl;
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