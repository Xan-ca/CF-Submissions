#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 template<typename T>class DSU{
    T MAXN=200000;
   
    T anc[200001];
   public :
    void init() {
        for (T i = 0; i <=MAXN; i++) {
            anc[i] = i;
        }
        return;
    }

    T find(T i) {
        return anc[i] == i ? i : anc[i] = find(anc[i]);
    }

    bool merge(T a, T b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        anc[a] = b;
        return true;
    }
};
void Solve() 
{
  // cout<<"hi";
   DSU<ll>dsuF;
   DSU<ll>dsuG;
   vector<pair<ll,ll>>F,G;

  map<pair<ll,ll>,int>mp;
   dsuF.init();
   dsuG.init();
   ll n,m1,m2;
   cin>>n>>m1>>m2;
  // cout<<"hi";
   for(ll i=0;i<m1;i++){
    ll a,b;
    cin>>a>>b;
    dsuF.merge(a,b);

    F.push_back(make_pair(a,b));
    mp[make_pair(a,b)]=1;
   } 
   for(ll i=0;i<m2;i++){
    ll a,b;
    cin>>a>>b;
    dsuG.merge(a,b);
    
    G.push_back(make_pair(a,b));
   } 
   //cout<<"hi";
   ll opers=0;
   for(ll i=0;i<F.size();i++){
    if(dsuG.find(F[i].first)!=dsuG.find(F[i].second)){
        opers++;
    }
   }
   for(ll i=0;i<G.size();i++){
    if(mp.find(G[i])==mp.end() && mp.find(make_pair(G[i].second,G[i].first))==mp.end()){
        opers++;
    }
   }
   //cout<<"hi";
   cout<<opers<<endl;


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