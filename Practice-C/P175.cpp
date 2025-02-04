#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,d,res=0;
    map<ll,ll>mp;
    cin>>n;
    vector<int>v(n);
    vector<int>vcpy;
    for(auto &it:v)cin>>it;
    	for(auto it:v)vcpy.push_back(it);
    sort(v.begin(),v.end()); 
     for(ll i=0;i<n;i++){
     	mp[v[i]]=i+1;
       res+=v[i]+1;    
   }
   mp[0]=0;
   //for(auto it:mp)cout<<it.second<<endl;
   map<ll,ll>resmp;
   ll x=0;
   for(ll i=0;i<n;i++){

   	res+=(mp[x])*(v[i]-x);
   	res-=(n-mp[x])*(v[i]-x);
    //cout<<v[i]<<":"<<res<<" ";
    resmp[v[i]]=res;
    x=v[i];
   }
   for(ll i=0;i<n;i++){
   	cout<<resmp[vcpy[i]]<<" ";
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