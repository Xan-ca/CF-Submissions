#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 void dfs(ll n,ll i,vector<vector<ll>>&adj,vector<ll>&vis){
    vis[i]=n;
    for(auto it:adj[i]){
    	if(vis[it]==0){
    		dfs(n,it,adj,vis);
    	}
    }
    return ;

 }
void Solve() 
{
    ll n,dest;
    cin>>n>>dest;
     vector<ll>a(n+1,0);
     vector<vector<ll>>adj(n+1);
     vector<ll>mn(n+1,INF),vis(n+1,0);
     mn[0]=0;
     for(ll i=1;i<=n;i++)cin>>a[i];
     
     for(ll i=1;i<=dest;i++){
     	ll temp1,temp2;
     	cin>>temp1>>temp2;
     	adj[temp1].push_back(temp2);
     	adj[temp2].push_back(temp1);
     }
    
     for(ll i=1;i<=n;i++){
     	if(vis[i]==0){
     		dfs(i,i,adj,vis);
     	}else mn[i]=0;
     }
     for(ll i=1;i<=n;i++){
     	mn[vis[i]]=min(a[i],mn[vis[i]]);
     }

     cout<<accumulate(mn.begin(),mn.end(),0ll)<<endl;
     return;


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