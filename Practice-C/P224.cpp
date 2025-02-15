#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<ll>cost(n+1,-1),has(k);
    vector<ll>dpcost(n+1,-1);
    vector<vector<ll>>recipe(n+1);
    for(ll i=1;i<=n;i++)cin>>cost[i];
    for(auto &it:has)cin>>it;
    for(ll i=1;i<=n;i++){
    ll m;
    cin>>m;
    for(ll j=0;j<m;j++){
    ll temp;
    cin>>temp;
    recipe[i].push_back(temp);
    }
    }
    for(auto it:has){
      dpcost[it]=0;
      cost[it]=0;
    }
    function<void(ll)> updatedp=[&](ll i){if(dpcost[i]!=-1)return;
    ll udcs=INF;
    if(recipe[i].size()!=0){
        udcs=0;
      for(auto it:recipe[i]){
      if(dpcost[it]!=-1){
      
      udcs+=dpcost[it];

      }
      else {
      updatedp(it);
      udcs+=dpcost[it];
      }
      }
    }
    ll dcs=cost[i];
    
    dpcost[i]=min(udcs,dcs);
    return;
};
    for(ll i=1;i<=n;i++){
    updatedp(i);
    }
    for(ll i=1;i<=n;i++)cout<<dpcost[i]<<" ";
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