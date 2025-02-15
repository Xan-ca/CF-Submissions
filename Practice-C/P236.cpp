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
   for(auto &it:v)cin>>it;
   	for(ll i=0;i<n-1;i++){
   		if(v[i]>v[i+1]){
   			cout<<"no"<<endl;
   			return;
   		}else{
   			ll k=min(v[i],v[i+1]);
             v[i]-=k;
             v[i+1]-=k;
   		}
   	}
   	cout<<"yes"<<endl;
   
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