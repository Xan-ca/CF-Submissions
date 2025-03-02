#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,res=0;

    cin>>n;
    vector<ll>v(n+1,0);
    vector<ll>indeg(n+1,0);
    for(ll i=1;i<=n;i++){
    cin>>v[i];
    }
    for(ll i=1;i<=n;i++){
    indeg[v[i]]+=1;
    }

    queue<ll>q,q2;
    for(ll i=1;i<=n;i++){
    if(indeg[i]==0){
    q.push(i);
    }
    }
    while(!q.empty()){
    while(!q.empty()){
    	ll it=q.front();
    if(--indeg[v[it]]==0){
      q2.push(v[it]);
    }
    q.pop();
    }
    while(!q2.empty()){
      q.push(q2.front());
      q2.pop();
    }
   res++;
   }
   cout<<res+2<<endl;
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