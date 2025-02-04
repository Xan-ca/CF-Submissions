#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    ll res=accumulate(a.begin(),a.end(),0ll);
   
    for(ll i=0;i<n-1;i++){
    	ll temp=max(a[n-i-1]-a[0],a[0]-a[n-i-1]);
    	res=max(temp,res);
    	for(ll j=0;j<n-i-1;j++){
    		a[j]=a[j+1]-a[j];
    	}
    	for(ll j=n-i-1;j<n;j++)a[j]=0;
    	res=max(accumulate(a.begin(),a.end(),0ll),res);
    	
          
          
    	
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