#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>grid(n,vector<ll>(m));
    vector<ll>sums(n,0);
    vector<ll>ressum(n,0);
    for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
    	ll temp;
        cin>>temp;
        if(j>0)grid[i][j]=temp+grid[i][j-1];
        else grid[i][j]=temp;
        if(j==m-1)sums[i]+=grid[i][j];
        ressum[i]+=grid[i][j];
    }
}
    // for(auto it:sums)cout<<it<<" ";
    // 	cout<<endl;
    sort(sums.rbegin(),sums.rend());
    ll res=0;
    for(ll i=n-1,j=0;i>=0;i--,j++){
    	res+=i*m*sums[j];
    	res+=ressum[j];
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