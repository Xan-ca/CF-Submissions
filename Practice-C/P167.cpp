#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 #define ll long long
 template<class T, class U>
 // T -> node, U->update.
 struct Lsegtree{
     vector<T>st;
     vector<U>lazy;
     ll n;
     T identity_element;
     U identity_update;
     Lsegtree(ll n, T identity_element, U identity_update)
     {
         this->n = n;
         this->identity_element = identity_element;
         this->identity_update = identity_update;
         st.assign(4*n,identity_element);
         lazy.assign(4*n, identity_update);
     }
     T combine(T l, T r)
     {
         // change this function as required.
         T ans = max(l , r);
         return ans;
     }
     void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
     {
         if(tl == tr)
         {
             st[v] = a[tl];
             return;
         }
         ll tm = (tl + tr)>>1;
         buildUtil(2*v + 1, tl, tm,a);
         buildUtil(2*v + 2,tm+1,tr,a);
         st[v] = combine(st[2*v + 1], st[2*v + 2]);
     }
     // change the following 2 functions, and you're more or less done.
     T apply(T curr, U upd, ll tl, ll tr)
     {
         T ans = upd;
         return ans;
     }
     U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
     {
         U ans = old_upd;
         ans=new_upd;
         return ans;
     }  
     void push_down(ll v, ll tl, ll tr)
     {
         if(lazy[v] == identity_update)return;
         st[v] = apply(st[v], lazy[v], tl, tr);
         if(2*v + 2 < 4*n)
         {
             ll tm = (tl + tr)>>1;
             lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
             lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
         }
         lazy[v] = identity_update;
     }
     T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
     {
         push_down(v,tl,tr);
         if(l > r)return identity_element;
         if(tr < l or tl > r)
         {
             return identity_element;
         }
         if(l <= tl and r >= tr)
         {
             return st[v];
         }
         ll tm = (tl + tr)>>1;
         return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
     }
  
     void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
     {
         push_down(v,tl,tr); 
         if(tr < l or tl > r)return;
         if(tl >=l and tr <=r)
         {
             lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
             push_down(v,tl,tr);
         }
         else
         {
             ll tm = (tl + tr)>>1;
             updateUtil(2*v+1,tl,tm,l,r,upd);
             updateUtil(2*v+2,tm+1,tr,l,r,upd);
             st[v] = combine(st[2*v + 1], st[2*v+2]);
         }
     }
 
 
 
     void build(vector<T>a)
     {
         assert(a.size() == n);
         buildUtil(0,0,n-1,a);
     }
     T query(ll l, ll r)
     {
         return queryUtil(0,0,n-1,l,r);
     }
     void update(ll l,ll r, U upd)
     {
         updateUtil(0,0,n-1,l,r,upd);
     }
 };
void Solve() 
{
    ll n;
    cin>>n;
    vector<vector<ll>>adj(n+1);
    vector<ll>edges(n+1,0);
   
    for(ll i=0;i<n-1;i++){
    ll a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    }
    edges[0]=0;
   for(ll i=1;i<n+1;i++){
   	edges[i]=adj[i].size();
   }
  
    Lsegtree<ll,ll>s(n+1,-1,-1);
    ll res=0;
    s.build(edges);
     
    for(ll i=1;i<=n;i++){
    	s.update(i,i,0);
    	for(ll j=0;j<adj[i].size();j++){
    		s.update(adj[i][j],adj[i][j],edges[adj[i][j]]-1);
    	}
    	ll temp=edges[i]+s.query(0,n)-1;
    	if(s.query(0,n)!=0)res=max(res,temp);
    	
    	s.update(i,i,edges[i]);
    	for(ll j=0;j<adj[i].size();j++){
    		s.update(adj[i][j],adj[i][j],edges[adj[i][j]]);
    	}
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