#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   string a,b,c;
   cin>>a>>b>>c;
   ll n=a.size();
   ll m=b.size();
   ll k;
   vector<vector<ll>>dp(n+2,vector<ll>(m+2,1e9));
   dp[0][0]=0;
   for( ll i=0;i<=n;i++){
   	for(ll j=0;j<=m;j++){
   		k=i+j;
   		ll cost=0;
   		if(i<n)cost=(a[i]!=c[k]);
   		dp[i+1][j]=min(dp[i][j]+cost,dp[i+1][j]);
   		if(j<m)cost=(b[j]!=c[k]);
   		dp[i][j+1]=min(dp[i][j]+cost,dp[i][j+1]);
   	}
   }
   cout<<dp[n][m]<<endl;
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