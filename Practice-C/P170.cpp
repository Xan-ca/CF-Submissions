#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,res=0;
    cin>>n;
    vector<ll>v(n);

    for(auto &it:v)cin>>it;
    	if(v.size()==1){
    		if(v[0]>=0){
    			cout<<v[0]<<endl;
    			return;
    		}else{
    			cout<<0<<endl;
    			return;
    		}
    	}
    for (auto it:v)if(it>0)res+=it;
    if(v[0]>=0){
      res=res;
    }else{
    if(v[1]>=0){
      if(v[1]+v[0]>0){
      res+=v[0];
      }else{
      res-=v[1];
      }
    }else{
      res=res;
    }
    }
    cout<<res<<endl;
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