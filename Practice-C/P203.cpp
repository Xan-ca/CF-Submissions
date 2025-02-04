#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    vector<ll>res;
    multiset<ll>mst;
    for(ll i=0;i<n;i++){
    cin>>v[i];
    mst.insert(v[i]);
    
    }
    sort(v.rbegin(),v.rend());
    ll cur,mx,mxpos;
    cur=v[0];
    res.push_back(cur);
    mst.erase(mst.find(cur));
    for(ll j=1;j<=32;j++){
    mx=cur;
     for(ll i=j;i<n;i++){
    
     if(max(cur,cur|v[i])>mx){
       mxpos=i;
       mx=max(cur,cur|v[i]);
     }
     }
     if(mx==cur)break;
     else cur=mx;
     res.push_back(v[mxpos]);
     mst.erase(mst.find(v[mxpos]));
    }
    for(auto it:mst)res.push_back(it);
    	for (auto it:res)cout<<it<<" ";
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