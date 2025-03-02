#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 bool dfscycle(ll prev,ll curr,vector<vector<ll>> &adj,vector<ll> &pathvis,vector<ll>&path){
 if(pathvis[curr]==1){
 return true;
 }
 pathvis[curr]=1;
 
 for(auto it:adj[curr]){
 path.push_back(it);
 if(it!=prev){
 if(dfscycle(curr,it,adj,pathvis,path))return true;
 }
 path.pop_back();
 }
 return false;
 }
void Solve() 
{
   ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<ll>vis(n+1,0);
    vector<ll>path;

    for(ll i=0;i<m;i++){
    ll temp1,temp2;
    cin>>temp1>>temp2;
    adj[temp1].push_back(temp2);
    adj[temp2].push_back(temp1);
    } 
    for(ll i=1;i<=n;i++){
    if(vis[i]==0){
    	path.push_back(i);
    if(dfscycle(0,i,adj,vis,path)){
    	ll res=0;
   for(ll i=path.size()-1;i>=0;i--){
   	res++;
   	if(path[i]==path[path.size()-1] && i!=path.size()-1)break;
   }
   cout<<res<<endl;
   for(ll i=path.size()-1;i>=0;i--){
   	cout<<path[i]<<" ";
   	if(path[i]==path[path.size()-1] && i!=path.size()-1)break;
   }
    return;
    }
    path.pop_back();
    }
    path.clear();
    }
    cout<<"IMPOSSIBLE"<<endl;
    

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