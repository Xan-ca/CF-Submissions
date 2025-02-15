#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool colouring(ll curr,ll col,vector<vector<ll>> &adj,vector<ll> &vis){
 if(vis[curr]!=-1 && vis[curr]!=col)return false;
 if(vis[curr]!=-1 && vis[curr]==col)return true;
 vis[curr]=col;
 for(auto it:adj[curr]){
 if(!colouring(it,!col,adj,vis))return false;
 }
 return true;
 }
void Solve() 
{   ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<ll>vis(n+1,-1);
    for(ll i=0;i<m;i++){
    ll temp1,temp2;
    cin>>temp1>>temp2;
    adj[temp1].push_back(temp2);
    adj[temp2].push_back(temp1);
    }
    for(ll i=1;i<n;i++){
    	if(vis[i]==-1){
    	if(colouring(i,0,adj,vis)==false){
    	cout<<"IMPOSSIBLE"<<endl;
    	return;
    }
    }
    }
    
    for(ll i=1;i<=n;i++){
    ll it=vis[i];
    cout<<it+1<<" ";
    }
    cout<<endl;
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