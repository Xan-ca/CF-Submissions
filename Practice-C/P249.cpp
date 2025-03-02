#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
  /*1. we know that a overtake is useless no mening no change if it gets overtaken by the one it over took
  hence if we make the cars at back over take all the cars at front once then we get the revrse order 
  now if we just overtake in way to get the original order essentially we are doing useless overtakes and the use ful one at the start
  preserve their contribution to ordering and use less one loss their contribution hence giving largest sequence */
 typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n),taken(n+1,0);
    vector<pair<ll,ll>>res;
    for(auto &it:v)cin>>it;
    for(ll i=1;i<=n;i++){
    for(ll j=i+1;j<=n;j++){
    //cout<<j<<" "<<i<<endl;
    res.push_back({j,i});
    }
    }
   // reverse(v.begin(),v.end());
    for(ll i=0;i<n;i++){
    taken[v[i]]=1;
        for(ll j=v[i]+1;j<=n;j++){
           if(!taken[j]){
           //cout<<v[i]<<" "<<j<<endl;
           res.push_back({v[i],j});
           }
        }
    }
    cout<<res.size()<<endl;
    for(auto it:res)cout<<it.first<<" "<<it.second<<endl;
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
   // cin >> t;
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