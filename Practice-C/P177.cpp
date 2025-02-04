#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{  ll n;
cin>>n;
   map<ll,ll>a,b,c,d;
   vector<pair<ll,ll>>v;
   for(ll i=0;i<n;i++){
    ll temp1,temp2;
    cin>>temp1>>temp2;
    v.push_back(make_pair(temp1,temp2));
    a[temp1]++;
    b[temp2]++;
    c[temp1-temp2]++;
    d[temp1+temp2]++;
   } 
   ll res=0;
   for(ll i=0;i<n;i++){
   res+=a[v[i].first]+b[v[i].second]+c[v[i].first-v[i].second]+d[v[i].first+v[i].second]-4;
   }
   cout<<res<<endl;
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
