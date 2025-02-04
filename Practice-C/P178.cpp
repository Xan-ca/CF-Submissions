#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    vector<vector<ll>>last(n+1);
    vector<ll>dp(n+1,0);
    for(ll i=0,dpi=1;i<n;i++,dpi++){
    if(last[v[i]].size()==0){
       dp[dpi]=dp[dpi-1];

    }else{
    for(auto it:last[v[i]])dp[dpi]=max(dp[dpi],i-it+1+dp[it]);
    dp[dpi]=max(dp[dpi-1],dp[dpi]);
    }
    if(last[v[i]].size()<2)last[v[i]].push_back(i);
    else if(last[v[i]].size()==2){
    	last[v[i]].pop_back();
    	last[v[i]].push_back(i);
    }
    }
    cout<<dp[n]<<endl;
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