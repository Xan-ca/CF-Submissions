#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n),res(n);
    ll maxi=0,maxi_pos=0;
    for(ll i=0;i<n;i++)cin>>v[i];
    	v[0]+=k;
    for(ll i=0;i<n;i++){
    	if(v[i]>maxi){
    		maxi_pos=i;
    		maxi=v[i];
    	}
    }
    ll ud=0;
    for(ll i=0;i<n;i++){
    	if(i>maxi_pos){
    		res[i]=i;
    		continue;
    	}
    	if(i==maxi_pos){
    		res[i]=0;
    		continue;
    	}
    	if(v[i]+ud>=maxi){
    		res[i]=i;
    	}else{
    		res[i]=i+1;
    	}
    	ud+=v[i];
    }
    for(ll i=0;i<n;i++)cout<<res[i]<<" " ;
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