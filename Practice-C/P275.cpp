#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 // partioining the array
void Solve() 
{
	ll n;
	cin>>n;
	vector<ll>v(n);
	ll res=0;
	for(auto &it:v)cin>>it;
	for(ll k=1;k<=n;k++){
		ll g=0;
		if(n%k==0){
			for(ll i=k;i<n;i++){
              g=__gcd<ll>(abs(v[i]-v[i-k]),g);

			}
			if(g!=1)res++;
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