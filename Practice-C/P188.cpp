#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool does(vector<ll>&v ,ll remv,ll n){
	ll start=1+remv,end=n-remv;
	for(ll i=0;i<n;i++){
	if(v[i]==start){
		if(start==end){
			return true;
		}
	start++;
	}
	}
	return false;
	
}
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    	
    ll lo=0,hi=n/2;
    while(hi-lo>1){
     ll mid=(lo+hi)/2;
    if(does(v,mid,n)){
       hi=mid;
    }else{
       lo=mid;
    }
    }
    if(does(v,lo,n)){
    	cout<<lo<<endl;
    	
    }else cout<<hi<<endl;
    
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