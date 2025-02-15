#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
    	ll tem1,tem2;
         cin>>tem1>>tem2;
         adj[tem1].push_back(tem2);
         adj[tem2].push_back(tem1);
    }
    vector<ll>vis(n+1,-1);
    // for(auto it:vis)cout<<it<<" ";
    // 	cout<<endl;
    queue<ll>q;
    ll kp=1;
    for(ll i=1;i<=n;i++){
    	ll colour=1;
    	if(vis[i]==-1){
   		q.push(i);
   		while(!q.empty()){
   			ll tp=q.front();
   			q.pop();
   			if(vis[tp]!=-1){
              if(vis[tp]==colour)continue;
              else {
              	cout<<-1<<endl;
              	return;
              }
   			}
   			vis[tp]=colour;
           if(tp==kp) colour=!colour;

   			  for(auto it:adj[tp]){

   					q.push(it);
   					kp=it;
   				
   			}
   		}
   		
   	} 
    }
    for(ll i=0;i<=n;i++)if(adj[i].size()==0)vis[i]=-1;
  
    vector<ll>arr1,arr2;
    for(ll i=1;i<=n;i++){
       if(vis[i]==1) arr1.push_back(i);
       if(vis[i]==0) arr2.push_back(i);
    }
    cout<<arr1.size()<<endl;
    for(auto it:arr1)cout<<it<<" ";
        cout<<endl;
    cout<<arr2.size()<<endl;
    for(auto it:arr2)cout<<it<<" ";
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