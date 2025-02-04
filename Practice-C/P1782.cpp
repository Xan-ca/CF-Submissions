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
    ll maxn=0;
    for(ll i=0;i<n;i++){
      ll it;
        cin>>it;
        v[i]=it;
        maxn=max(it,maxn);
    }
    vector<ll>last(maxn+1,-1);
    vector<ll>taken(n+1,0);
    vector<ll>dp(n+1,0);
    for(ll i=0,dpi=1;i<n;i++,dpi++){

    if(last[v[i]]==-1){
    	//cout<<0<<" ";
       dp[dpi]=dp[dpi-1];

    }else{
    	//cout<<taken[last[v[i]]]<<" ";
    if(taken[last[v[i]]]==0)dp[dpi]=max(dp[dpi-1],i-last[v[i]]+1+dp[last[v[i]]+1]);
    if(taken[last[v[i]]]==1)dp[dpi]=max(dp[dpi-1],i-last[v[i]]  +dp[last[v[i]]+1]);
    if(dp[dpi]>dp[dpi-1]){
    taken[i]=1;
    }
    }
    last[v[i]]=i;
   // cout<<dp[dpi]<<" ";
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