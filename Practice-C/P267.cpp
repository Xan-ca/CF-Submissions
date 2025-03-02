#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{   ll n;
   cin>>n;
   vector<pair<ll,ll>>v(n);
   map<ll,ll>mp1,mp2;
   for(ll i=0;i<n;i++){
    cin>>v[i].first;
   }
   for(ll i=0;i<n;i++){
    cin>>v[i].second;
   }
   for(ll i=0;i<n;i++){
    mp1[v[i].first]=v[i].second;
    mp2[v[i].second]=v[i].first;
   }
   for(auto it)
    ll acutan=a[n-1],bcutan=mp1[a[n-1]];
   ll idxab=get_inedx(b,bcutan);
   ll idxaa=get_index(a,acutan);
   while(){
    for(ll i=idxab;i<n;i++){
       acutan=min(acutan,mp2[b[i]]);
   }
   ll idxaa=get_index(a,acutan);
   for(ll i= idxaa;i<)

   }
   

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