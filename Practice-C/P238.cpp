#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
   ll n,m;
   cin>>n>>m;
   vector<set<ll>>adj(n+1);
   vector<ll>fres(n+1,0),vis(n+1,0);
   vector<ll>v(n);
   for(ll i=0;i<m;i++){
   	ll k;
   	cin>>k;
   
   	for(ll i1=0;i1<k;i1++)cin>>v[i1];
   	ll i2=0;
   		for(ll i3=0;i3<k;i3++){
   		if(v[i3]!=v[i2]){
   			adj[v[i2]].insert(v[i3]);
   		    adj[v[i3]].insert(v[i2]);}
   	}
   
   }
   
   queue<ll>q;
   set<ll>st;
   for(ll i=1;i<=n;i++) {
   	ll res=0;
   	//cout<<vis[i]<<" ";
   	if(vis[i]==0){
   		
   		q.push(i);
   		res++;
   		while(!q.empty()){
   			ll tp=q.front();
   			
   			st.insert(tp);
   			q.pop();
   			if(vis[tp]==1)continue;
   			vis[tp]=1;
   			for(auto it:adj[tp]){

   				if (vis[it]==0){
   					q.push(it);
   					res++;
   				}
   			}
   		}
   		for(auto it:st){fres[it]=st.size();}
   			st.clear();
   	}
   	
   }
  
   //	cout<<endl;
   for(ll i=1;i<=n;i++)cout<<fres[i]<<" ";
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