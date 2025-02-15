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
   vector<ll>mp(n+1,0);
   for(auto &it:v)cin>>it;
   sort(v.begin(),v.end());
   for(ll i=0;i<n;i++){
   	mp[v[i]]++;
   }
   for(ll j=0;j<n;j++){
   for(ll i=1;i<n;i++){
   	
   		if(mp[i]>2){
   			mp[i+1]++;
   			mp[i]--;
   		}
   	
   }
    
}
   for(ll i=1;i<=n;i++){
   	if(mp[i]%2!=0){
   		cout<<"No"<<endl;
   		return;
        
   	}
   }
   cout<<"Yes"<<endl; 
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